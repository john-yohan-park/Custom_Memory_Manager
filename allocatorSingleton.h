// John Park
#ifndef ALLOCATORSINGLETON_H
#define ALLOCATORSINGLETON_H

#include "allocator.h"
#include "FFit.h"

class AllocatorSingleton {
public:
    static Allocator* getAllocator();
private:
    static Allocator* a;   // singly instantiated allocator obj
    AllocatorSingleton(){} // priv cnstr 
};// singleton

#endif // ALLOCATORSINGLETON