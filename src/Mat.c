#include "../headers/Mat.h"

float uniform_rand(float left, float right) {
    float randomNumber = sin(rand() * rand());
    return left + (right - left) * fabs(randomNumber);
}

    
Mat *new_mat(unsigned int rows, unsigned int cols){
    if(rows == 0) { printf("Error: Invalid no of rows"); return NULL; }
    if(cols == 0) { printf("Error: Invalid no of cols"); return NULL; }
    Mat *ptr = (Mat*) calloc(1, sizeof(Mat));
    ptr->rows = rows;
    ptr->cols = cols;
    ptr->data = (float**) calloc(1, rows * sizeof(float*));
    for(unsigned int row = 0; row < rows; row++){
        ptr->data[row] = (float*) calloc(1, cols * sizeof(float));
    }
    return ptr;
}

void delete_mat(Mat*self){
    for(unsigned int i = 0; i < self->cols; i++){
        free(self->data[i]);
    }
    free(self->data);
}

void print_mat(Mat *self){
    printf("\n\n");
    for(unsigned int row = 0; row < self->rows; row++){
        for(unsigned int col = 0; col < self->cols; col++){
            printf("%f  ", self->data[row][col]);
        }
        printf("\n\n");
    }
}

Mat *new_rand_mat(unsigned int rows, unsigned int cols, int min, int max){
    if(rows == 0) { printf("Error: Invalid no of rows"); return NULL; }
    if(cols == 0) { printf("Error: Invalid no of cols"); return NULL; }
    Mat *ptr = (Mat*) calloc(1, sizeof(Mat));
    ptr->rows = rows;
    ptr->cols = cols;
    ptr->data = (float**) calloc(1, rows * sizeof(float*));
    for(unsigned int row = 0; row < rows; row++){
        ptr->data[row] = (float*) calloc(1, cols * sizeof(float));
    }
    for(unsigned int row = 0; row < rows; row++){
        for(unsigned int col = 0; col < cols; col++){
            float rnd = uniform_rand(min, max);
            ptr->data[row][col] = rnd;
        }
    }
    return ptr;
}

Mat * dot_product(Mat *mat1, Mat *mat2){
    if (mat1->cols != mat2->rows) { printf("Error: no of cols don't match no of rows"); return NULL; }
    Mat *new_mat_ptr = new_mat(mat1->rows, mat2->cols);
    for(unsigned int row = 0; row < mat1->rows; row++){
        for(unsigned int col = 0; col < mat2->cols; col++){
            float sum= 0;
            for(unsigned int i = 0; i < mat1->cols; i++){
                sum += (mat1->data[row][i] * mat2->data[i][col]);
            }
            new_mat_ptr->data[row][col] = sum;
        }
    }
    return new_mat_ptr;
}

Mat * add_mat(Mat *mat1, Mat *mat2){
    if (mat1->rows != mat2->rows || mat1->cols != mat2->cols) { printf("Error: Both Mats must match the shape"); return NULL; }
    Mat *new_mat_ptr = new_mat(mat1->rows, mat1->cols);
    for(unsigned int row = 0; row < mat1->rows; row++){
        for(unsigned int col = 0; col < mat1->cols; col++){
            new_mat_ptr->data[row][col] = mat1->data[row][col] + mat2->data[row][col];
        }
    }
    return new_mat_ptr;
}

Mat *add_num(Mat *mat, float num){
    Mat *new_mat_ptr = new_mat(mat->rows, mat->cols);
    for(unsigned int row = 0; row < mat->rows; row++){
        for(unsigned int col = 0; col < mat->cols; col++){
            new_mat_ptr->data[row][col] = mat->data[row][col] + num;
        }
    }
    return new_mat_ptr;
}

float mat_sum(Mat *mat){
    float sum  = 0;
    for(unsigned int row = 0; row < mat->rows; row++){
        for(unsigned int col = 0; col < mat->cols; col++){
            sum += get_mat_val_at(mat, row, col);
        }
    }
    return sum;
}

float mat_avg(Mat *mat){
    float sum = mat_sum(mat);
    return (sum / (mat->rows * mat->cols));
}



void set_mat_val_at(Mat *self, unsigned int row, unsigned int col, float val){
    if(row >= self->rows) { printf("Error: Invalid row index"); return; }
    if(col >= self->cols) { printf("Error: Invalid col index"); return; }
    self->data[row][col] = val;
}

float get_mat_val_at(Mat *self, unsigned int row, unsigned int col){
    if(row >= self->rows) { printf("Error: Invalid row index"); return -1; }
    if(col >= self->cols) { printf("Error: Invalid col index"); return -1; }
    return self->data[row][col];
}

Mat *clone_mat(Mat *mat){
    Mat *cloned_mat = new_mat(mat->rows, mat->cols);
    for(unsigned int row = 0; row < mat->rows; row++){
        for(unsigned int col = 0; col < mat->cols; col++){
            set_mat_val_at(cloned_mat, row, col, mat->data[row][col]);
        }
    }
    return cloned_mat;
}

Mat *clone_mat_at(Mat *mat, unsigned int x, unsigned int y, unsigned int width, unsigned int height){
    if(width <= x){ printf("Error: width must be greater than x"); return NULL; }
    if(height <= y){ printf("Error: height must be greater than y"); return NULL; }
    if(x >= mat->cols){ printf("Error: width must be greater than x"); return NULL; }
    if(y >= mat->rows){ printf("Error: height must be greater than y"); return NULL; }

    Mat *cloned_mat = new_mat(width - x, width - y);
    for(unsigned int row = x; row < width; row++){
        for(unsigned int col = y; col < height; col++){
            set_mat_val_at(cloned_mat, row, col, mat->data[row][col]);
        }
    }
    return cloned_mat;
}



