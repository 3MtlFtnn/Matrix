#include "s21_matrix.h"
#include <stdio.h>

int main() {
  printf("Создание матрицы 3x3:\n");
  matrix_t *result1 = malloc(sizeof(double **));
  matrix_t *result3 = malloc(sizeof(double **));
  int error1 = s21_create_matrix(3, 3, result1);
  int error3 = s21_create_matrix(3, 3, result3);
  printf("%d\n", error1);
  printf("%d\n", error3);

  matrix_filler_random(result1);
  printf("Матрица 1: \n");
  matrix_print(result1);

  int sub_flag = s21_transpose(result1, result3);
  printf("результат: %d\n", sub_flag);
  printf("результат-матрица:\n");
  matrix_print(result3);

  s21_remove_matrix(result1);
  s21_remove_matrix(result3);
  return 0;
}
