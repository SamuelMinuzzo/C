/*Escreva uma função que receba três variáveis (altura, largura e comprimento) do tipo float para a representação de um paralelepípedo reto e três ponteiros do tipo float. 
Nessa função, cada ponteiro deverá armazenar uma medida relacionada ao palalepípedo, como:

área = 2 * (altura * largura + altura * comprimento + largura * comprimento)

volume = altura * largura * comprimento

comprimento da diagonal = sqrt(altura^2 + largura^2 + comprimento^2)

Input Format

Ler três variáveis do tipo float.

Constraints

A impressão dos floats deve considerar apenas uma casa decimal.

Output Format

Em cada linha, imprimir o conteúdo de um ponteiro seguido o seguinte padrão:

"area: valor"

"volume: valor"

"comprimento da diagonal: valor"*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void Paralelepipedo (float altura, float largura, float comprimento,float *p1, float *p2, float *p3)
{

    *p1=2*altura*largura+2*altura*comprimento+2*largura*comprimento;
    *p2=altura*largura*comprimento;
    *p3=sqrt((altura*altura)+(largura*largura)+(comprimento*comprimento));
}


int main(){

    float alt, larg,comp,area,volume,diagonal;

    scanf("%f %f %f",&alt,&larg,&comp);

    Paralelepipedo(alt,larg,comp,&area,&volume,&diagonal);
    
    printf("area: %.1f\n",area);
    printf("volume: %.1f\n",volume);
    printf("comprimento da diagonal: %.1f",diagonal);

    return 0;
}

