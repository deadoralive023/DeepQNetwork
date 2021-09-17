#include "../headers/utils.h"



void print(void *o, enum o_type type){
    switch(type){
        case MAT:
            print_mat((Mat*)o);
            break;
        case DL:
            print_dense_layer((DenseLayer*)o);
            break;
    }
}
