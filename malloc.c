#include "malloc.h"
#define BASE_MEM_POINTER 0x20004000 
/* Testing pointers 
heap_s liam = {(heap_s *) 0x10010001, (heap_s *) 0x00010001,4, (block_t *) 0x00010001, (block_t*) 0x00010001};

void * my_malloc(long int size)
{
    return &liam;
}
*/

/*
void * my_malloc(long int size)
{
    void *sram_pointer = (void *)(0x20004000);
    return sram_pointer;
}
*/

static heap_s sections[6]; /* 6 1024 byte sections tracker */
static block_t blocks[64]; /* 16 byte blocks tracker */ /* Might need to initialize some of the values */

void * __allocate_block(int number)
{
    /* Iterate through the blocks */
    for(int i=0;i<64;i++)
    {
        if(blocks[i].is_used == 1)
        {
            /* Continue iteration */
        }
        else
        {
            /* Allocate block */
            void *mem_ptr = (void *) (0x20004000 + (unsigned long int) i*0x10);
            blocks[i].prev = (block_t *) (0x20004000 + (unsigned long int) i*0x10); //Storing pointer for free
            blocks[i].is_used = 1;
            return mem_ptr;
        }
    }
    /* Check if they are used */

    /* Continue iteration or assign pointer to block depending on the index */
    return (void *) (0x20004000);
}

void * my_malloc(int size)
{
    void *sram_pointer;
    /* Check size to see how many blocks will be allocated */
    //Think about scalability with enums or whatever
    if(size < 16)
    {
        sram_pointer = (void *) __allocate_block(1); /* Allocate one blocks */
    }
    else if (32 >= size > 16)
    {
        sram_pointer = (void *) __allocate_block(2); /* Allocate two blocks */
    }
    return sram_pointer;
}

int my_free(void * p)
{
    for(int i=0;i<64;i++)
    {
        if(p == blocks[i].prev)
        {
            blocks[i].is_used = 0;
        }
        else
        {
            return -1;
        }
    }
}