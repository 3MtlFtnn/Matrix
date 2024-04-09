#include "../s21_matrix.h"
#include <time.h>

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
int matrix_filler_random(matrix_t *A) {
  if (!(A == NULL)) {
    srand(time(NULL));

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        A->matrix[i][j] = randfrom(1, 2);
      }
    }
    return SUCCESS;
  } else {
    return FAILURE;
  }
}

// Создает случайный double в заданном диапазоне
double randfrom(double min, double max) {
  double range = (max - min);
  double div = RAND_MAX / range; // из stdlib.h: RAND_MAX	0x7fffffff
  return min + (rand() / div);
}
