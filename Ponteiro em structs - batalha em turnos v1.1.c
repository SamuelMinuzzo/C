/*Após ter o protótipo de jogo de RPG aprovado pelo CEO de uma importante empresa de games, Gladstone decide fazer melhorias na jogabilidade. 
Dessa vez o jogo deverá ter mais recursos. Consequentemente, a estrutura de cada personagem deve ter os seguintes campos: nome, energia, defesa, 
força e três golpes diferentes (A1, A2, A3), sendo cada um com um valor diferente. Após a execução de um golpe, o dano é dado pela seguinte equação:

dano = força_atacante + golpe_atacante - defeesa_atacado

Caso o valor da equação acima for negativo, o dano será de 1 ponto apenas. Em cada batalha, 
o perdedor será o personagem que tiver a energia zerada ou que tiver o menor valor de energia. Também, poderá ocorrer empate. 
É importante ressaltar que o personagem com energia zerada não pode mais atacar!

O jogo também tem mais novidades novidades: o personagem, em vez de atacar, pode tomar uma poção de cura, que restaura 200 pontos; 
quem inicia o ataque não é necessariamente o primeiro personagem; o valor máximo de energia é 1000 (personagem completamente saudável).

Implemente funções para o gerenciamento de batalha entre dois personagens. Para isso, devem ser utilizados ponteiros de structs. Exemplo de protótipos:

void reduzir_energia(Tipo *p, int pontos_dano); // reduz pontos_dano pontos na saúde do personagem (valor mínimo de saúde: 0)

void restaurar(Tipo *p); // aumenta 200 pontos na saúde do personagem (valor máximo de saúde: 1000)

Input Format

Nas duas primeiras linhas, devem ler lidos os dados dos personagens. Cada uma das duas primeiras linhas tem a seguinte seguência:
 "nome (vetor de char) energia (int) defesa (int), força (int), ataque 1 (int), ataque 2 (int), ataque 3 (int)""

Na linha seguinte, deve ser lida a quantidade de ações (N) que deverá ter a batalha.

A leitura das próximas N linhas devem ser no formato: "P A" (o personagem toma uma poção de cura) ou P A G (o personagem realiza um ataque), onde:

P: do tipo inteiro, representa o personagem que executa a ação. O valor pode ser 1 (primeiro persongem lido) ou 2

A: é um caractere que representa uma ação, que pode ser "C" (cura) ou "A" ataque.

Caso a ação representada pelo caractere "A", ainda deverá ser definido qual dos 3 três golpes possíveis deve ser executado, ou seja, o valor deve ser 1, 2 ou 3

Constraints

.

Output Format

Na primeira e segunda linha, imprimir o nome e a energia restante do primeiro e do segundo personagem, após a execução das rodadas de ataques.

Na terceira lunha, imprimir o nome do personagem vencedor ou "empate", caso os personagens tiverem a mesma quantidade de energia 
(neste exercício não levando em conta que os personagens possam iniciar uma batalha com diferentes valores de energia).*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int energia,defesa,forca,atq[3];
}Personagem;

void reduzir_energia(Personagem *p, int pontos_dano){
    p->energia = (pontos_dano>1) ? p->energia-pontos_dano : p->energia - 1;
}

void curar(Personagem *p){
    p->energia = (p->energia+200>1000) ? 1000 : p->energia+200;
}

int main() {

    Personagem a,b,*p1=&a,*p2=&b;
    int turno,i,p,ataq;
    char acao;

    scanf("%s %d %d %d %d %d %d",&a.nome,&a.energia,&a.defesa,&a.forca,&a.atq[0],&a.atq[1],&a.atq[2]);
    scanf("%s %d %d %d %d %d %d",&b.nome,&b.energia,&b.defesa,&b.forca,&b.atq[0],&b.atq[1],&b.atq[2]);
    scanf("%d",&turno);

    for(i=0;i<turno;i++){
        scanf("%d %c",&p,&acao);
        if(acao=='A'){
            scanf("%d",&ataq);
            p==1 ? reduzir_energia(p2,(a.forca+a.atq[ataq-1]-b.defesa)) : reduzir_energia(p1,(b.forca+b.atq[ataq-1]-a.defesa));
        }
        if(acao=='C'){
            p==1 ? curar(p1) : curar(p2);
        }
    }

    printf("%s %d\n",a.nome,a.energia);
    printf("%s %d\n",b.nome,b.energia);

    a.energia==b.energia ? printf("empate"): a.energia>b.energia ? printf("%s",a.nome): printf("%s",b.nome);

    return 0;
}

