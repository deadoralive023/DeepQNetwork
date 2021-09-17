#ifndef __CONV2D__
#define __CONV2D__

#include "./Mat.h"

#define RST  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"


#define BOLD "\x1B[1m"
#define UNDL "\x1B[4m"


typedef struct pair {
    unsigned int rows;
    unsigned int cols;
} pair;
typedef struct Conv2dLayer {
    unsigned int in_size;
    unsigned int out_size;
    unsigned int no_of_kernels;
    pair kernel_size;
    unsigned int padding;
    unsigned int stride;
    Mat *** kernels;
    Mat **output;
} Conv2dLayer;

Conv2dLayer *new_conv2d_layer(unsigned int, unsigned int, pair, unsigned int, unsigned int);
Conv2dLayer *convolve(Conv2dLayer *, Mat**);
void print_conv2d_layer(Conv2dLayer *);
void print_conv2d_layer_output(Conv2dLayer *);

#endif
