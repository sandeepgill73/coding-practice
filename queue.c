/*****************************************************************************
 * Includes                                                                  *
 *****************************************************************************/
#include "stdint.h"
#include "stdbool.h"
#include "queue.h"
#include <string.h>

/*****************************************************************************
 * Defined and Enumerated Constants                                          *
 *****************************************************************************/
#define HEAP_SIZE (sizeof(struct queue_t) + (MAX_QUEUE_ELEMENTS * sizeof(element_t)))

/*****************************************************************************
 * User Defined Datatypes                                                    *
 *****************************************************************************/
typedef void xdata * element_t;   /* the elements in the queue are void ptrs */

struct queue_t
{
    uint8_t count;                         /* count of elements in the queue */
    uint8_t front;                /* index to the front element in the queue */
    uint8_t rear;                  /* index to the rear element in the queue */
    uint8_t max_count;            /* maximum number of elements in the queue */
    element_t xdata * p_contents;        /* pointer to the array of elements */
};

/*****************************************************************************
 * Private Variables                                                         *
 *****************************************************************************/
static uint8_t xdata heap[HEAP_SIZE]; /* a heap of memory for all queues */
static uint8_t xdata * xdata p_free = &heap[0]; /* a ptr to the start of */
                                                /* free heap memory */

/*****************************************************************************
 * Public Functions                                                          *
 *****************************************************************************/

/*****************************************************************************

  NAME:        createQ

  SCOPE:       PUBLIC

  PARAMETERS:  len - length of queue in bytes

  RETURNS:     p_queue_t

  DESCRIPTION:

 *****************************************************************************/
p_queue_t createQ(uint8_t len)
{
    p_queue_t p_queue;
    uint16_t bytes_required;

    bytes_required = sizeof(struct queue_t) + (len * sizeof(element_t));

    if ((p_free + bytes_required <= &heap[0] + HEAP_SIZE) &&
        (len != 0))
    {
        /* there room for this new queue */
        p_queue = (p_queue_t) p_free;
        p_free += sizeof(struct queue_t);
        p_queue->p_contents = (element_t xdata *) p_free;
        p_free += len * sizeof(element_t);

        p_queue->max_count = len;

        flushQ(p_queue);              /* initialized queue indexes and count */
    }
    else
    {
        p_queue = NULL;                 /* out of memory return NULL pointer */
    }

    return p_queue;
}

/******************************************************************************

  NAME:        enqueue

  SCOPE:       public

  PARAMETERS:  q = pointer to a QUEUE structure
               val = element to be added to the queue

  RETURNS:     0 if the element could not be added, since the queue was full
               1 if the element was successfully added to the queue

  DESCRIPTION: This function adds elements to a queue.  It maintains the front
               and rear indexes into the queue's array together with an
               element count.

 *****************************************************************************/
bool enqueue(p_queue_t q, element_t element)
{
    bool status;

    if (q->count == q->max_count)
    {
        status = false;                                       /* queue is full */
    }
    else
    {
        q->p_contents[q->rear++] = element;
        q->count++;

        if (q->rear == q->max_count)
        {
            q->rear = 0;                        /* wrap rear index if needed */
        }

        status = true;
    }

    return status;
}

/*****************************************************************************

  NAME:        dequeue

  SCOPE:       public

  PARAMETERS:  q = pointer to a QUEUE structure

  RETURNS:     NULL pointer if the queue was empty and no element was returned
               otherwise a pointer from the queue

  DESCRIPTION: This function removes elements from a queue and returns them to
               the caller.  It maintains the front and rear indexes into the
               queue's array together with an element count.

 *****************************************************************************/
element_t dequeue(p_queue_t q)
{
    element_t element;

    if (q->count == 0)
    {
        element = NULL;
    }
    else
    {
        element = q->p_contents[q->front++];
        q->count--;

        // Wrap front index if we have gone over the maximum size
        if (q->front == q->max_count)
        {
            q->front = 0;
        }
    }

    return element;
}

/*****************************************************************************

  NAME:        flushQ

  SCOPE:       public

  PARAMETERS:  q = pointer to a QUEUE structure

  RETURNS:     void

  DESCRIPTION: This function resets the front and rear indexes together with
               the element count.  It doesn't actually clear any items in
               memory.

 *****************************************************************************/
void flushQ(p_queue_t q)
{
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}

/*****************************************************************************
 *
 * NAME:        frontQ
 *
 * SCOPE:       public
 *
 * PARAMETERS:  q = pointer to a QUEUE structure

 * RETURNS:     NULL pointer if the queue was empty and no element was returned
                otherwise a pointer from the queue
 *
 * DESCRIPTION: This function does not remove elements from a queue, it only
 *              returns the value of the first item in the queue.
 *
 *****************************************************************************/
element_t frontQ(p_queue_t q)
{
    element_t element;

    if (q->count == 0)
    {
        element = NULL;
    }
    else
    {
        element = q->p_contents[q->front];
    }

    return element;
}

