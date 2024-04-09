#include "s21_matrix.h"
#include <stdio.h>

int main() {
    printf("Создание матрицы 3x3:\n");
    matrix_t *result1 = malloc(sizeof(double **));
    int error1 = s21_create_matrix(4,4, result1);
    printf("%d\n", error1);

    matrix_filler_random(result1);
    printf("Матрица 1: \n");
    matrix_print(result1);

    printf("\n");

    double determ = 0.0;
    int sub_flag = s21_determinant(result1,&determ);
    printf("результат: %d\n", sub_flag);
    printf("Ответ пон: %f\n",determ);
    printf("результат-матрица:\n");
    matrix_print(result1);

    s21_remove_matrix(result1);
    return 0;
}
