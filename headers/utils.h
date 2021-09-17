#ifndef __UTILS__
#define __UTILS__

#include "./Mat.h"
#include "./DenseLayer.h"
#include "./Conv2d.h"
enum o_type{ MAT = 0, DL = 1, C2DL = 2, C2DLO = 3};
void print(void *, enum o_type);
#endif
