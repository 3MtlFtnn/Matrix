#include "../s21_matrix.h"

/* miltiplier_matrix - сохраняет значение
 *  matrix - источник
 *  pivot - центр операции, вокруг него проводятся
 *  вычисления
 *  row_index - индекс матричной строки
 *
 */
void matrix_carry_row(matrix_t *multiplier_matrix, matrix_t *matrix, int pivot,
                      int row_index) {
  int j;
  float multiplier =
      (matrix->matrix[row_index][pivot] / matrix->matrix[pivot][pivot]);

  if (multiplier_matrix != NULL) {
    multiplier_matrix->matrix[row_index][pivot] = multiplier;
  } else {
    perror("Матрицы для сохранения значения не предоставлено.");
    return;
  }

  for (j = 0; j < matrix->columns; j++) {
    matrix->matrix[row_index][j] -= multiplier * matrix->matrix[pivot][j];
  }
}
