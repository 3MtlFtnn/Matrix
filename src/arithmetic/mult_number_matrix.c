#include "../s21_matrix.h"

/* Умножает матрицу А на скаляр number и помещает результат в *result
 *
 *  параметры:
 *  matrix_t *A - матрица 1
 *  double number - скаляр
 *  matrix_t *result - результат умножение
 *
 *  возвращает:
 *  0 - ОК
 *  2 - Ошибка вычислений (несовпадающие матрицы, неверный тип матрицы)
 *
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  /* !(если матрица A существует и матрица result существует) */
  if (!((A == NULL) && (result == NULL))) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  } else {
    return CALC_ERR;
  }
  return SUCCESS;
}
