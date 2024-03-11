///////////////////////////
// Matrix Multiplication //
///////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct matrix {
    int r; // rows
    int c; // columns
    float *d; // data
} matrix;

float randfloat(float min, float max) {
    int irandom;
    float frandom;
    irandom = rand();
    frandom = min + ((float) irandom / RAND_MAX) * (max - min);
    return frandom;
} // randfloat

void matin(matrix *m, int rows, int cols, float* values) {
    int i, j;
    m->r = rows;
    m->c = cols;
    m->d = (float *)malloc(rows * cols * sizeof(float));
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            m->d[i * cols + j] = values[i * cols + j];
        }
    }
} // matin

void matout(matrix *a) {
    int i, j, r, c;
    r = a->r;
    c = a->c;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%3f ", a->d[i * c + j]);
        }
        printf("\n");
    }
} // matout

void matmul(matrix *a, matrix *b, matrix *c) {
    int i, j, k, ar, ac, cc;
    float *am, *bm, *cm;
    ar = a->r;
    ac = a->c;
    cc = c->c;
    am = a->d;
    bm = b->d;
    cm = c->d;

    // Version 1: loop order (i j k)
    for (i = 0; i < ar; i++) {
        for (j = 0; j < cc; j++) {
            cm[i * cc + j] = 0;
            for (k = 0; k < ac; k++) {
                cm[i * cc + j] += am[i * ac + k] * bm[k * cc + j];
            }
        }
    }
} // matmul

int main() {
    int r1, c1, r2, c2;
    matrix a, b, c;
    
    float values_a[] = {1, 2, 3, 4, 5, 6}; // Change values as needed
    float values_b[] = {7, 8, 9, 10, 11, 12}; // Change values as needed

    r1 = 2; c1 = 3; // Matrix a is 2x3
    r2 = 3; c2 = 2; // Matrix b is 3x2

    if (c1 != r2) {
        printf("ERROR: matrices are incompatible!\n");
        exit(EXIT_FAILURE);
    }

    matin(&a, r1, c1, values_a);
    matin(&b, r2, c2, values_b);

    c.r = a.r;
    c.c = b.c;
    c.d = (float *)malloc(c.r * c.c * sizeof(float));

    matmul(&a, &b, &c);

    printf("Matrix A:\n");
    matout(&a);
    printf("\nMatrix B:\n");
    matout(&b);
    printf("\nProduct of A and B:\n");
    matout(&c);

    free(a.d);
    free(b.d);
    free(c.d);

    return EXIT_SUCCESS;
} // main

