#include "../s21_matrix.h"
#include <stdio.h>
/*
int s21_calc_complements(matrix_t *A, matrix_t *result) {
    if(A==NULL || (A->columns!=A->rows)){
        return FAILURE;
    }else {
        s21_create_matrix(A->rows, A->columns, result);
        if(A->rows!=1){
            matrix_t temp ={0};
            s21_create_matrix(A->rows, A->columns, &temp);
            for (int sign = 0, x = 0; x < A->rows; x++){
                for (int y = 0; y < A->columns ;y++){
                    matrix_min(A->matrix, temp.matrix, x, y, A->rows);
                    sign = ((x+y)%2==0) ? 1 : (-1);
                    //result->matrix[x][y] = sign * calc
                }
            }
        }
    }

    return SUCCESS;
}
*/
