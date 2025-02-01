/*O Sr. Alcídes está trabalhando em uma mina para extrair o máximo que consegue de diamantes "<>". 
Ele deve excluir todas as particulas de areia "." do processo e a cada retirada de diamante, 
novos diamantes poderão ser encontrados. Se ele tem como uma entrada .<...<<..>>....>....>>>., 
três diamantes são formados: "O primeiro é retirado de "<..>", "<>" e "<.......>". 
Implemente uma função que receba uma string representado a carga com areia e diamante. A função deverá retornar a quantidade de diamantes contidas na carga. 
Para a solução do problema, deve ser utilizada uma pilha estática.

Para a implementação do exercício, utilize um TAD de pilhas estáticas, podendo ser um dos códigos que foi apresentado em aula.

Input Format

Deve ser lido um valor inteiro N que representa a quantidade de casos de teste. Cada linha a seguir é uma string que contém apenas os seguintes caracteres: "<", ">" e ".".

Constraints

Os elementos da pilha podem ser manipulados apenas utilizando funções de empilhar e desempilhar.

Output Format

A quantidade de diamantes possíveis de serem extraídos em cada caso de entrada deve ser impressa.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<limits.h>

#define TAM_MAX 100

typedef struct Pilha Pilha;

struct Pilha{
    int item[TAM_MAX];
    int topo;
};

Pilha* criar_pilha(){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));

    p->topo = -1;

    return p;
}
int pilha_cheia(Pilha *p){
    if (p == NULL)
        return -1;
    else if (p->topo >= (TAM_MAX - 1))
        return 1;
    else
        return 0;
}

int empilhar(Pilha *p, int item){
    if (p == NULL)
        p = criar_pilha();

    if (!pilha_cheia(p)){
        p->topo++;

        p->item[p->topo] = item;

        return 1;
    }

    return 0;
}
int pilha_vazia(Pilha *p){
    if (p == NULL)
        return -1;
    else if (p->topo < 0)
        return 1;
    else
        return 0;
}

int desempilhar(Pilha *p){
    int item = INT_MIN;

    if (!pilha_vazia(p)){
        item = p->item[p->topo];

        p->topo--;
    }

    return item;
}


void imprimir_pilha(Pilha *p){
    Pilha aux = *p;
    int item;

    while (!pilha_vazia(&aux)){
        item = desempilhar(&aux);

        printf("%d\n", item);
    }
}

void liberar_pilha(Pilha *p){
    if (p != NULL)
        free(p);
}


int minecraft(char *picareta){
    int i,cont=0;
    Pilha *p=criar_pilha();
    
    for(i=0;i<strlen(picareta);i++){
        if(picareta[i]=='<')
            empilhar(p,picareta[i]);

        if(picareta[i]=='>' && !pilha_vazia(p)){
            desempilhar(p);
            cont++;
        }
    }
 
    return cont;
    
}

int main(){
    int n,i;
    char str[TAM_MAX];
    Pilha *p=criar_pilha(),*b=criar_pilha();
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%s",str);
        empilhar(p,minecraft(str));
    }
    
    for(i=n-1;i>=0;i--)
        empilhar(b,p->item[i]);

    imprimir_pilha(b);
    
    liberar_pilha(p);
    liberar_pilha(b);
    
    return 0;
}