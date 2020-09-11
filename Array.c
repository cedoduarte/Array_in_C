#include "Array.h"
#include <stdlib.h>

void aforeach(Array *a, void (*func)(void *))
{
    unsigned x;
    for (x = 0; x < a->size; ++x)
    {
        func(a->data[x]);
    }
}

Array *newArray(void)
{
    Array *a = (Array *) malloc(sizeof(Array));
    a->data = NULL;
    a->size = 0;
    return a;
}

void releaseArray(Array *a)
{
    free(a->data);
    free(a);
}

void arrayAppend_u(Array *a, unsigned i)
{
    unsigned *ptr = NULL;
    if (a->size == 0)
    {
        a->data = (void **) calloc(sizeof(void *), 1);
        ptr = (unsigned *) malloc(sizeof(unsigned));
        *ptr = i;
        a->data[0] = ptr;
        a->size = 1;
    }
    else if (a->size > 0)
    {
        void **copy = NULL;
        unsigned x;
        copy = (void **) calloc(sizeof(void *), a->size);
        for (x = 0; x < a->size; ++x)
        {
            copy[x] = a->data[x];
        }
        free(a->data);
        a->data = (void **) calloc(sizeof(void *), a->size + 1);
        for (x = 0; x < a->size; ++x)
        {
            a->data[x] = copy[x];
        }
        free(copy);
        ptr = (unsigned *) malloc(sizeof(unsigned));
        *ptr = i;
        a->data[a->size] = ptr;
        a->size += 1;
    }
}

void adeleteall(Array *a)
{
    unsigned x;
    for (x = 0; x < a->size; ++x)
    {
        free(a->data[x]);
    }
}
