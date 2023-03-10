#ifndef AVL_H
#define AVL_H 
#include <stdlib.h>


typedef struct no {
    int chave;
    int altura;
    struct no *esq;
    struct no *dir;
} No;

int altura(No *no);
int max(int a, int b);
No *rotacaoEsquerda(No *no);
No *rotacaoDireita(No *no);
No *rotacaoDuplaEsquerda(No *no);
No *rotacaoDuplaDireita(No *no);
No *inserir(No *no, int chave);
No *remover(No *no, int chave);
void imprimir(No *no);
No *preorder (No * raiz);
No *inorder (No * raiz);
No *posorder (No * raiz);





#endif
























