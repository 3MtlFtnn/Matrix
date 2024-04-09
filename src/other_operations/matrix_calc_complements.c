#include "../s21_matrix.h"
#include <math.h>
/*
    параметры:
    matrix_t *A - исходная матрица
    matrix_t *result - обработанная матрица

    возвращает:
    0 - OK
    1 - Ошибка в вычислениях

*/
int s21_calc_complements(matrix_t *A, matrix_t *result){
    int flag = 0;
    if(A==NULL || (A->columns != A->rows)) return FAILURE;
    s21_create_matrix(A->rows, A->rows, result);

    for(int i = 0; i < A->rows; i++){
        for(int j = 0; j < A->columns; j++){
            matrix_t *temp = malloc(sizeof(double **));
            double determ = 0;
            s21_create_matrix(A->columns-1, A->rows-1, temp);
            matrix_min(A->matrix, temp->matrix, i, j, A->rows);
            s21_determinant(temp, &determ);
            result->matrix[i][j] = pow(-1, (i+j))*determ;
            s21_remove_matrix(temp);
        }
    }
    return flag;
}
