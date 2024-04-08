#include "s21_matrix.h"
#include <stdio.h>
/*
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
  s21_calc_complements(result1, result3);

  matrix_min(a, result3, 1, 1, 3);
  printf("результат-матрица:\n");
  matrix_print(result3);

  s21_remove_matrix(result1);
  s21_remove_matrix(result3);
  return 0;
}
*/

void matrix_min(double **A, double **result, int minrow, int mincol, int size);
void print_matrix(double **matrix, int rows, int cols);

int main() {
  int size = 3;
  double **A = (double **)malloc(size * sizeof(double *));
  for (int i = 0; i < size; i++) {
    A[i] = (double *)malloc(size * sizeof(double));
  }

  double **result = (double **)malloc((size - 1) * sizeof(double *));
  for (int i = 0; i < size - 1; i++) {
    result[i] = (double *)malloc((size - 1) * sizeof(double));
  }

  // Инициализация матрицы A
  A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
  A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;
  A[2][0] = 7; A[2][1] = 8; A[2][2] = 9;

  int minrow = 1;
  int mincol = 1;

  // Вычисление минора
  matrix_min(A, result, minrow, mincol, size);

  // Вывод исходной матрицы A
  printf("Исходная матрица A:\n");
  print_matrix(A, size, size);

  // Вывод результирующей матрицы (минора)
  printf("\nРезультирующая матрица (минор):\n");
  print_matrix(result, size - 1, size - 1);

  // Освобождение памяти
  for (int i = 0; i < size; i++) {
    free(A[i]);
  }
  free(A);

  for (int i = 0; i < size - 1; i++) {
    free(result[i]);
  }
  free(result);

  return 0;
}

void matrix_min(double **A, double **result, int minrow, int mincol, int size) {
  if (A != NULL) {
    for(int row = 0, x = 0; row<size;row++){
        for(int col = 0, y = 0; col < size; col++){
            if(row!=minrow && col!=mincol){
                result[x][y++] = A[row][col];
                if(y == size - 1){
                    y = 0;
                    x++;
                }
            }
        }
    }
  }
}

void print_matrix(double **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%.2f ", matrix[i][j]);
    }
    printf("\n");
  }
}
