
#include "malloc.h"

//Uncomment for ARM compatible code 
void reset(void)
{
    struct heap_list *ptr = my_malloc(sizeof(struct heap_list));
    ptr->first = 75;
    ptr->last = 79;
    my_free(ptr);
    struct heap_list *ptr2 = my_malloc(sizeof(struct heap_list));
    ptr2->first = 79;
    ptr2->last = 79;
    my_free(ptr2);
    struct heap_list *ptr3 = my_malloc(sizeof(struct heap_list));
    ptr3->first = 80;
    ptr3->last = 81;
}

//Allocate STACK

int STACK[256];

//Creating the Vector table
const void *vectors[] __attribute__ ((section(".vectors"))) = //Instruct GCC to put the vector table in the vectors section
{
    STACK + sizeof(STACK)/sizeof(*STACK),
    reset
};



/*
int main()
{
    struct heap_list *ptr = my_malloc(sizeof(struct heap_list));
    printf("%p\n",ptr);
    ptr->first = 75;
    ptr->last = 79;
    struct heap_list *ptr2 = my_malloc(sizeof(struct heap_list));
    printf("%p\n",ptr2);
    ptr->first = 79;
    ptr->last = 75;
    return 0;   
}
*/