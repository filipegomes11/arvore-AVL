#ifndef AVL_H
#define AVL_H 
#include <stdlib.h>



typedef struct no{

int valor;
int fatorBalanco;

struct no* dir;
struct no* esq;
    
}no;

typedef no* arvore;

arvore inserir(arvore raiz, int valor, int* cresceu);


void preorder (arvore  raiz);

void inorder (arvore raiz);

void posorder (arvore raiz);

arvore maiorElemento (arvore raiz);

arvore remover (arvore raiz, int valor);

arvore rotacionar (arvore raiz);

arvore rot_simples_esquerda(arvore raiz);

arvore rot_simples_direita(arvore raiz);

arvore rot_dupla_esquerda(arvore raiz);

arvore rot_dupla_direita(arvore raiz);


#endif
























