#ifndef __MAT__
#define __MAT__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct Matrix {
    unsigned int rows;
    unsigned int cols;
    float **data;
} Mat;

float uniform_rand(float, float);

Mat *new_mat(unsigned int, unsigned int);

void delete_mat(Mat*);

void print_mat(Mat *);

Mat *new_rand_mat(unsigned int, unsigned int, int, int);

Mat *dot_product(Mat *, Mat *);

Mat *add_mat(Mat *, Mat *);

Mat *add_num(Mat *, float);

float mat_sum(Mat *);

float mat_avg(Mat *);

void set_mat_val_at(Mat *, unsigned int, unsigned int, float);

float get_mat_val_at(Mat *, unsigned int, unsigned int);

Mat *clone_mat(Mat *);

Mat *clone_mat_at(Mat *, unsigned int, unsigned int, unsigned int, unsigned int);


#endif
