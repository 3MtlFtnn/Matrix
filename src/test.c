#include "s21_matrix.h"
#include <stdio.h>

int main() {
  printf("Создание матрицы 3x3:\n");
  matrix_t result1 = malloc(sizeof());
  matrix_t result3;
  int error1 = s21_create_matrix(3, 3, &result1);
  int error3 = s21_create_matrix(3, 3, &result3);
  printf("Код ошибки создания матрицы 1: %d\n", error1);
  printf("Код ошибки создания матрицы 3: %d\n", error3);

  if (error1 == SUCCESS && error3 == SUCCESS) {
    matrix_filler_random(&result1);
    printf("Матрица 1:\n");
    matrix_print(&result1);

    double determinant;
    int sub_flag = s21_determinant(&result1, &determinant);
    printf("Результат вычисления определителя: ");
    if (sub_flag == SUCCESS) {
      printf("%lf\n", determinant);
    } else {
      printf("Не удалось вычислить определитель\n");
    }

    printf("Результат-матрица (не изменяется при вычислении определителя):\n");
    matrix_print(&result3);

    s21_remove_matrix(result1);
    s21_remove_matrix(result3);
  } else {
    printf("Не удалось создать матрицу\n");
  }

  return 0;
}
