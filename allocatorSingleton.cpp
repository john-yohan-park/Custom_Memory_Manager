// John Park
#include "allocatorSingleton.h"

Allocator* AllocatorSingleton::a = new (malloc(sizeof(FFit))) FFit;; // instantiate obj
Allocator* AllocatorSingleton::getAllocator() {return a;}            // get instantiated obj