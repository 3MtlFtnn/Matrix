#include "../s21_matrix.h"
#include <stdio.h>

/* Выводит матрицу построчно
 *
 *  параметры:
 *  matrix_t *A - матрица, которую надо вывести.
 *
 *  возвращает:
 *  0 - ОК
 *  1 - Ошибка, матрица не существует
 *
 */
int matrix_print(matrix_t *A) {
  if (!(A == NULL)) {

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        printf("%lf\t\t", A->matrix[i][j]);
      }
      printf("\n");
    }
    return SUCCESS;
  } else {
    return FAILURE;
  }
}
