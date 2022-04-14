#ifndef __BINARYHEAP__H__
#define __BINARYHEAP__H__

#include <iostream>
using namespace std;

extern void upAdjust(int* a, int len);
extern void downAdjust(int* a, int parentIndex, int len);
extern void creatHeap(int* a, int len);

#endif // !__BINARYHEAP__H__
