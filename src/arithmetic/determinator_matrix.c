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
  }

  
}