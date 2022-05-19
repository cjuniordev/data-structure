#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *prox;
} No;

struct no *cria(int a)
{
    No *no = (No*)malloc(sizeof(No));
    if(no == NULL){
        printf("memoria nao alocada com sucesso!!!");
        exit(1);
    }
    no->chave = a;
    no->prox = NULL;

    return no;
}

void insereNoInicio(No **L, No *no){
    // 1. Verificar se a lista é vazia
    // 2. Armazenar a referencia da lista em uma variavel auxiliar
    //    Atribuir o no ao L e atribuir todo o restante da lista em L->prox
    if((*L) == NULL){
         (*L) = no;
    } else{
        No *aux = (*L);
        (*L) = no;
        (*L)->prox = aux;
    }
}

void insereNoFim(No **L, No *no){
    // 1. Verificar se L é vazio
    // 2. Verificar se L->prox é vazio
    // 3. Rodar lista ate é chegar em um nó em que ele nao tem prox e insere o elemento

    No *aux = NULL;

    if((*L) == NULL){
        (*L) = no;
        return;
    }

    if((*L)->prox == NULL){
        (*L)->prox = no;
        return;
    }

    aux = (*L);
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    if(aux->prox == NULL){
        aux->prox = no;
    }
}

void imprimeIterativa(No *L){
    No *aux = NULL;
    aux = (L);
    while(aux != NULL){
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
}

int quantosNosAntecedem(No *L, int c){
    No *aux = NULL;
    int count = 0;
    aux = L;

    while(aux->chave != c){
        if(aux->prox == NULL){
            printf("O elemento procurado não existe!\n");
            return -1;
        }
        count++;
        aux = aux->prox;
    }

    return count;
}

void imprimeRecursiva(No *L){
    if(L == NULL) return;

    printf("%d ", L->chave);

    if(L->prox == NULL) return;
    imprimeRecursiva(L->prox);   
}

void inverte(No **L){
    No *aux = NULL, *L2 = NULL, *temp = NULL;  
    aux = (*L);
    L2 = cria(aux->chave);

    while (aux->prox != NULL){
        temp = cria(aux->prox->chave);
        insereNoInicio(&L2, temp);
        temp = aux;
        aux = aux->prox;
        free(temp);
    }

    (*L) = L2;
}

int main(){
    No *L = NULL;
    No *no1 = NULL;
    No *no2 = NULL;
    No *no3 = NULL;

    no1 = cria(10);
    no2 = cria(11);
    no3 = cria(12);

    insereNoFim(&L, no1);
    insereNoFim(&L, no2);
    insereNoFim(&L, no3);

    imprimeIterativa(L);

    inverte(&L);
    printf("\n");

    imprimeRecursiva(L);

    int r = quantosNosAntecedem(L, 10);
    printf("\nUm total de %d nós antecedem a busca.\n", r);

    return 0;
}
