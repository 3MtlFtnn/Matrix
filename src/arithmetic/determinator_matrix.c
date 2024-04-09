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
  if (A==NULL){
   return FAILURE;
  }
  if (A->columns != A->rows){
    return FAILURE;
  }
  if (A->rows == 1){
    *result = A->matrix[0][0];
  }
  else if(A->rows == 2){
      *result = (A->matrix[0][0] * A->matrix[1][1]) - (A->matrix[0][1] * A->matrix[1][0]);
  }else{
      *result = help_determinant(A, A->rows);
  }

  return SUCCESS;
}
double help_determinant(matrix_t *A, int size) {
    double answer = 0;
    int sign = 1;
    matrix_t *temp = malloc(sizeof(double **));
    s21_create_matrix(size - 1, size - 1, temp);

    for (int i = 0; i < A->rows; i++){
        matrix_min(A->matrix, temp->matrix, 0, i, A->rows);
        answer += sign* A->matrix[0][i] * help_determinant(temp, size-1);
        sign*=-1;
    }
    s21_remove_matrix(temp);
    return answer;
}
