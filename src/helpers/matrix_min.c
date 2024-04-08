#include "../s21_matrix.h"
#include <stdio.h>
// i -строка; j - столбец
int matrix_min(matrix_t *A, matrix_t *result, int row, int col) {
  if (A != NULL) {
    for (int i = A->rows; i <= A->rows; i++) {
      int min_row = i;
      if (i > row) {
        min_row--;
      }
      for (int j = A->columns; j <= A->columns; j++) {
        int min_col = j;
        if (j > col) {
          min_col--;
        }
        if (i != row && j != col) {
          result->matrix[min_row][min_col] = A->matrix[i][j];
        }
      }
    }
  } else {
    return FAILURE;
  }
  return SUCCESS;
}
