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
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!(A->columns != A->rows)) {
    matrix_t *temp = malloc(sizeof(double *));

    int result_flag = s21_create_matrix(A->rows * 2, A->columns * 2, temp);
    if (result_flag != 0) {
      perror("Создание матрицы не удалось");
      return FAILURE;
    }

    matrix_copy(A, temp);

    for (int j = 0; j < temp->rows; j++) {
      for (int k = A->rows; k < temp->columns; k++) {
        if (j + A->rows == k) {
          temp->matrix[j][k] = 1;
        } else {
          temp->matrix[j][k] = 0;
        }
      }
    }

    matrix_reduce_row(temp);

    for (int j = 0; j < temp->rows; j++) {
      for (int k = A->rows; k < temp->columns; k++) {
        A->matrix[j][k - A->rows] = temp->matrix[j][k];
      }
    }

    matrix_copy(temp, result);

    s21_remove_matrix(temp);
  }
  return FAILURE;
}
