#include <stdio.h>
#include <stdlib.h>
#include "Array.h"

void print(void *ptr)
{
    printf("%u ", *(unsigned *) ptr);
}

int main(void)
{
    Array *a = newArray();
    unsigned x;
    for (x = 0; x < 100; ++x)
    {
        arrayAppend_u(a, x);
    }
    aforeach(a, &print);
    printf("\n");
    adeleteall(a);
    releaseArray(a);
    return 0;
}

