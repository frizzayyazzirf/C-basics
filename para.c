#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funsaoes.h"
typedef struct {
    Pintao *tab;
}hash;

void ini(hash tabe[], int tamhash){
    for(int i = 0; i < tamhash; i++){
        tabe[i].tab = NULL;
        
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

void addinte(Pintao **topo, int valor) {
	Pintao *novo = malloc(sizeof(Pintao));
	novo->prio = valor;
	novo->rola = *topo;
	*topo = novo;
}

void inserir(hash tabe[], int val, int tam){
    int ind;
    ind = funha(val, tam);
    addinte(&tabe[ind].tab, val);
}

int busca(hash tabe[], int val, int tam){
    int ind;
    Pintao *aux;
    ind = funha(val , tam);
    aux = tabe[ind].tab;
    while(aux != NULL && aux->prio != val){
        if(!aux)
        break;
        if(aux->prio == val){
            printf("Valor encontrado\n");
            return aux->prio;
        } else{
            aux = aux->rola;
        }
    }
    if(aux){
        if(aux->prio == val){
            printf("Valor encontrado\n");
            return aux->prio;
        }
    }
    printf("Valor nao encontrado\n");
    return 0;
}

int main() {
    int tamhash, tam = 6, buscar;
    printf("Qual o tamanho da tabela?\n");
    //scanf("%d", &tam);
    tamhash = criatab(tam);
    hash *t;
    t = malloc(sizeof(hash) * tamhash);
    ini(t, tamhash);
    inserir(t, 27, tamhash);
    inserir(t, 5, tamhash);
    inserir(t, 87, tamhash);
    inserir(t, 9, tamhash);
    for(int i = 0; i < tamhash; i++){
        if(t[i].tab)
        printf("%d\n", t[i].tab->prio);
    }
    //printf("%d", t[10].tab->prio);
    buscar = busca(t, 87, tamhash);
    printf("VALOR AQ O %d", buscar);
}