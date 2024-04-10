#include "../s21_matrix.h"
#include <stdio.h>
/*
    Вспомогательная функция для расчета минора матрицы

    Параметры:
    A - исходная матрица
    result - матрица обработанная
    minrow - строка, которая будет вырезана
    mincol - столбец, который будет вырезан
    size - размер матрицы (так как минор высчитывается для квадратной матрицы,
    то в качестве параметра можно передать длинну строки или столбца)

*/
void matrix_minor(matrix_t *A, matrix_t *result, int minrow, int mincol, int size) {
    for(int row = 0, x = 0; row<size;row++){
        for(int col = 0, y = 0; col < size; col++){
            if(row!=minrow && col!=mincol){
                result->matrix[x][y++] = A->matrix[row][col];
                if(y == size - 1){
                    y = 0;
                    x++;
                }
            }
        }
    }
}
