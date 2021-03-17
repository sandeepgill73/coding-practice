/*****************************************************************************
 * Includes                                                                  *
 *****************************************************************************/
#include <string.h>
#include "stdint.h"
#include "stdbool.h"
#include "assert.h"
#include "mem_pool.h"
#include "xdata_memcpy.h"

/*****************************************************************************
 * User Defined Datatypes                                                    *
 *****************************************************************************/
typedef struct node
{
    /* Pointer to allocated memory */
    uint8_t xdata * p_alloc;
    /* Flag indicating allocated memory is no longer needed */
    uint8_t b_used;
    /* Pointer to previous node struct in linked list */
    struct node xdata * p_prev_node;
    /* Pointer to next node struct in linked list */
    struct node xdata * p_next_node;
} node_t;

/*****************************************************************************
 * Private Variables                                                         *
 *****************************************************************************/
DEFINE_THIS_FILE

/* Generic memory pool used by the various download algorithms */
static uint8_t xdata g_mem_pool[MEM_POOL_SIZE];

/*****************************************************************************
 * Public Functions                                                          *
 *****************************************************************************/

/******************************************************************************

  FUNCTION:     mem_pool_init

  SCOPE:        public

  PARAMETERS:

  RETURNS:

  DESCRIPTION:  Initialized our memory pool data structure

******************************************************************************/
void mem_pool_init(void)
{
    /* Initialize mem pool to zero on power up, this will also set the root
     * nodes prev and next pointers to NULL, which is necessary. */
    memset_xdata(&g_mem_pool[0], 0, sizeof(g_mem_pool));
}

/******************************************************************************

  FUNCTION:     mem_pool_alloc

  SCOPE:        public

  PARAMETERS:   uint16_t len - amount of memory in bytes to allocate

  RETURNS:      uint8_t xdata * - pointer to allocated memory

  DESCRIPTION:  Allocates variable sized memory chucks from a pool of memory

******************************************************************************/
uint8_t xdata * mem_pool_alloc(uint16_t len, uint8_t skip_assert)
{
    node_t xdata * p_node = (node_t xdata *) &g_mem_pool[0];
    uint16_t diff;

    /* Find the next node */
    while (p_node->p_next_node != NULL)
    {
        p_node = p_node->p_next_node;
    }

    /* Find the allocation pointer by incrementing past the node */
    p_node->p_alloc = (uint8_t xdata *) (p_node + 1);

    /* Confirm we have enough memory for the allocation */
    if ((p_node->p_alloc + len + sizeof(node_t)) > &g_mem_pool[MEM_POOL_SIZE])
    {
        p_node = (node_t xdata *) &g_mem_pool[0];

        /* Look for unused block large enough */
        while (p_node->p_next_node != NULL)
        {
            diff = ((uint16_t)(p_node->p_next_node)) - ((uint16_t) (p_node->p_alloc));

            if ((p_node->b_used == false) && (diff >= len))
            {
                /* We found a block large enough */
                p_node->b_used = true;
                break;
            }
            else
            {
                p_node = p_node->p_next_node;
            }
        }

        if (p_node->p_next_node == NULL)
        {
            if (skip_assert == false)
            {
                ASSERT(0);
            }
            else
            {
                /* clear memory pool */
                mem_pool_init();
                return NULL;
            }
        }
    }
    else
    {
        /* Indicate our allocation is in use */
        p_node->b_used = true;
        /* Find the next node pointer */
        p_node->p_next_node = (node_t xdata *) (p_node->p_alloc + len);

        /* Write the next nodes fields */
        p_node->p_next_node->p_next_node = NULL;
        p_node->p_next_node->p_prev_node = p_node;
    }

    return p_node->p_alloc;
}

/******************************************************************************

  FUNCTION:     mem_pool_free

  SCOPE:        public

  PARAMETERS:   void xdata * p_free - pointer to allocated memory being freed

  RETURNS:      void

  DESCRIPTION:  Frees up memory chucks that have been previously allocated

******************************************************************************/
void mem_pool_free(void const xdata * p_free, uint8_t skip_assert)
{
    node_t xdata * p_node = (node_t xdata *) &g_mem_pool[0];

    /* Find the node to free */
    while ((p_node->p_next_node != NULL) &&
           (p_node->p_alloc != p_free))
    {
        p_node = p_node->p_next_node;
    }

    if (p_node->p_next_node == NULL)
    {
        /* An invalid pointer was passed to this function */
        if (skip_assert == false)
        {
            ASSERT(0);
        }
        else
        {
            /* clear memory pool */
            mem_pool_init();
        }
    }
    else if (p_node->p_next_node->p_next_node == NULL)
    {
        /* If node corresponds to the last allocation then deallocate it */
        p_node->p_next_node = NULL;

        /* Traverse back over the linked list and free up allocations
         * if they are unused */
        while ((p_node->p_prev_node != NULL) &&
               (p_node->p_prev_node->b_used == false))
        {
            /* We can free up the previous allocation as well */
            p_node = p_node->p_prev_node;
            p_node->p_next_node = NULL;
        }
    }
    else
    {
        /* If not mark it as unused */
        p_node->b_used = false;

        if ((p_node->p_prev_node != NULL) &&
            (p_node->p_prev_node->b_used == false))
        {
            /* Merge with previous unused block */
            p_node->p_prev_node->p_next_node = p_node->p_next_node;
            p_node->p_next_node->p_prev_node = p_node->p_prev_node;
        }
        else if ((p_node->p_next_node->p_next_node != NULL) &&
                 (p_node->p_next_node->b_used == false))
        {
            /* Merge with next unused block*/
            p_node->p_next_node = p_node->p_next_node->p_next_node;
            p_node->p_next_node->p_prev_node = p_node;
        }
        else
        {
        }
    }
}

