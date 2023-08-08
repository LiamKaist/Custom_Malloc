#ifndef MALLOC_H
#define MALLOC_H


typedef struct block block_t;
typedef struct heap_section heap_s;

typedef struct block
{
    block_t *prev;
    block_t *next;
    unsigned int size;
    int is_used;
}block_t;

typedef struct heap_section
{
    heap_s *prev;
    heap_s *next;
    /* Size of the heap section */
    /* Number of blocks */
    int num_blocks;
    char u;
    char o;
    char y;
    block_t *start;
    block_t *end; 
}heap_s;

struct heap_list 
{
    int first;
    int last;
};

void * __allocate_block(int number);
void * my_malloc(int size);
int my_free(void * p);

#endif

/*
typedef struct heap_section
{
    heap_s *prev;
    heap_s *next;
    int num_blocks;
    char u;
    char o;
    char y;
    block_t *start;
    block_t *end; 
}heap_s;*/