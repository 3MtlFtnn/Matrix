#include "../s21_matrix.h"

/*
  Высчитывает определитель 

  параметры:
  - matrix_t *A = Матрица
  - *result = определитель

  возвращает:
  0 - хорошо
  1 - плохо
  2 - ошибка вычислений

*/
int s21_determinant(matrix_t *A, double *result) {
  if(A->columns != A->rows){
    return FAILURE;
  }else{
    if(A->rows == 1){
      *result = A->matrix[0][0];
    }else if(A->rows == 2){
      *result = (A->matrix[0][0] * A->matrix[1][1]) - (A->matrix[0][1] * A->matrix[1][0]);
    // - вот тут когда не 2 
    }else if(){

    }
  }

}