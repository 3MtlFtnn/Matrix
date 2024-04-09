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
  } else {
    //для 2 и более порядка
    matrix_t *tmp = malloc(sizeof(double **));
    s21_create_matrix(A->rows - 1, A->columns - 1, tmp);

    for (int i = 0; i < A->columns; i++) {
      matrix_min(A->matrix, tmp->matrix, 0, i, A->columns);
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
