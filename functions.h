// John Park
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "allocatorSingleton.h"

void* operator new(size_t);
void* operator new[](size_t);
void  operator delete(void*);
void  operator delete[](void*);

#endif // FUNCTIONS