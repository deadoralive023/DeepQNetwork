#ifndef MAT
#define MAT
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct Matrix {
    unsigned int rows;
    unsigned int cols;
    float *data;
} Mat;

float uniform_rand(float left, float right);
int index_to_cordinate(unsigned int, unsigned int, unsigned int);
    
Mat *new(unsigned int, unsigned int);
void print(Mat *);
Mat *new_rand_mat(unsigned int, unsigned int, int, int);
Mat * dot_product(Mat *, Mat *);
Mat * add_mat(Mat *, Mat *);
Mat * add_num(Mat *, float);

#endif
