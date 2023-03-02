#include "avl.h"
#include<stdio.h>


void preorder (arvore  raiz){

if (raiz != NULL){
    printf("%d", raiz->valor);
    preorder(raiz->esq);
    preorder(raiz->dir);
}



}

void inorder (arvore raiz){
if(raiz!=NULL){
    inorder(raiz->esq);
    printf("%d", raiz->valor);
    inorder(raiz->dir);
}

}

void posorder (arvore raiz){
    posorder(raiz->esq);
    posorder(raiz->dir);
    printf("%d", raiz->valor);
}

arvore maiorElemento (arvore raiz){

if(raiz!=NULL && raiz->dir==NULL){
    return raiz;
}

if(raiz!=NULL){
    return maiorElemento(raiz->dir);
}

return raiz;


}


arvore inserir(arvore raiz, int valor, int* cresceu){
    if(raiz == NULL) {
		arvore novo = (arvore) malloc(sizeof(arvore));
		novo->valor = valor;
		novo->esq = NULL;
		novo->dir = NULL;
		novo->fatorBalanco = 0;
	  * cresceu = 1; 
		return novo;
    }

    else{
        if(valor > raiz->valor){
            raiz->dir = inserir(raiz->dir, valor, cresceu);
            if(*cresceu){   
                switch (raiz->fatorBalanco)
                {
                case 0:
                    raiz->fatorBalanco =1;
                    *cresceu = 1;
                    
                    break;
                
                case -1:
                    raiz->fatorBalanco = 0;
                    *cresceu = 0;


                    break;

                case 1:
                    *cresceu = 0;
                    return rotacionar(raiz);
                    
                    break;    
                }

            }

        }
        else{
            raiz->esq = inserir(raiz->esq, valor, cresceu);
            if(*cresceu){
                switch (raiz->fatorBalanco)
                {
                case 0:
                    raiz->fatorBalanco =-1;
                    *cresceu = 1;
                    
                    break;
                
                case -1:
                    *cresceu = 0;
                    return rotacionar(raiz);


                    break;

                case 1:
                    *cresceu = 0;
                    raiz->fatorBalanco =0;
                    
                    break;    
                }
            }
            
        }  
        return raiz;
    }
    return raiz;



}

arvore rotacionar (arvore raiz){

    if(raiz->fatorBalanco > 0){
        switch (raiz->dir->fatorBalanco)
        {
        case 1: //simples esquerda 
            raiz->dir->fatorBalanco = 0; //raiz direito eh U
            raiz->fatorBalanco = 0;
            return rot_simples_esquerda(raiz);   //raiz eh P
            break;

        case 0: //simples esquerda excluir
            raiz->dir->fatorBalanco = -1;
            raiz->fatorBalanco = 1; 
            return rot_simples_esquerda(raiz);    
            break;

        case -1: //dupla esquerda
        
            break;     
        }
    }

    else{
        switch (raiz->esq->fatorBalanco)
        {
        case -1: //simples direita
            raiz->esq->fatorBalanco =0; //raiz esquerdo eh U
            raiz->fatorBalanco = 0;
            return rot_simples_direita(raiz);   //raiz eh P
            break;
        
        case 0: //simples direita excluir
            raiz->esq->fatorBalanco = 1;
            raiz->fatorBalanco =-1;
            return rot_dupla_direita(raiz);
            break;

        case 1: //dupla direita
            switch (raiz->esq->dir->fatorBalanco)
            {
            case 0 :
                raiz->esq->fatorBalanco = 0;
                raiz->fatorBalanco = 0;
                break;
            case 1:     
                raiz->esq->fatorBalanco = -1;
                raiz->fatorBalanco = 0;

            case -1:
                raiz->esq->fatorBalanco =0;
                raiz->fatorBalanco = 1;
                raiz->esq->dir->fatorBalanco = 0;
                break;
            }
            return rot_dupla_direita(raiz);
                 
        }

    }
}


arvore rot_simples_esquerda(arvore raiz){
    arvore p,u,t2;
    p = raiz;
    u = p->dir;
    t2 = u->esq;
    p->dir = t2;
    u->esq = p;
    return u;
}

arvore rot_simples_direita(arvore raiz){
    arvore p,u,t2;
    p = raiz;
    u = p->esq;
    t2 = u->dir;
    p->esq = t2;
    u->dir = p;
    return u;

}

arvore rot_dupla_esquerda(arvore raiz){
    raiz->dir = rot_simples_direita(raiz->dir);
    return rot_simples_esquerda(raiz);
}

arvore rot_dupla_direita(arvore raiz){
    raiz->esq = rot_simples_esquerda(raiz->esq);
    return rot_simples_direita(raiz);
}

arvore remover (arvore raiz, int valor){}

