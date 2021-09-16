#include "../headers/Mat.h"

float uniform_rand(float left, float right) {
    float randomNumber = sin(rand() * rand());
    return left + (right - left) * fabs(randomNumber);
}

int index_to_cordinate(unsigned int cols, unsigned int row, unsigned int col){
    return row * cols + col;
}
    
Mat *new(unsigned int rows, unsigned int cols){
    if(rows == 0) { printf("Error: Invalid no of rows"); return NULL; }
    if(cols == 0) { printf("Error: Invalid no of cols"); return NULL; }
    Mat *ptr = (Mat*) calloc(1, sizeof(Mat));
    ptr->rows = rows;
    ptr->cols = cols;
    ptr->data = (float*) calloc(1, rows * cols * sizeof(float));
    return ptr;
}

void delete(Mat*self){
    free(self->data);
    free(self);_
}

void print(Mat *self){
    printf("\n\n");
    for(unsigned int row = 0; row < self->rows; row++){
        for(unsigned int col = 0; col < self->cols; col++){
            printf("%f  ", self->data[index_to_cordinate(self->cols, row, col)]);
        }
        printf("\n\n");
    }
}

Mat *new_rand(unsigned int rows, unsigned int cols, int min, int max){
    if(rows == 0) { printf("Error: Invalid no of rows"); return NULL; }
    if(cols == 0) { printf("Error: Invalid no of cols"); return NULL; }
    Mat *ptr = (Mat*) calloc(1, sizeof(Mat));
    ptr->rows = rows;
    ptr->cols = cols;
    ptr->data = (float*) calloc(1, rows * cols * sizeof(float));
    for(unsigned int i = 0; i < ptr->rows * ptr->cols; i++){
        float rnd = uniform_rand(min, max);
        ptr->data[i] = rnd;
    }
    return ptr;
}

Mat * dot_product(Mat *mat1, Mat *mat2){
    if (mat1->cols != mat2->rows) { printf("Error: no of cols don't match no of rows"); return NULL; }
    Mat *new_mat_ptr = new(mat1->rows, mat2->cols);
    for(unsigned int row = 0; row < mat1->rows; row++){
        for(unsigned int col = 0; col < mat2->cols; col++){
            float sum= 0;
            for(unsigned int i = 0; i < mat1->cols; i++){
                sum += (mat1->data[index_to_cordinate(mat1->cols, row, i)] * mat2->data[index_to_cordinate(mat2->cols, i, col)]);
            }
            new_mat_ptr->data[index_to_cordinate(new_mat_ptr->cols, row, col)] = sum;
        }
    }
    return new_mat_ptr;
}

Mat * add_mat(Mat *mat1, Mat *mat2){
    if (mat1->rows != mat2->rows || mat1->cols != mat2->cols) { printf("Error: Both Mats must match the shape"); return NULL; }
    Mat *new_mat_ptr = new(mat1->rows, mat1->cols);
    for(unsigned int i = 0; i < mat1->rows * mat1->cols; i++){
        new_mat_ptr->data[i] = mat1->data[i] + mat2->data[i];
    }
    return new_mat_ptr;
}

Mat * add_num(Mat *mat, float num){
    Mat *new_mat_ptr = new(mat->rows, mat->cols);
    for(unsigned int i = 0; i < mat->rows * mat->cols; i++){
        new_mat_ptr->data[i] = mat->data[i] + num;
    }
    return new_mat_ptr;
}

