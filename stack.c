/*****************************************************************************
 * Includes                                                                  *
 *****************************************************************************/
#include "stdint.h"
#include "stdbool.h"
#include "stack.h"
#include <string.h>

/*****************************************************************************
 * Defined and Enumerated Constants                                          *
 *****************************************************************************/
#define STACK_SIZE (sizeof(struct stack_t) + (MAX_STACK_ELEMENTS * sizeof(element_t)))

/*****************************************************************************
 * User Defined Datatypes                                                    *
 *****************************************************************************/
typedef void xdata * element_t;   /* the elements in the queue are void ptrs */

struct stack_t
{
    uint8_t count;                         /* count of elements in the stack */
    uint8_t top;                /* index to the top element in the stack */
    uint8_t max_count;            /* maximum number of elements in the stack */
    element_t xdata * p_contents;        /* pointer to the array of elements */
};

/*****************************************************************************
 * Private Variables                                                         *
 *****************************************************************************/
static uint8_t xdata stack[STACK_SIZE]; /* a stack in external data memory (after the USB xdata)*/
static uint8_t xdata * xdata p_free = &stack[0];    /* a ptr to the start of */
                                                    /* free stack memory     */

/*****************************************************************************
 * Public Functions                                                          *
 *****************************************************************************/

/*****************************************************************************

  NAME:        create_stack

  SCOPE:       PUBLIC

  PARAMETERS:  len - length of stack in bytes

  RETURNS:     p_stack_t

  DESCRIPTION:

 *****************************************************************************/
p_stack_t create_stack(uint8_t len)
{
    p_stack_t p_stack;
    uint16_t bytes_required;

    bytes_required = sizeof(struct stack_t) + (len * sizeof(element_t));

    if ((p_free + bytes_required <= &stack[0] + STACK_SIZE) &&
        (len != 0))
    {
        /* there is room for this new stack */
        p_stack = (p_stack_t) p_free;
        p_free += sizeof(struct stack_t);
        p_stack->p_contents = (element_t xdata *) p_free;
        p_free += len * sizeof(element_t);

        p_stack->max_count = len;

        flush_stack(p_stack);              /* initialized stack indexes and count */
    }
    else
    {
        p_stack = NULL;                 /* out of memory return NULL pointer */
    }

    return p_stack;
}

/******************************************************************************

  NAME:        push

  SCOPE:       public

  PARAMETERS:  q = pointer to a stack structure
               val = element to be added to the stack

  RETURNS:     0 if the element could not be added, since the stack was full
               1 if the element was successfully added to the stack

  DESCRIPTION: This function adds elements to a stack.  It maintains the front
               and rear indexes into the stack's array together with an
               element count.

 *****************************************************************************/
bool push(p_stack_t s, element_t element)
{
    bool status;

    if (s->count == s->max_count)
    {
        status = false;    /* stack is full */
    }
    else
    {
        s->p_contents[s->top] = element;

        s->top++;
        s->count++;

        status = true;
    }

    return status;
}

/*****************************************************************************

  NAME:        pop

  SCOPE:       public

  PARAMETERS:  s = pointer to a stack structure

  RETURNS:     NULL pointer if the stack was empty and no element was returned
               otherwise a pointer from the stack

  DESCRIPTION: This function removes elements from a stack and returns them to
               the caller.  It maintains the top indexes into the
               stack's array together with an element count.

 *****************************************************************************/
element_t pop(p_stack_t s)
{
    element_t element;

    if (s->count == 0)
    {
        element = NULL;
    }
    else
    {
        s->top--;
        s->count--;

        element = s->p_contents[s->top];
    }

    return element;
}

/*****************************************************************************

  NAME:        flush_stack

  SCOPE:       public

  PARAMETERS:  s = pointer to a stack structure

  RETURNS:     void

  DESCRIPTION: This function resets the top indexes together with
               the element count.  It doesn't actually clear any items in
               memory.

 *****************************************************************************/
void flush_stack(p_stack_t s)
{
    s->count = 0;
    s->top = 0;
}

/*****************************************************************************
 *
 * NAME:        top_stack
 *
 * SCOPE:       public
 *
 * PARAMETERS:  s = pointer to a stack structure

 * RETURNS:     NULL pointer if the stack was empty and no element was returned
                otherwise a pointer from the stack
 *
 * DESCRIPTION: This function does not remove elements from a stack, it only
 *              returns the value of the top item in the stack.
 *
 *****************************************************************************/
element_t top_stack(p_stack_t s)
{
    element_t element;

    if (s->count == 0)
    {
        element = NULL;
    }
    else
    {
        element = s->p_contents[(s->top) - 1];
    }

    return element;
}

/*****************************************************************************
 *
 * NAME:        size_stack
 *
 * SCOPE:       public
 *
 * PARAMETERS:  s = pointer to a stack structure

 * RETURNS:     integer element count
 *
 * DESCRIPTION: This function returns the number of elements on the stack..
 *
 *****************************************************************************/
uint8_t size_stack(p_stack_t s)
{
    return s->count;
}

/*****************************************************************************
 *
 * NAME:        destroy_stack
 *
 * SCOPE:       public
 *
 * PARAMETERS:  void

 * RETURNS:     void
 *
 * DESCRIPTION:
 *
 *****************************************************************************/
void destroy_stack(void)
{
    p_free = &stack[0];
}

