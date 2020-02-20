// John Park
#ifndef FFIT_H
#define FFIT_H

#include <iostream>
#include "allocator.h"
using namespace std;

class FFit : public Allocator {
public:
    FFit();               // cnstr
    ~FFit();              // dstr
    void* alloc(size_t);  // allocate memory within reserved memory block
    void  dealloc(void*); // deallocate memory (soft delete)
    void  print();        // for debugging
private:
    void* startMem;       // start adr of reserved memory
    void* endMem;         // end adr of reserved memory
    int*  bookkeeper;     // keeps track of reserved memory
    void  pad(size_t&);   // pad num bytes to fit word boundary
};// FFit

#endif // FFIT