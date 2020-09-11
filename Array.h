#ifndef ARRAY_H
#define ARRAY_H

typedef struct Array Array;

/** array */
struct Array
{
    unsigned size; //!< tamaño del array
    void **data; //!< datos del array
};

void aforeach(Array *a, void (*func)(void *)); //!< foreach
Array *newArray(void); //!< crea array
void releaseArray(Array *a); //!< libera array
void arrayAppend_u(Array *a, unsigned i); //!< agrega unsigned al array
void adeleteall(Array *a); //!< libera contenido del array

#endif // ARRAY_H
