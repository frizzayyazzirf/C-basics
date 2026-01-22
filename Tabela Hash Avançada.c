#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funsaoes.h"
typedef struct {
    No *tab;
}hash;

void ini(hash tabe[], int tamhash){
    for(int i = 0; i < tamhash; i++){
        tabe[i].tab = NULL;
        
    }
}

void imprimirlista(No *l){
    No *aux;
    aux = l;
    while(aux){
        printf("%d ", aux->prio);
        aux = aux->prox;
    }
}

void imprimirtab(hash *t, int tam){
    for(int i = 0; i < tam; i++){
        printf("indice %d: ", i);
        imprimirlista(t[i].tab);
        printf("\n");
    }
}

int criatab(int tam){
int b, aux = 1;
    b = tam * 2;
    //verificação de numero primo
    while(aux >= 1){
        //Definição para que o loop continue caso b seja divisivel por outro numero alem de 1 e ele mesmo
        aux = 0;
        //primeiro loop, verifica todos os numeros possiveis capazes de dividir
        for(int i = 1; i<=b; i++ ){
            if(i != 1 && i != b){
                if (b % i == 0){
                    printf("Nao e primo.");
                    b++;
                    //detecção de numero nao primo, aux++, logo, aux != 0, codigo rodara novamente
                    aux++;
                    break;
                }
            }
        }
    }
    printf(" %d\n", b);
    return b;
}

int funha(int val, int tam){
    int ind;
    ind = val % tam;
    return ind;
}

void addinte(No **topo, int valor) {
	No *novo = malloc(sizeof(No));
	novo->prio = valor;
	novo->prox = *topo;
	*topo = novo;
}

void inserir(hash tabe[], int val, int tam){
    int ind;
    ind = funha(val, tam);
    addinte(&tabe[ind].tab, val);
    printf("Valor inserido!\n");
}

int busca(hash tabe[], int val, int tam){
    int ind;
    No *aux;
    ind = funha(val , tam);
    aux = tabe[ind].tab;
    while(aux != NULL && aux->prio != val){
        if(aux->prio == val){
            printf("Valor encontrado\n");
            return aux->prio;
        } else{
            aux = aux->prox;
        }
    }
    if(aux){
        if(aux->prio == val){
            printf("Valor encontrado");
            return aux->prio;
        }
    }
    printf("Valor nao encontrado\n");
    return 0;
}

int main() {
    int tamhash, tam = 0, buscar, esc, ins;
    while(!tam){
        printf("Qual o tamanho da tabela?\n");
        scanf("%d", &tam);
    }
    tamhash = criatab(tam);
    hash *t;
    t = malloc(sizeof(hash) * tamhash);
    ini(t, tamhash);
    while(esc){
        printf("1 Para imprimir, 2 para inserir, 3 para buscar e 0 para fechar\n");
        scanf("%d", &esc);
        switch(esc){
            case 2 :
            ins = 0;
            scanf("%d", &ins);
            inserir(t , ins, tamhash);
            break;
            case 1 : 
            imprimirtab(t, tamhash);
            break;
            case 3 : 
            scanf("%d", &buscar);
            buscar = busca(t, buscar, tamhash);
            if(buscar)
                printf(": %d\n", buscar);
            break;
            case 0 :
            break;
            default :
            printf("Escolha invalida!\n");
        }
    }
}
