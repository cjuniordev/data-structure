#include <stdio.h>
#include <stdlib.h>

int matriz(int *m, int qt_row, int qt_col, int row, int col);

int main(){
    int col = 3, row = 3;
    int len = (col * row);
    int *m = calloc(len, sizeof(int));

    if(m == NULL){
        printf("Matriz não foi alocada corretamente!");
        exit(0);
    }

    for(int i=1; i <= len; i++){
        m[i-1] = i;
    }

    printf("Vetor:\n");
    for(int i=0; i < len; i++){
        printf("%d ", m[i]);
    }

    int continua = 1;

    while (continua){
        printf("\n\nMatriz:\n");
        for (int i=0; i < row; i++){
            for(int j=0; j < col; j++){
                int v = matriz(m, row, col, i+1, j+1);
                printf("%d ", m[v]);
            }
            printf("\n");
        }
        int l, c;
        printf("Qual linha? ");
        scanf("%d", &l);
        printf("Qual coluna? ");
        scanf("%d", &c);

        int pos = matriz(m, row, col, l, c);
        printf("m[%d][%d] = %d\n\n", l, c, m[pos]);

        printf("Continuar?: 1 - sim | 0 - nao ");
        scanf("%d", &continua);
    }

    free(m);

    return 0;
}

int matriz(int *m, int qt_row, int qt_col, int row, int col){
    // calcula quantos itens tem que passar para chegar ao fim da linha
    // a quantidade de colunas é a quantidade de itens que tem em cada linha, logo,
    // quantidade de colunas vezes a quantidade de linhas é o o ultimo elemento da linha +1
    int aux_row = (qt_col * row) -1;
    // calcula a quantidade de itens que tenho q andar a partir do ultimo elemento da linha
    // para encontrar a coluna desejada
    int aux_col = qt_col - col;
    // pega o ultimo elemento da linha desejada e subtrai a quantidade de itens que preciso para encontrar a coluna
    int pos = aux_row - aux_col;

    return pos;
}