/*Seja um arranjo composto por números inteiros, podendo ser positivos e/ou negativos. A subsequência máxima é aquela que tem o maior valor de 
soma entre todos os os seus elementos.


Implemente, utilizando a estratégia divisão-e-conquista, uma função que retorne o somatório da subsequência máxima.

Input Format

Na primeira linha deve ser lido um número inteiro (n).

Na segunda linha deve ser lida um vetor de números inteiros de tamanho n.

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<limits.h>

int sub_arranjo(int *v, int ini, int meio, int fim) {
    int soma = 0;
    int soma_esq = INT_MIN;
    for (int i = meio; i >= ini; i--) {
        soma += v[i];
        if (soma > soma_esq)
            soma_esq = soma;
    }

    soma = 0;
    int soma_dir = INT_MIN;
    for (int i = meio + 1; i <= fim; i++) {
        soma += v[i];
        if (soma > soma_dir)
            soma_dir = soma;
    }
    
    soma=soma_dir+soma_esq;
    
    if(soma_esq>=soma_dir && soma_esq>=soma)
           return soma_esq;
       else if(soma_dir>=soma_esq && soma_dir>=soma)
           return soma_dir;
       else
           return soma;
}

int maior_sub_arranjo(int *v, int ini, int fim) {
    if (ini == fim)
        return v[ini];

    int meio = (ini + fim) / 2;
    int soma_esq, soma_dir, soma;
    
       soma_esq = maior_sub_arranjo(v,ini,meio);
       soma_dir = maior_sub_arranjo(v,meio+1,fim);
       soma=sub_arranjo(v,ini,meio,fim);
       
       if(soma_esq>=soma_dir && soma_esq>=soma)
           return soma_esq;
       else if(soma_dir>=soma_esq && soma_dir>=soma)
           return soma_dir;
       else
           return soma;
}

int main() {
    int n,*v;
    
    scanf("%d",&n);
    v=malloc(sizeof(int)*n);
    
    for(int i =0 ; i<n ; i++)
        scanf("%d",&v[i]);
    
    printf("%d",maior_sub_arranjo(v,0,n-1));
       
    return 0;
}