#include <stdio.h>
#include <stdlib.h>
#include "./headers/Mat.h"
#include "./headers/DenseLayer.h"
#include "./headers/utils.h"

int main(){
    srand(time(0));
    Mat * matrix1 = new_rand_mat(2, 2, 0, 1);
    //Mat * matrix2 = new_rand_mat(2, 2, 0, 1);
    print(matrix1, MAT);
    //print_mat(matrix2);
    //Mat * new_mat_dot = dot_product(matrix1, matrix2);
    //print_mat(new_mat_dot);
    DenseLayer *layer = new_dense_layer(3, 3);
    print(layer, DL);
    /*Mat *input = new_rand_mat(3, 1, 0, 1);
    print_mat(input);
    DenseLayer *prop_layer = f_prop_dense_layer(layer, input);
    print_dense_layer_output(prop_layer);
    Mat *activated_output = activate_dense_layer(prop_layer);
    print_mat(activated_output);*/
    return 0;
}


// layer1 = conv_layer(in_size, kernel_channels, kernel_size, stride, padding)
// layer2 = conv_layer(in_size, put_size)
//
// forward(input){
//   output = AF(forward(layer1, input))
//   output = AF(forward(layer2, output))
//   return output
// }
