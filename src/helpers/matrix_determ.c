#include "../s21_matrix.h"
#include <stdio.h>

double matrix_determ(matrix_t *A, int size){
    if(size == 1){
        return A->matrix[0][0];
    }
    matrix_t temp = {0};
    double result = 0;
    s21_create_matrix(size, size, &temp);
    for(int sign = 1, x = 0; x<size; x+=1, sign*=(-1)){
        matrix_min(A->matrix, temp.matrix, 0, x, size);
        result+= sign * A->matrix[0][x] * matrix_determ(&temp, size - 1);
    }
    s21_remove_matrix(&temp);
    return result;
}
