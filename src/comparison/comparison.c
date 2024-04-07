#include "../s21_matrix.h"

/* Сравнивает две матрицы *A и *B
 *
 *  параметры:
 *  matrix_t *A - матрица 1
 *  matrix_t *B - матрица 2
 *
 *  возвращает:
 *  COMP_FAILURE (0) - матрицы не равны
 *  COMP_SUCCESS (1) - матрицы равны
 *
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int a_columns = A->columns;
  int a_rows = A->rows;
  int b_columns = A->columns;
  int b_rows = A->rows;

  if (!(a_columns != b_columns) || (a_rows != b_rows)) {
    for (int i = 0; i < a_rows; i++) {
      for (int j = 0; j < a_columns; j++) {
        if (!(A->matrix[i][j] == B->matrix[i][j]))
          return COMP_FAILURE;
      }
    }
  }

  return COMP_SUCCESS;
}
