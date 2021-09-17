#include "../headers/Conv2d.h"

Conv2dLayer *new_conv2d_layer(unsigned int in_size, unsigned int no_of_kernels, pair kernel_size, unsigned int padding, unsigned int stride){
    if(in_size == 0) { printf("Error: Invalid input size"); return NULL; }
    if(no_of_kernels == 0) { printf("Error: Invalid no of kernel channels"); return NULL; }
    Conv2dLayer *conv2d_layer = (Conv2dLayer*) calloc(1, sizeof(Conv2dLayer));
    conv2d_layer->in_size = in_size;
    conv2d_layer->no_of_kernels = no_of_kernels;
    conv2d_layer->kernel_size = kernel_size;
    conv2d_layer->padding = padding;
    conv2d_layer->stride = stride;
    conv2d_layer->kernels = (Mat***) calloc(no_of_kernels, sizeof(Mat*));
    conv2d_layer->output = (Mat**) calloc(no_of_kernels, sizeof(Mat*));
    for(unsigned int i = 0; i < no_of_kernels; i++){
        conv2d_layer->kernels[i] = (Mat**) calloc(in_size, sizeof(Mat*));
        for(unsigned int j = 0; j < in_size; j++){
            conv2d_layer->kernels[i][j] = new_rand_mat(kernel_size.rows, kernel_size.cols, -1, 1);
        }
    }
    return conv2d_layer;
}

Conv2dLayer *convolve(Conv2dLayer *conv2d_layer, Mat **input){
    for(unsigned int k = 0;  k < conv2d_layer->no_of_kernels; k++){
        // ((n +2p -f)/s)+1
        conv2d_layer->output[k] = new_mat((input[0]->rows + (((2 * conv2d_layer->padding) - conv2d_layer->kernel_size.rows)/conv2d_layer->stride)) + 1, (input[0]->cols + (((2 * conv2d_layer->padding) - conv2d_layer->kernel_size.cols)/conv2d_layer->stride)) + 1);
        for(unsigned c = 0; c < conv2d_layer->in_size; c++){
            float sum =  0;
            for(unsigned int row = 0; row < conv2d_layer->kernels[k][c]->rows; row += conv2d_layer->stride){
                for(unsigned int col = 0; col < conv2d_layer->kernels[k][c]->cols; col += conv2d_layer->stride){
                    Mat *input_kernel = clone_mat_at(input[c], row, col, conv2d_layer->kernel_size.rows, conv2d_layer->kernel_size.cols);
                    sum = mat_sum(add_mat(input_sec, conv2d_layer->kernels[k][c]));
                }
            }
        }
    }
    return NULL;
}

void print_conv2d_layer(Conv2dLayer *conv2d_layer){
    for(unsigned int k = 0; k < conv2d_layer->no_of_kernels; k++){
        printf(BOLD);
        printf(RED); //Set the text to the color red
        printf("%s %d\n\n", "Kernel:", k);
        printf(RST); //Resets the text to default color
        for(unsigned int c = 0; c < conv2d_layer->in_size; c++){
            printf(BOLD);
            printf(GRN); //Set the text to the color red
            printf("%s %d", "Channel:", c);
            printf(RST); //Resets the text to default color
            print_mat(conv2d_layer->kernels[k][c]);
        }
    }
}

void print_conv2d_layer_output(Conv2dLayer *conv2d_layer){
    for(unsigned int k = 0; k < conv2d_layer->no_of_kernels; k++){
        printf(BOLD);
        printf(RED); //Set the text to the color red
        printf("%s %d\n\n", "Output:", k);
        printf(RST); //Resets the text to default color
        print_mat(conv2d_layer->output[k]);

    }
}



