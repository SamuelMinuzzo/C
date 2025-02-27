/*Implemente o algoritmo de Dijkstra. A função deve receber um grafo representado por uma lista de adjacência e construir uma árvore de caminhos mínimos, 
que deve ser construída a partir do vértice "0".

Para a implementação, considere o grafo representado por lista de adjacências, conforme as estruturas apresentadas abaixo:

typedef struct {
   int V; // número de vértices
   int A; // número de arestas
   Lista **adj; // lista de adjacências
}GrafoLA;

typedef struct Cell Cell;

struct Cell{
    int key;
    Cell *next;
};


typedef struct{
    Cell *head;
}Lista;
Input Format

A primeira linha contém o número de vértices. A segunda linha contém a quantidade de arestas (A). Para cada uma das 
"A" próximas linhas devem der lidos dois números inteiros. sendo os 2 primeiros, a aresta, e o último, o peso da aresta.

Constraints

O não uso do TAD de lista de adjacências acerratará em 75% de desconto da nota, já que a versão com matriz de adjacências é implementada em aula..

Output Format

Imprimir a árvore de caminhos mínimos. Cada linha deve ser impressa no seguinte formato: "v_i: pai[v_i]".

Para o vértice da árvore que não tiver "pai", deve ser impresso o caractere "-" (traço/sinal de menos). Como o algoritmo deve ser iniciada a partir do vértice 
"0", então a primeira linha sempre será "0: -"*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

typedef struct Cellf Cellf;
typedef struct Cell Cell;
typedef struct Lista Lista;
typedef struct GrafoLA GrafoLA;
typedef struct FilaE FilaE;

struct Cellf{
    int item;
    Cellf *next;
};


struct FilaE{
    Cellf *inicio;
    Cellf *fim;
};


Cellf* criar_celulaf(int key){
    Cellf *c = (Cellf*) malloc(sizeof(Cellf));
    c->item = key;

    c->next = NULL;

    return c;
}


FilaE* criar_filaE(){
    FilaE *f = (FilaE*) malloc(sizeof(FilaE));
    
    f->inicio = NULL;
    f->fim = NULL;
    
    return f;
}


int filaE_vazia(FilaE* f){
    return (f == NULL) || (f->inicio == NULL);
}


void enfileirar(int key, FilaE* f){
    Cellf *aux;

    if (f == NULL)
        f = criar_filaE();

    aux = criar_celulaf(key);

    if (f->inicio == NULL)
        f->inicio = f->fim = aux;
    else{
        f->fim->next = aux;
        f->fim = f->fim->next;
    }

}


int desenfileirar(FilaE* f){
    Cellf *aux;
    int item = INT_MIN;

    if (!filaE_vazia(f)){
        aux = f->inicio;

        f->inicio = aux->next;
        
        item = aux->item;

        free(aux);
    }

    return item;
}


void imprimir_fila(FilaE* f){
    Cellf *aux;

    if (!filaE_vazia(f)){
        aux = f->inicio;

        while (aux != NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }
        
        printf("\n");
    }
}


int liberar_filaE(FilaE* f){
    if (!filaE_vazia(f)){
        while (f->inicio != NULL)
            desenfileirar(f);

        free(f);

        return 1;
    }

    return 0;
}


struct Cell{
    int key;
    int peso;
    struct Cell *next;
};


struct Lista{
    Cell *head;
};

struct GrafoLA{
   int V;
   int A;
   int *nafila, *pai, *key;
   Lista **adj;
};

Lista* criar_lista(){
    Lista* l = (Lista*) malloc(sizeof(Lista));

    l->head = NULL;

    return l;
}


Cell* criar_celula(int key,int peso){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->key = key;
    c->peso = peso;
    
    c->next = NULL;

    return c;
}

int lista_vazia(Lista *l){
    return (l == NULL) || (l->head == NULL);
}


int procurar(int key, Lista *l){
    Cell *aux;

    if (l != NULL){
        aux = l->head;

        while ((aux != NULL) && (key < aux->key))
            aux = aux->next;
    }

    if ((aux != NULL) && (key == aux->key))
        return 1;
    else
        return 0;
}


void inserir_na_lista(int key, Lista *l, int peso){
    Cell *auxA, *auxP;
    Cell* c;

    if (lista_vazia(l)){
        if (l == NULL)
            l = criar_lista();

        l->head = criar_celula(key,peso);
    }else{
        c = criar_celula(key,peso);

        if (l->head->key >= key){
           c->next = l->head;


           l->head = c;
        }else{
            auxA = l->head;
            auxP = auxA;

            while ((auxP != NULL) && (auxP->key < key)){
                auxA = auxP;
                auxP = auxP->next;
            }

            auxA->next = c;
            c->next = auxP;
        }
    }
}


int remover_na_lista(int key, Lista *l){
    Cell *auxA, *auxP;

    if (!lista_vazia(l)){
        auxA = l->head;

        if(auxA->key == key)
            l->head = l->head->next;
        else{
            auxP = auxA;

            while((auxA != NULL) && (key < auxA->key)){
                auxP = auxA;
                auxA = auxA->next;
            }

            if (auxA->key == key)
                auxP->next = auxA->next;
            else
                auxA = NULL;
        }

        if (auxA != NULL)
            free(auxA);

        return 1;
    }

        return 0;
}


void imprimir(Lista *l){
    Cell *aux;

    if (!lista_vazia(l)){
        aux = l->head;

        while (aux != NULL){
            printf("%d\n", aux->key);

            aux = aux->next;
        }
    }
}


int liberar_lista(Lista *l){
    Cell *aux;

    if ((l != NULL) && !lista_vazia(l)){

        while(l->head != NULL){
            aux = l->head;

            l->head = aux->next;

            free(aux);
        }

        free(l);

        return 1;
    }

    return 0;
}


static Lista** iniciar_LA(int n){
    int i;
    Lista **adj = (Lista**) malloc(n * sizeof(Lista*));

    for (i = 0; i < n; i++)
        adj[i] = criar_lista();

    return adj;
}


GrafoLA* iniciar_grafoLA(int v){
    GrafoLA* G = (GrafoLA*) malloc(sizeof(GrafoLA));

    G->V = v;
    G->A = 0;
    G->pai = malloc(sizeof(int)*v);
    G->key = malloc(sizeof(int)*v);
    G->nafila = malloc(sizeof(int)*v);
    G->adj = iniciar_LA(G->V);

    return G;
}


int aresta_existeLA(GrafoLA* G, int v1, int v2){
    if ((G!= NULL) && (G->adj[v1]->head != NULL))
        return procurar(v2, G->adj[v1]);

    return 0;
}


void inserir_arestaLA(GrafoLA* G, int v1, int v2,int peso){
    if (!aresta_existeLA(G, v1, v2)){
        inserir_na_lista(v2, G->adj[v1],peso);
        G->A++;
    }
}


void remover_arestaLA(GrafoLA* G, int v1, int v2){
    if (aresta_existeLA(G, v1, v2)){
        remover_na_lista(v2, G->adj[v1]);
        G->A--;

    }
}


void imprimir_arestasLA(GrafoLA* G){
    int i;
    Cell *aux;

    if (G != NULL)
        for (i = 0; i < G->V; i++){
            aux = G->adj[i]->head;

            while (aux != NULL){
                printf("(%d, %d)\n", i, aux->key);

                aux = aux->next;
            }

        }
}


void liberarGLA(GrafoLA* G){
    int i;

    if (G != NULL){
        for (i = 0; i < G->V; i++)
            liberar_lista(G->adj[i]);

        free(G);
    }
}

int valida_vertice(GrafoLA *G, int v){
    return (v>=0) && (v<G->V);
}

int extract_min(FilaE *f, GrafoLA *G){
    int vM;
    Cellf *aux, *auxM;
    
    auxM = f->inicio;
    aux = auxM->next;
    
    while(aux != NULL){
        if(G->key[aux->item] < G->key[auxM->item])
            auxM = aux;
        
        aux = aux->next;
    }
    
    if(auxM != f->inicio){
        vM = f->inicio->item;
        f->inicio->item = auxM->item;
        auxM->item = vM;
    }
    
    return desenfileirar(f);
}

void dijkistra(GrafoLA *G, int s) {
    int u, v;
    FilaE *f = criar_filaE();

    if (valida_vertice(G, s)) {
        for (v = 0; v < G->V; v++) {
            G->pai[v] = -1;
            G->key[v] = INT_MAX;
            G->nafila[v] = 1;
            enfileirar(v, f);
        }

        G->key[s] = 0;

        while (!filaE_vazia(f)) {
            u = extract_min(f, G);
            G->nafila[u] = 0;

            Cell *aux = G->adj[u]->head;

            while (aux != NULL) {
                v = aux->key;
                int peso = aux->peso;

                if (G->nafila[v] && G->key[u] + peso < G->key[v]) {
                    G->key[v] = G->key[u] + peso;
                    G->pai[v] = u;
                }

                aux = aux->next;
            }
        }

        liberar_filaE(f);

        for (v = 0; v < G->V; v++) {
            printf("%d: ", v);

            if (G->pai[v] >= 0)
                printf("%d\n", G->pai[v]);
            else
                printf("-\n");
        }
    }
}


int main() {
    int v,s,a,v1,v2,peso;
    
    GrafoLA *G;
    scanf("%d",&v);
    scanf("%d",&a);
    
    G = iniciar_grafoLA(v);
    
    for(int i = 0; i< a; i++){
        scanf("%d %d %d",&v1,&v2,&peso);
        inserir_arestaLA(G,v1,v2,peso);
    }
    
    scanf("%d",&s);
    
    dijkistra(G,s);
    
       
    return 0;
}

