#ifndef QUEUE_H
#define QUEUE_H

#include "stdint.h"
#include "stdbool.h"

/*****************************************************************************
 * Defined and Enumerated Constants                                          *
 *****************************************************************************/

/* For a single queue, this is the maximum number of elements, for multiple
 * queues, this will decrease by 3 elements for each extra queue */
#define MAX_QUEUE_ELEMENTS   (275u)

/*****************************************************************************
 * User Defined Datatypes                                                    *
 *****************************************************************************/
typedef struct queue_t xdata * p_queue_t;

/*****************************************************************************
 * Public Prototypes                                                         *
 *****************************************************************************/
extern p_queue_t createQ(uint8_t);
extern bool enqueue(p_queue_t, void xdata *);
extern void xdata * dequeue(p_queue_t);
extern void flushQ(p_queue_t);
extern void xdata * frontQ(p_queue_t);

#endif
