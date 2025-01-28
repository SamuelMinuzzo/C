/*Implemente um programa que faça o controle do consumo de energia dos eletrodomésticos de um imóvel. 
Primeiro leia os N eletrodomésticos que contendo nome, potência (inteiro, em kW) e tempo ativo por dia (real, em horas). Em seguida, 
leia um número inteiro d (quantidade de dias) e calcule:

O consumo total no imovel

O consumo total de cada eletrodoméstico

O consumo relativo de cada eletrodoméstico ((consumo/consumo total) * 100) nesse período de tempo.

Input Format

Na primeira linha deve ser lido o número de eletrodoméstico.

Para cada uma das N linhas seguintes, leia as seguintes informações para cada eletrodoméstico: nome (string), potencia (inteiro) e tempo (real).

Por fim, leia um número inteiro que represente a quantidade de dias.

Constraints

Não utize a função gets para ler as strings. Em vez disso, use scanf (nos casos de teste não há o caractere espaço em branco)

Output Format

A primeira linha deve exibir o consumo total no imóvel seguido de N linhas com o consumo relativo de cada eletrodoméstico.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int potencia;
    float tempo;
}Eletrodomestico;

int main(){

    int eletro,i,dias;
    scanf("%d",&eletro);
    float total=0;

    Eletrodomestico a[eletro];

    for(i=0;i<eletro;i++)
    {
        scanf("%s",&a[i].nome);
        scanf("%d",&a[i].potencia);
        scanf("%f",&a[i].tempo);
    }
    scanf("%d",&dias);

    for(i=0;i<eletro;i++)
    {
        total=total + a[i].potencia*a[i].tempo*dias;
    }
    printf("%.0f\n",total);

    for(i=0;i<eletro;i++)
    {
        printf("%s %.1f\n",a[i].nome,((a[i].potencia*a[i].tempo*dias/total)*100));
    }
    
    return 0;
}
