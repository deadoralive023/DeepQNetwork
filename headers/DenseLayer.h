#ifndef __DENSE_LAYER__
#define __DENSE_LAYER__

#include "./Mat.h"
#include "./AF.h"

typedef struct DenseLayer {
    unsigned int in_size;
    unsigned int out_size;
    Mat *weights;
    Mat *output;
    Mat *activated_output;
} DenseLayer;

DenseLayer * new_dense_layer(unsigned int, unsigned int);
void print_dense_layer(DenseLayer *);
void print_dense_layer_output(DenseLayer *);
DenseLayer *f_prop_dense_layer(DenseLayer *, Mat *);
Mat *activate_dense_layer(DenseLayer *);

#endif
