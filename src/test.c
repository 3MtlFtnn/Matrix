#include "s21_matrix.h"
#include <stdio.h>

int main() {
    printf("Создание матрицы 3x3:\n");
    matrix_t *result1 = malloc(sizeof(double **));
    int error1 = s21_create_matrix(3,3, result1);
    printf("%d\n", error1);

    int sub_flag = s21_calc_complements(result1, NULL);
    printf("результат: %d\n", sub_flag);

    s21_remove_matrix(result1);
    return 0;
}
