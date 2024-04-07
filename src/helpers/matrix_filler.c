#include "../s21_matrix.h"
#include <stdio.h>

/* Забивает матрицу A случайными double-числами.
 *
 *  параметры:
 *  matrix_t *A - матрица, в которую помещаются значения.
 *
 *  возвращает:
 *  0 - ОК
 *  1 - Ошибка, матрица не существует
 *
 */
int matrix_filler(matrix_t *A) {
  if (!(A == NULL)) {
    int i, j;

    printf("Введите значения матрицы:\n");
    for (i = 0; i < A->rows; i++) {
      for (j = 0; j < A->columns; j++) {
        scanf("%lf", &A->matrix[i][j]);
      }
    }

    return SUCCESS;
  } else {
    return FAILURE;
  }
}
