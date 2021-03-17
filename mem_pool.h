#ifndef MEM_POOL_H
#define MEM_POOL_H

#include "stdint.h"

/*****************************************************************************
 * Defined and Enumerated Constants                                          *
 *****************************************************************************/
#define MEM_POOL_SIZE (1300)

/*****************************************************************************
 * Public Prototypes                                                         *
 *****************************************************************************/
extern void mem_pool_init(void);
extern uint8_t xdata * mem_pool_alloc(uint16_t, uint8_t);
extern void mem_pool_free(void const xdata *, uint8_t);

#endif
