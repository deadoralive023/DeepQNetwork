#include "../headers/DenseLayer.h"

DenseLayer * new_dense_layer(unsigned int in_size, unsigned int out_size){
    if(in_size == 0) { printf("Error: Invalid input size"); return NULL; }
    if(out_size == 0) { printf("Error: Invalid output size"); return NULL; }
    DenseLayer *dense_layer = (DenseLayer*) calloc(1, sizeof(DenseLayer));
    dense_layer->in_size = in_size;
    dense_layer->out_size = out_size;
    dense_layer->weights = new_rand_mat(out_size, in_size, 0, 1);
    return dense_layer;
}

void print_dense_layer(DenseLayer *self){
    print_mat(self->weights);
}

void print_dense_layer_output(DenseLayer *self){
    print_mat(self->output);
}

DenseLayer *f_prop_dense_layer(DenseLayer *self, Mat *prev_output){
    self->output = dot_product(self->weights, prev_output);
    return self;
}

Mat *activate_dense_layer(DenseLayer *self){
    self->activated_output = clone_mat(self->output);
    for(unsigned int row = 0; row < self->activated_output->rows; row++){
        float curr_val = get_mat_val_at(self->activated_output, row,  0);
        set_mat_val_at(self->activated_output, row, 0, Relu(curr_val));
    }
    return self->activated_output;
}
