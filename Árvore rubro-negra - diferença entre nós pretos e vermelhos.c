/*Implemente uma função que receba, pelo menos, uma árvore rubro-negra. Essa função deverá retornar um número >= 0 que represente a 
diferença de somatórios entre nós pretos e vermelhos. Por exemplo, primeiramente deve ser somado os valores dos nós de cada tipo. 
Em seguinda, calcular a diferença entre essas somas.

Input Format

Na primeira linha deve ser lido o número inteiro N, que é referente à quantidade de nós da árvore. Em seguida, em cada linha deve ser 
lido um número inteiro para ser inserido como nó na árvore (fazer isso até que N números sejam lidos).

Constraints

Utilizar o TAD de árvore rubro-negra disponibilizada na página da disciplina no Moodle.

Output Format

Imprimir a diferença de somatórios entre nós pretos e vermelhos.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct NodeVP NodeVP;

struct NodeVP{
    int key;
    int color;
    NodeVP *father;
    NodeVP *left;
    NodeVP *right;
};


NodeVP* criar_AVP(int key){
    NodeVP* tree = (NodeVP*) malloc(sizeof(NodeVP));
    tree->key = key;
    tree->color = 0;
    tree->left = NULL;
    tree->right = NULL;
    tree->father = NULL;

    return tree;
}


NodeVP* pesquisar(NodeVP *tree, int key){
    if (tree != NULL){
        if (key == tree->key)
            return tree;
        else if (key < tree->key)
            return pesquisar(tree->left, key);
        else
            return pesquisar(tree->right, key);
    }

    return NULL;
}



static NodeVP* obter_avo(NodeVP *no){
    if ((no != NULL) && (no->father != NULL)){
        return no->father->father;
    }

    return NULL;
}


static NodeVP* obter_tio(NodeVP *no){
    NodeVP* avo = obter_avo(no);
    NodeVP* aux = NULL;
    

    if (avo != NULL){
        if (avo->left == no->father){
            aux = avo->right;
        }else
            aux = avo->left;
    }

    return aux;
}


static NodeVP* rotacionar_dir(NodeVP *x){
    NodeVP *p = x->father;
    NodeVP *a = p->father;
    
    p->father = a->father;
    
    if (a->father != NULL){
        if (a->father->left == a)
            a->father->left = p;
        else
            a->father->right = p;
    }
    
    a->father = p;
    a->left = p->right;
    p->right = a;
    
    x = p;
    
    return x;
}


static NodeVP* rotacionar_esq(NodeVP *x){
    NodeVP *p = x->father;
    NodeVP * a = p->father;
    
    p->father = a->father;
    
    if (a->father != NULL){
        if (a->father->right == a)
            a->father->right = p;
        else
            a->father->left = p;
    }
    
    a->father = p;
    a->right = p->left;
    p->left = a;

    x = p;
    
    return x;
}


static NodeVP* rotacionar_dir_esq(NodeVP *x){
    NodeVP *p = x->father;
    NodeVP *a = p->father;
    
    x->father = a;
    a->left = x;
    p->left = x->right;
    x->right = p;
    p->father = x;
    
    x = rotacionar_esq(p);

    return x;
}


static NodeVP* rotacionar_esq_dir(NodeVP *x){
    NodeVP *p = x->father;
    NodeVP * a = p->father;
    
    x->father = a;
    a->left = x;
    p->father = x;
    p->right = x->left;
    x->left = p;
    
    x = rotacionar_dir(p);

    return x;
}


static NodeVP* balancear(NodeVP *x){
    NodeVP *pai, *tio;

    if (x->father == NULL){
        x->color = 1;
    }else{
        pai = x->father;

        if (pai->color == 0){
            tio = obter_tio(x);

            if ((tio != NULL) && (tio->color == 0)){
                pai->color = tio->color = 1;
                x = obter_avo(x);
        
            if (x->father != NULL)
                x->color = 0;
            }else{
                if (pai->left == x){
                    if (pai->father->left == pai)
                        x = rotacionar_dir(x);
                    else
                        x = rotacionar_dir_esq(x);
                }else{
                    if (pai->father->right == pai)
                        x = rotacionar_esq(x);
                    else
                        x = rotacionar_esq_dir(x);
                }

                x->color = 1;
                
                if (x->left != NULL)
                    x->left->color = 0;
                
                if (x->right != NULL)
                    x->right->color = 0;
            }
        }
    }
    
    return x;
}


NodeVP* inserirVP(NodeVP *tree, int key){
    NodeVP *auxP, *auxF;

    if (tree == NULL){
        tree = criar_AVP(key);
        tree->color = 1;
    }else{
        auxP = auxF = tree;

        while (auxF != NULL){
            auxP = auxF;

            if (key < auxF->key)
                auxF = auxF->left;
            else
                auxF = auxF->right;
        }

        auxF = criar_AVP(key);
        auxF->father = auxP;

        if (auxF->key < auxP->key)
            auxP->left = auxF;
        else
            auxP->right = auxF;

        while ((auxF->father != NULL) && (auxF->color == 0) && (auxF->father->color == 0))
            auxF = balancear(auxF);
        
        while (auxF->father != NULL)
            auxF = auxF->father;

        tree = auxF;
    }
    
    return tree;
}

int contar_no_vermelho(NodeVP *tree){
    if(tree != NULL){
        if(tree->color == 0)
            return tree->key + contar_no_vermelho(tree->left)+ contar_no_vermelho(tree->right);
        else
            return contar_no_vermelho(tree->left)+ contar_no_vermelho(tree->right);
    }
    else 
        return 0;
}

int contar_no_preto(NodeVP *tree){
    if(tree != NULL){
        if(tree->color == 1)
            return tree->key + contar_no_preto(tree->left)+ contar_no_preto(tree->right); 
        else 
            return contar_no_preto(tree->left)+ contar_no_preto(tree->right);
    }
    else 
        return 0;
}

int diferenca_de_nos(NodeVP *tree){
    int num1,num2;
    num1=contar_no_preto(tree);
    num2=contar_no_vermelho(tree);
    
    return num1-num2;
}

int main() {
    int n,i,item;
    NodeVP *tree=NULL;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%d",&item);
        
        tree=inserirVP(tree,item);
    }
    
    printf("%d",diferenca_de_nos(tree));
        
    return 0;
}
