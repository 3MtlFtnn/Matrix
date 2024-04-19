#include "s21_matrix.h"
#include <stdio.h>

int main() {
  printf("Создание матрицы 3x3:\n");
  matrix_t *result = malloc(sizeof(double **));
  int error1 = s21_create_matrix(3, 3, result);
  printf("Return value: %d\n", error1);

  int sub_flag = s21_calc_complements(result, NULL);
  printf("результат: %d\n", sub_flag);

  s21_remove_matrix(result);
  return 0;
}
