#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Cell Cell;

typedef struct PilhaE PilhaE;

struct Cell{
    int item;
    Cell *next;
};


struct PilhaE{
    Cell *topo;
};


Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}


PilhaE* criar_pilhaE(){
    PilhaE* p = (PilhaE*) malloc(sizeof(PilhaE));

    p->topo = NULL;

    return p;
}


int pilhaE_vazia(PilhaE *p){
    return (p == NULL) || (p->topo == NULL);
}


void empilhar(int key, PilhaE *p){
    Cell *aux;

    if (p == NULL)
        p = criar_pilhaE();

    aux = criar_celula(key);

    aux->next = p->topo;

    p->topo = aux;
}


char desempilhar(PilhaE *p){
    Cell *aux;
    int item = INT_MIN;

    if (!pilhaE_vazia(p)){
        aux = p->topo;
        
        item = aux->item;

        p->topo = aux->next;

        free(aux);
    }

    return item;
}

int acessar_valor_topo(PilhaE *p){
    if (!pilhaE_vazia(p))
        return p->topo->item;
    else
        return INT_MIN;
}


void imprimir_pilha(PilhaE *p){
    Cell *aux;

    if (!pilhaE_vazia(p)){
        aux = p->topo;

        while (aux != NULL){
            
            (aux->item <= 9) ? printf("%d", aux->item): printf("%c",aux->item);

            aux = aux->next;
        }
    }
}


int liberar_pilha(PilhaE *p){
    if (p != NULL){
        while (!pilhaE_vazia(p))
            desempilhar(p);

        free(p);

        return 1;
    }

    return 0;
}

PilhaE* base(int n, int b){
    int resto;
    PilhaE *p = criar_pilhaE();
    
    while(n>=b){
        resto = n % b;
        n = n/b;
        if(resto>9){
            if(resto==10)
                empilhar('a',p);
            if(resto==11)
                empilhar('b',p);
            if(resto==12)
                empilhar('c',p);
            if(resto==13)
                empilhar('d',p);
            if(resto==14)
                empilhar('e',p);
            if(resto==15)
                empilhar('f',p);
        }else  
            empilhar(resto, p);
    }
       empilhar(n,p);
    
    return p;
}
int main() {
    int n,b;
    PilhaE *p = criar_pilhaE();
    
    scanf("%d %d",&n,&b);
    
    p = base(n,b);
    
    imprimir_pilha(p);
    
    liberar_pilha(p);
    
    return 0;
}
