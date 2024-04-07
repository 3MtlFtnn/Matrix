#include "../s21_matrix.h"

/* Вычитает из матрицы А матрицу B и помещает результат в *result
 *
 *  параметры:
 *  matrix_t *A - матрица 1
 *  matrix_t *A - матрица 2
 *  matrix_t *result - результат вычитания
 *
 *  возвращает:
 *  0 - ОК
 *  1 - Ошибка, некорректная матрица
 *  2 - Ошибка вычислений (несовпадающие матрицы, неверный тип матрицы)
 *
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  /* !(если матрица A существует и матрица B существует) */
  if (!((A == NULL) && (B == NULL) && (result == NULL))) {
    /* !(если результат сравнения матриц A и B не равен COMP_SUCCESS) */
    if (!((A->columns != B->columns) && (A->rows != B->rows))) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
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
