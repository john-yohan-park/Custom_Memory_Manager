// John Park
#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <cstddef> // for size_t

class Allocator {
public:
    size_t megs = 256;                 // # of megabytes to reserve
    size_t cap  = 1024*1024*megs;      // 256 MB
    int wordCap = cap/4;               // num of words in 256 MB
    Allocator() {}                     // cnstr
    virtual ~Allocator() {}            // virtual so FFit, BFit, YFit dstr get called
    virtual void* alloc  (size_t) = 0; // allocate mem
    virtual void  dealloc(void*)  = 0; // free mem
};// Allocator

#endif // ALLOCATOR