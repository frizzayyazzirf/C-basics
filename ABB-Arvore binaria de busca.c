#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funsaoes.h"

typedef struct{
    NoArvore *ref;
} Visitado;

int verificaPrioridade(NoArvore *a, NoArvore *c , int b[], int tam){
    int cont = 0;
    if(a){
        for(int i = 0; i < tam; i++){
            if(a->prio == b[i]){  
                cont++;
            }
        }
    }
    else{
        return 9999;
    }
    if(cont){
        return 1;
    } else
    return 0;
}

int jaVisitado(NoArvore *a, Visitado v[], int tam){
    if(a){
        for(int i = 0; i < tam;i++){
            if(a == (v + i)->ref)
            return 1;
        }
    }
    return 0;
}

void inserirArvore(NoArvore **raizArv, int val, int *tam){
    NoArvore *raiz;
    raiz = malloc(sizeof(NoArvore));
    raiz->prio = val;
    raiz->pontdireito = NULL;
    raiz->pontesquerdo = NULL;
    if (!*raizArv){
       *raizArv = raiz;
    } else {
        NoArvore *aux = *raizArv;
       while(aux){
            if(raiz->prio < aux->prio || raiz->prio == aux->prio){
                 if(!aux->pontesquerdo){
                    aux->pontesquerdo = raiz;
                    break;
                }
                aux = aux->pontesquerdo;
            } else if(raiz->prio > aux->prio){
                if(!aux->pontdireito){
                    aux->pontdireito = raiz;
                    break;
                }
                aux = aux->pontdireito;
            }
       }
    }
    *tam = *tam + 1;
}

NoArvore* buscarArvore(NoArvore *arv, int busc){
    if(arv){
        if(busc == arv->prio){
            printf("Valor %d encontrado na raiz\n", busc);
            return arv;
        } 
        while(arv){
            if(arv->prio == busc){
                if(arv->pontdireito || arv->pontdireito)
                printf("Valor %d encontrado na subarvore\n", busc);
                else if(!arv->pontdireito && !arv->pontesquerdo)
                printf("Valor %d encontrado na folha\n", busc);
                return arv;
            }
            if(arv->prio < busc){
                arv = arv->pontdireito;
            } else if(arv->prio > busc){
                arv = arv->pontesquerdo;
            }
        }
        if(!arv){
            printf("Valor nao encontrado\n");
            return arv;
        }
    } 
    printf("arvore vazia");
    return arv;
}

int impressao(NoArvore *arvbin, int tam, int esc){
    NoArvore *aux, *aux2;
    Visitado visitados[tam];
    for(int i = 0; i < tam; i++){
        (visitados + i)->ref = NULL;
    }
    ...
}

NoArvore* inserirSubarvore(NoArvore *arvbin, NoArvore *sub, int tam, int valida, NoArvore *pai, NoArvore *alvo){
    NoArvore *aux, *aux2;
    Visitado visitados[tam];
    ...
}

NoArvore* remover(NoArvore *raiz, int val, int *tam){
    if(raiz){
        NoArvore *aux, *aux2;
        aux = raiz;
        if(buscarArvore(aux, val)){
           if(!raiz->pontdireito && !raiz->pontesquerdo)
                return NULL;
            aux2 = buscarArvore(raiz, val);
            while(aux->pontdireito != aux2 && aux->pontesquerdo != aux2){
                if(aux->prio < aux2->prio)
                    aux = aux->pontdireito;
                else
                    aux = aux->pontesquerdo;
            }
            if(!aux2->pontdireito && !aux2->pontesquerdo){
                if(aux->pontdireito == aux2)
                aux->pontdireito = NULL;
                else if(aux->pontesquerdo == aux2)
                aux->pontesquerdo = NULL;
                *tam = *tam - 1;
                return raiz;
            }
            inserirSubarvore(raiz, aux2, *tam, 0, aux, aux2);
            *tam = *tam - 1;
            return raiz;
        } else{
            return aux;
        }
    } 
    else{
        printf("Arvore vazia!");
        return NULL;
    }
}

int main() {
    NoArvore *arvbin = NULL;
    int tam = 0;
    inserirArvore(&arvbin, 10, &tam);
    inserirArvore(&arvbin, 7, &tam);
    inserirArvore(&arvbin, 8, &tam);
    inserirArvore(&arvbin, 6, &tam);
    inserirArvore(&arvbin, 1, &tam);
    inserirArvore(&arvbin, 4, &tam);
    inserirArvore(&arvbin, 4, &tam);
    inserirArvore(&arvbin, 8, &tam);
    inserirArvore(&arvbin, 9, &tam);
    inserirArvore(&arvbin, 9, &tam);
    inserirArvore(&arvbin, 13, &tam);
    buscarArvore(arvbin, 4);
    impressao(arvbin, tam, 0);
    remover(arvbin, 13, &tam);
    impressao(arvbin, tam, 0);
}
