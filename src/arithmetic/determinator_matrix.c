#include "../s21_matrix.h"

#include <stdio.h>
int s21_determinant(matrix_t *A, double *result) {

  if (A->columns != A->rows) return FAILURE;

  if (A->rows == 1)
    *result = A->matrix[0][0];
  else
    *result = matrix_determ(A, A->rows);

  return SUCCESS;
}
