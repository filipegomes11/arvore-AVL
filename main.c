#include "avl.c"

int main() {
    No *raiz = NULL;
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 25);
    imprimir(raiz);

    
    raiz = remover(raiz, 20);
    imprimir(raiz);
    
    printf("");


    return 0;




}