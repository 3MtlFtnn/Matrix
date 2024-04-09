#include "../s21_matrix.h"
#include <stdio.h>
void matrix_min(double **A, double **result, int minrow, int mincol, int size) {
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
