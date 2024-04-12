#include "../s21_matrix.h"

int matrix_copy(matrix_t *source, matrix_t *destination) {
  int return_flag = SUCCESS;

  if (!(source->columns != destination->columns) &&
      (source->rows != destination->columns)) {
    for (int i = 0; i < source->rows; i++) {
      for (int j = 0; j < source->columns; j++) {
        destination->matrix[i][j] = source->matrix[i][j];
      }
    }
  } else {
    return_flag = FAILURE;
  }

  return return_flag;
}
