#include "../s21_matrix.h"
#include <stdio.h>

/* Умножает матрицу А на матрицу B и помещает результат в *result
 *
 *  параметры:
 *  matrix_t *A - матрица 1
 *  matrix_t *B - матрица 2
 *  matrix_t *result - результат умножение
 *
 *  возвращает:
 *  0 - ОК
 *  1 - Ошибка, некорректная матрица
 *  2 - Ошибка вычислений (несовпадающие матрицы, неверный тип матрицы)
 *
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  /* !(если матрица A существует и матрица B существует) */
  if (!((A == NULL) && (B == NULL) && (result == NULL))) {
    if (!(A->rows != B->columns)) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          for (int k = 0; k < B->rows; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][i];
          }
        }
      }
    } else {
      return CALC_ERR;
    }
  } else {
    return FAILURE;
  }

  return SUCCESS;
}
