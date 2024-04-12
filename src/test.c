#include "s21_matrix.h"
#include <stdio.h>

int main() {
  printf("Создание матрицы 3x3:\n");
  matrix_t *result1 = malloc(sizeof(double **));
  int error1 = s21_create_matrix(3, 3, result1);
  matrix_t *result2 = malloc(sizeof(double **));
  int error2 = s21_create_matrix(3, 3, result2);
  printf("%d\n", error1);

  matrix_filler_random(result1);
  printf("Матрица 1: \n");
  matrix_print(result1);

  printf("\n");

  int sub_flag = s21_inverse_matrix(result1, result2);
  printf("результат: %d\n", sub_flag);
  printf("Матрица 2: \n");
  matrix_print(result2);
  s21_remove_matrix(result1);
  s21_remove_matrix(result2);
  return 0;
}
