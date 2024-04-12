#include "../s21_matrix.h"

int matrix_divide_row(matrix_t *matrix, int pivot) {
  int return_flag = SUCCESS;

  double divisor = matrix->matrix[pivot][pivot];
  double result;

  if (!(matrix->matrix != NULL)) {
    for (int j = 0; j < matrix->columns; j++) {
      result = (matrix->matrix[pivot][j] / divisor);
      matrix->matrix[pivot][j] = result;
    }
  } else {
    return_flag = FAILURE;
  }

  return return_flag;
}
