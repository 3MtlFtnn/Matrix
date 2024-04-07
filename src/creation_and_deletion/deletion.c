#include "../s21_matrix.h"

/* Удаляет матрицу *A
 *
 *  параметры:
 *  matrix_t *A - матрица, которую нужно удалить
 *
 */
void s21_remove_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
  }
  free(A->matrix);
  free(A);
}
