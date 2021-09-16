#include <stdio.h>
#include <stdlib.h>
#include "./headers/Mat.h"

int main(){
    srand(time(0));
    Mat * matrix1 = new(2, 2);
    Mat * matrix2 = new(2, 2);
    print(matrix1);
    print(matrix2);
    Mat * new_mat_dot = add_num(matrix1,  13);
    print(new_mat_dot);
    return 0;
}
