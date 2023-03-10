#include <stdio.h>
#include <stdlib.h>
#include "avl.h"


int altura(No *no) {
    if (no == NULL) {
        return -1;
    } else {
        return no->altura;
    }
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

No *rotacaoEsquerda(No *no) {
    No *aux = no->dir;
    no->dir = aux->esq;
    aux->esq = no;
    no->altura = max(altura(no->esq), altura(no->dir)) + 1;
    aux->altura = max(altura(aux->dir), no->altura) + 1;
    return aux;
}

No *rotacaoDireita(No *no) {
    No *aux = no->esq;
    no->esq = aux->dir;
    aux->dir = no;
    no->altura = max(altura(no->esq), altura(no->dir)) + 1;
    aux->altura = max(altura(aux->esq), no->altura) + 1;
    return aux;
}

No *rotacaoDuplaEsquerda(No *no) {
    no->dir = rotacaoDireita(no->dir);
    return rotacaoEsquerda(no);
}

No *rotacaoDuplaDireita(No *no) {
    no->esq = rotacaoEsquerda(no->esq);
    return rotacaoDireita(no);
}

No *inserir(No *no, int chave) {
    if (no == NULL) {
        no = (No *) malloc(sizeof(No));
        no->chave = chave;
        no->altura = 0;
        no->esq = no->dir = NULL;
    } else if (chave < no->chave) {
        no->esq = inserir(no->esq, chave);
        if (altura(no->esq) - altura(no->dir) == 2) {
            if (chave < no->esq->chave) {
                no = rotacaoDireita(no);
            } else {
                no = rotacaoDuplaDireita(no);
            }
        }
    } else if (chave > no->chave) {
        no->dir = inserir(no->dir, chave);
        if (altura(no->dir) - altura(no->esq) == 2) {
            if (chave > no->dir->chave) {
                no = rotacaoEsquerda(no);
            } else {
                no = rotacaoDuplaEsquerda(no);
            }
        }
    }
    no->altura = max(altura(no->esq), altura(no->dir)) + 1;
    return no;
}

No *remover(No *no, int chave) {
    if (no == NULL) {
        return NULL;
    } else if (chave < no->chave) {
        no->esq = remover(no->esq, chave);
    } else if (chave > no->chave) {
        no->dir = remover(no->dir, chave);
    } else {
        if (no->esq == NULL && no->dir == NULL) {
            free(no);
            no = NULL;
        } else if (no->esq == NULL) {
            No *aux = no;
            no = no->dir;
            free(aux);
        } else if (no->dir == NULL) {
            No *aux = no;
            no = no->esq;
            free(aux);
        } else {
            No *aux = no->esq;
            while (aux->dir != NULL) {
                aux = aux->dir;
            }
            no->chave = aux->chave;
            aux->chave = chave;
            no->esq = remover(no->esq, chave);
        }
    }
    if (no != NULL) {
        no->altura = max(altura(no->esq), altura(no->dir)) + 1;
        if (altura(no->esq) - altura(no->dir) == 2) {
            if (altura(no->esq->esq) - altura(no->esq->dir) == 1) {
                no = rotacaoDireita(no);
            } else {
                no = rotacaoDuplaDireita(no);
            }
        } else if (altura(no->dir) - altura(no->esq) == 2) {
            if (altura(no->dir->dir) - altura(no->dir->esq) == 1) {
                no = rotacaoEsquerda(no);
            } else {
                no = rotacaoDuplaEsquerda(no);
            }
        }
    }
    return no;
}

void imprimir(No *no) {
    if (no != NULL) {
        imprimir(no->esq);
        printf("%d ", no->chave);
        imprimir(no->dir);
    }
}

No *preorder (No * raiz)
{

  if (raiz != NULL)
    {
      printf ("%d ", raiz->chave);
      preorder (raiz->esq);
      preorder (raiz->dir);
    }
}

No*inorder (No* raiz)
{

  if (raiz != NULL)
    {
      inorder (raiz->esq);
      printf ("%d ", raiz->chave);
      inorder (raiz->dir);
    }

}


No *posorder (No * raiz)
{

  if (raiz != NULL)
    {
      posorder (raiz->esq);
      posorder (raiz->dir);
      printf ("%d ", raiz->chave);
    }
}