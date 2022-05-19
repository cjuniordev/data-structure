#include <stdio.h>
#include <stdlib.h>

int matriz(int *m, int qt_row, int qt_col, int row, int col);

int main(){
    int col = 3, row = 3;

    // cria matriz
    int **m = calloc(row, sizeof(int));

    if(m == NULL){
        printf("Matriz não foi alocada corretamente!");
        exit(0);
    }

    for(int i=1; i <= row; i++){
        m[i-1] = calloc(col, sizeof(int));
        if(m[i-1] == NULL){
            printf("Matriz não foi alocada corretamente!");
            exit(0);
        }
    }

    // imprime matriz
    for (int i=0; i < row; i++){
        for(int j=0; j < col; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    // libera matriz
    for(int i=0; i < row; i++){
        free(m[i]);
    }
    free(m);

    return 0;
}