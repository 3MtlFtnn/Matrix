#include "../s21_matrix.h"

/* Создает матрицу columnsXrows и помещает ее в *result
 *
 *  параметры:
 *  int rows - количество строк
 *  int columns - количество столбцов
 *
 *  возвращает:
 *  0 - ОК
 *  1 - Ошибка, некорректная матрица
 *  2 - Ошибка вычислений (несовпадающие матрицы, неверный тип матрицы)
 *
 */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (!((rows == 0) && (columns == 0))) {
    result->columns = columns;
    result->rows = rows;
    result->matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)malloc(columns * sizeof(double));
    }
    return SUCCESS;
  } else {
    return FAILURE;
  }
}
