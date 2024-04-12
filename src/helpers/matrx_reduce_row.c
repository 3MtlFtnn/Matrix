#include "../s21_matrix.h"

int matrix_reduce_row(matrix_t *matrix) {
  int pivot, row_index;
  for (pivot = 0; pivot < matrix->rows; pivot++) {

    if ((matrix->matrix[pivot][pivot] != 1) &&
        (matrix->matrix[pivot][pivot] != 0)) {
      matrix_divide_row(matrix, pivot);
    }

    for (row_index = pivot + 1; row_index < matrix->rows; row_index++) {
      if (matrix->matrix[pivot][pivot] != 0) {
        matrix_carry_row(NULL, matrix, pivot, row_index);
      }
    }

    for (row_index = pivot - 1; row_index >= 0; row_index--) {
      if (matrix->matrix[pivot][pivot] != 0) {
        matrix_carry_row(NULL, matrix, pivot, row_index);
      }
    }
  }

  return SUCCESS;
}
