#include "../s21_matrix.h"

/* Транспонирует матрицу *A и помещает результат в *result
 *
 *  параметры:
 *  matrix_t *A - матрица 1
 *  matrix_t *result - результат транспозиции
 *
 *  возвращает:
 *  0 - ОК
 *  1 - Ошибка, некорректная матрица
 *  2 - Ошибка вычислений (несовпадающие матрицы, неверный тип матрицы)
 *
 */
int s21_transpose(matrix_t *A, matrix_t *result) {
  /* !(если матрица A существует и матрица result существует) */
  if (A == NULL || (A->columns != A->rows) || (result == NULL) || (result->columns != result->rows)) {
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  } else {
    return CALC_ERR;
  }
  return SUCCESS;
}
