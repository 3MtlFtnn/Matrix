#include "../s21_matrix.h"


/*
  Высчитывает определитель

  параметры:
  - matrix_t *A = Матрица
  - double *result = определитель

  возвращает:
  0 - Отработал без ошибок
  1 - На вход подана неверная матрица
*/
int s21_determinant(matrix_t *A, double *result) {
  int flag = 0;
    if (A->rows == A->columns) {
      *result = matrix_get_determinant(A);
    } else {
      flag = 1;
    }
  return flag;
}


double matrix_get_determinant(matrix_t *A) {
  double flag = 0.0;

  //матрица 1х1
  if (A->rows == 1) {
    flag = A->matrix[0][0];
  //матрица 2х2
  } else if(A->rows == 2) {
    flag = matrix_determinant_2x2(A);
  //матрица высшего порядка
  } else {
    matrix_t *tmp = malloc(sizeof(double **));
    s21_create_matrix(A->rows - 1, A->columns - 1, tmp);
    for (int i = 0; i < A->columns; i++) {
      matrix_minor(A, tmp, 0, i, A->columns);
      if (i % 2) {
        flag -= A->matrix[0][i] * matrix_get_determinant(tmp);
      } else {
        flag += A->matrix[0][i] * matrix_get_determinant(tmp);
      }
    }
    s21_remove_matrix(tmp);
  }
  return flag;
}

double matrix_determinant_2x2(matrix_t *A){
    double result = (A->matrix[0][0]*A->matrix[1][1]) - (A->matrix[0][1]*A->matrix[1][0]);
    return result;
}
