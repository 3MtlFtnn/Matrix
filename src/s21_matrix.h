#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <stdlib.h>

#define SUCCESS 0
#define FAILURE 1
#define CALC_ERR 2

#define COMP_SUCCESS 1
#define COMP_FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// Создание и удаление
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

// Сравнение
int s21_eq_matrix(matrix_t *A, matrix_t *B);

// Арифметические операции
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
/* умножение скалярного числа (number) */
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
/* умножение матриц */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Другие операции
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// Вспомогательные функции
int matrix_print(matrix_t *A);
int matrix_filler(matrix_t *A);
int matrix_filler_random(matrix_t *A);
void matrix_min(double **A, double **result, int minrow, int mincol, int size);
double matrix_determ(matrix_t *A, int size);
double randfrom(double min, double max);
#endif
