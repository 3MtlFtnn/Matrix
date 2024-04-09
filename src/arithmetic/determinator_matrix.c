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
      *result = help_get_determinant(A);
    } else {
      flag = 1;
    }
  return flag;
}

double help_get_determinant(matrix_t *A) {
  double flag = 0.0;
  if (A->rows == 1) {
    flag = A->matrix[0][0];
  } else {
    matrix_t tmp = {0};
    s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
    for (int i = 0; i < A->columns; i++) {
      s21_get_matrix(0, i, A, &tmp);
      if (i % 2) {
        flag -= A->matrix[0][i] * help_get_determinant(&tmp);
      } else {
        flag += A->matrix[0][i] * help_get_determinant(&tmp);
      }
    }
    //s21_remove_matrix(&tmp);
  }
  return flag;
}
void s21_get_matrix(int row, int col, matrix_t *A, matrix_t *result) {
  int m_row = 0;
  int m_col = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == row) {
      continue;
    }
    m_col = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == col) {
        continue;
      }
      result->matrix[m_row][m_col] = A->matrix[i][j];
      m_col++;
    }
    m_row++;
  }
}
