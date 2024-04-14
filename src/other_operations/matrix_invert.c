#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!((A == NULL) && (result == NULL))) {
    if (!(A->rows != A->columns)) {
      double det = 0;
      int status = s21_determinant(A, &det);
      if (fabs(det) < 1e-6 || status != SUCCESS)
        return CALC_ERR;
      matrix_t *temp = malloc(sizeof(double **));
      matrix_t *temp_transpose = malloc(sizeof(double **));

      s21_create_matrix(A->rows, A->columns, temp);
      s21_create_matrix(A->rows, A->columns, temp_transpose);

      s21_calc_complements(A, temp);
      s21_transpose(temp, temp_transpose);

      for (int x = 0; x < A->rows; x += 1) {
        for (int y = 0; y < A->rows; y += 1) {
          result->matrix[x][y] = temp_transpose->matrix[x][y] / det;
        }
      }

      s21_remove_matrix(temp_transpose);
      s21_remove_matrix(temp);
    }
  } else {
    return CALC_ERR;
  }

  return SUCCESS;
}
