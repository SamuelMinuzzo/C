/*Implemente uma função que receba duas listas estáticas (l1, l2). A função deverá retornar a posição lista l2 dentro de l1. 
Caso a lista l2 não estiver na l1, retornar "-1".

Exemplo:

l1 = {1, 2, 3, 4, 5, 6, 7,** 8, 7, 6, 8**, 9, 10}

l2 = {8, 7, 6, 8}

No exemplo acima, l2 está (inicia) na posição 7 da lista l2.

Para a implementação do exercício, utilize um TAD de listas estáticas, podendo ser o código que foi apresentado em aula.

Input Format

Na primeira linha, enquanto "-1" não for lido, ler números inteiros. Na segunda linha, a mesma restrição da primeira linha deve ser aplicada.

Constraints

.

Output Format

Imprimir a posição da lista l2 na l1.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Lista Lista;

struct Lista{
    int item[MAX_SIZE];
    int tam;
};


Lista* criar_lista(){
    Lista *l = (Lista*) malloc(sizeof(Lista));

    l->tam = 0;

    return l;
}


int lista_vazia(Lista *l){
    return (l == NULL) || (l->tam == 0);
}


int lista_cheia(Lista *l){
    return (l != NULL) && (l->tam == MAX_SIZE);
}


int buscar(Lista *l, int chave){
    int i;

    if (!lista_vazia(l)){
        for (i = 0; i < l->tam; i++)
            if (l->item[i] == chave)
                return i;
    }

    return -1;
}

int inserir(Lista *l, int chave){
    if (!lista_cheia(l)){
        l->item[l->tam] = chave;

        l->tam++;

        return 1;
    }

 
    return 0;
}

int remover(Lista *l, int chave){
    int i, p = buscar(l, chave);

    if (p > -1){
        for (i = p; i < l->tam - 1; i++)
            l->item[i] = l->item[i + 1];

        l->tam--;

        return 1;
    }

    return 0;
}


void imprimir_lista(Lista *l){
    int i;

    if (!lista_vazia(l)){
        for (i = 0; i < l->tam; i++)
            printf("%d ", l->item[i]);

        printf("\n");
    }
}

int sub_lista(Lista *l1, Lista *l2){
   int i,j,k=0;
    
    for(i=0 ; i<l1->tam; i++){
        j=i;
            if(l1->item[j]==l2->item[k]){
                 while((l1->item[j]==l2->item[k]) && j<l1->tam)
                    j++, k++;
            }
         if(k==l2->tam)
            return i;
        
        j=0;
        k=0;
    }
    
    return -1;
    
}

int main() {
    int aux=0;
    Lista *l1 = criar_lista(), *l2 = criar_lista();
    
    while(aux != -1){
        scanf("%d",&aux);
        
        if(aux!= -1)
            inserir(l1,aux);
    }
    aux=0;
    while(aux != -1){
        scanf("%d",&aux);
        
        if(aux!= -1)
            inserir(l2,aux);
    }
    
    printf("%d",sub_lista(l1,l2));
    
    
    free(l1);
    free(l2);
    
    return 0;
}
