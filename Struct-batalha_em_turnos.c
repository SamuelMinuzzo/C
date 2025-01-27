/*Gladstone está desenvolvendo um jogo simples de RPG em que há batalhas, os quais são por turnos, onde, em cada luta, 
os jogadores se revezam em cada ataque. Cada personagem, além do nome (string), tem os seguintes atributos representados por números inteiros: 
energia, defesa e força. Em cada ataque, a energia do personagem que está sofrendo o golpe é reduzida. O dano (redução de energia) 
é dado pela subtração entre o atributo de força (F) do atacante e o atributo de defesa do personagem atacado, o qual pode ter redução de energia. 
Caso a diferença entre força (atacante) e defesa (atacado) seja menor igual a zero, o dano será de 1 ponto. Se o dano resultar em energia negativa, 
o valor da mesma para o personagem derrotado deverá ser "0". Em cada batalha, o perdedor será o personagem que tiver a energia zerada ou que tiver o 
menor valor de energia. Também, poderá ocorrer empate. É importante ressaltar que o personagem com energia zerada não pode mais atacar!

Implemente uma função que receba duas variáveis referentes aos personagens e um número inteiro que represente a quantidade de turnos, 
onde o primeiro personagem fornecido como parâmetro começa o ataque. Ao final, a função deverá imprimir o resultado, indicando o nome personagem vencedor ou se houve empate.

Input Format

Nas duas primeiras linhas, devem ler lidos os dados dos personagens. "nome (vetor de char) energia (int) defesa (int), força (int)".

Na linha seguinte, deve ser lida a quantidade de rodadas que deverá ter a batalha.

Constraints

.

Output Format

Na primeira e segunda linha, imprimir o nome e a energia restante do primeiro e do segundo personagem, após a execução das rodadas de ataques.

Na terceira lunha, imprimir o nome do personagem vencedor ou "empate", caso os personagens tiverem a mesma quantidade de energia 
(neste exercício não levando em conta que os personagens possam iniciar uma batalha com diferentes valores de energia). */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int energia,defesa,forca;
} Personagem;

void Combate(Personagem a, Personagem b, int turno)
{
    int danoA,danoB,i;

    danoA = a.forca - b.defesa;
    danoB = b.forca - a.defesa;

    if(danoA<=0 )
        danoA=1;

    if(danoB<=0)
        danoB=1;

    for(i=0; i<turno; i++)
    {
        b.energia=b.energia - danoA;
        if(b.energia<=0 || a.energia<=0)
            break;

        a.energia=a.energia - danoB;
    }

    if(a.energia<0)
        a.energia=0;

    if(b.energia<0)
        b.energia=0;

    printf("%s %d\n",a.nome,a.energia);
    printf("%s %d\n",b.nome,b.energia);


    if(a.energia>b.energia)
        printf("%s\n",a.nome);
    
    if( b.energia>a.energia)
        printf("%s\n",b.nome);

    else if(b.energia==a.energia)
        printf("empate");

}

int main()
{
    Personagem a,b;
    int turno;

    scanf("%s""%d""%d""%d",&a.nome,&a.energia,&a.defesa,&a.forca);
    scanf("%s""%d""%d""%d",&b.nome,&b.energia,&b.defesa,&b.forca);
    scanf("%d",&turno);

    Combate(a,b,turno);

    return 0;
}