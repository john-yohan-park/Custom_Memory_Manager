// John Park
#include "functions.h"

void* operator new(size_t sz) {return AllocatorSingleton::getAllocator()->alloc(sz);}
void* operator new[](size_t sz) {return AllocatorSingleton::getAllocator()->alloc(sz);}
void  operator delete(void* p) {AllocatorSingleton::getAllocator()->dealloc(p);}
void  operator delete[](void* p) {AllocatorSingleton::getAllocator()->dealloc(p);}