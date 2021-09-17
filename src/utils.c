#include "../headers/utils.h"


void print(void *o, enum o_type type){
    switch(type){
        case MAT:
            print_mat((Mat*)o);
            break;
        case DL:
            print_dense_layer((DenseLayer*)o);
            break;
        case C2DL:
            print_conv2d_layer((Conv2dLayer*)o);
            break;
        case C2DLO:
            print_conv2d_layer_output((Conv2dLayer*)o);
            break;
    }
}
