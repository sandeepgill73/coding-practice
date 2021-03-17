#ifndef STACK_H
#define STACK_H

#include "stdint.h"
#include "stdbool.h"

/*****************************************************************************
 * Defined and Enumerated Constants                                          *
 *****************************************************************************/

/* For a single stack, this is the maximum number of elements, for multiple
 * stacks, this will decrease by 3 elements for each extra stack */
#define MAX_STACK_ELEMENTS   (100U)

/*****************************************************************************
 * User Defined Datatypes                                                    *
 *****************************************************************************/
typedef struct stack_t xdata * p_stack_t;

/*****************************************************************************
 * Public Prototypes                                                         *
 *****************************************************************************/
extern p_stack_t create_stack(uint8_t);
extern void destroy_stack(void);
extern bool push(p_stack_t, void xdata *);
extern void xdata * pop(p_stack_t);
extern void flush_stack(p_stack_t);
extern void xdata * top_stack(p_stack_t);
extern uint8_t size_stack(p_stack_t);

#endif
