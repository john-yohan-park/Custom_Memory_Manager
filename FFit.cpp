// John Park
#include "FFit.h"

FFit::FFit() {
    startMem   = malloc(cap);
    endMem     = (uintptr_t*) startMem + cap;
    bookkeeper = new (malloc(cap)) int[wordCap]; // bookkeeper
}// cnstr

FFit::~FFit() {
    free(startMem);
    free(bookkeeper);
    startMem   = nullptr;
    endMem     = nullptr;
    bookkeeper = nullptr;
}// dstr

void* FFit::alloc(size_t sz) {
    pad(sz);
    int wordSz = sz/4;
    void* adr = nullptr;
    int i, j, k;
    for(i=0; i+wordSz < wordCap; ++i) {
        if(bookkeeper[i]==0) {
            for(j=i; j-i < wordSz; ++j) if(bookkeeper[j]!=0) break;
            if(j-i==wordSz) {
                adr = (uintptr_t*) startMem + 4*i;
                for(k=0; k<wordSz; ++k) bookkeeper[k+i]=k+1;
                break;
            }// if
        }// if
    }// for
    if(adr==nullptr) {
        cout << "Could not find adequate block of memory." << endl;
        exit(0);
    }// if
    void* endAdr = (uintptr_t*) adr + sz;
    return adr;
}// aclloc

void FFit::dealloc(void* adr) {
    int start = ((uintptr_t*) adr - (uintptr_t*) startMem)/4;
    for(int i=start; bookkeeper[i]==i-start+1; ++i) bookkeeper[i] = 0;        
}// free

void FFit::pad(size_t& sz) {if(sz%4!=0) sz=(sz/4+1)*4;} // pad num bytes

void FFit::print() { // for debugging
    for(int i=0; i<=wordCap; ++i) cout << bookkeeper[i] << '\t' << (uintptr_t*) startMem + 4*i << endl;
    cout << endl;
}// prnt
