#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funsaoes.h"

typedef struct {
    NoLista *lista;
} TabelaHash;

void inicializar(TabelaHash tabela[], int tamanhoHash){
    for(int i = 0; i < tamanhoHash; i++){
        tabela[i].lista = NULL;
    }
}

int criarTabela(int tamanho){
    int candidato, composto = 1;
    candidato = tamanho * 2;

    // verificação de número primo
    while(composto){
        composto = 0;
        for(int i = 2; i < candidato; i++){
            if(candidato % i == 0){
                printf("Nao e primo.");
                candidato++;
                composto = 1;
                break;
            }
        }
    }
    printf(" %d\n", candidato);
    return candidato;
}

int funcaoHash(int valor, int tamanho){
    return valor % tamanho;
}

void inserirLista(NoLista **topo, int valor) {
    NoLista *novo = malloc(sizeof(NoLista));
    novo->prio = valor;
    novo->prox = *topo;
    *topo = novo;
}

void inserirTabela(TabelaHash tabela[], int valor, int tamanho){
    int indice = funcaoHash(valor, tamanho);
    inserirLista(&tabela[indice].lista, valor);
}

int buscarTabela(TabelaHash tabela[], int valor, int tamanho){
    int indice = funcaoHash(valor, tamanho);
    NoLista *aux = tabela[indice].lista;

    while(aux && aux->prio != valor){
        aux = aux->prox;
    }

    if(aux && aux->prio == valor){
        printf("Valor encontrado\n");
        return aux->prio;
    }

    printf("Valor nao encontrado\n");
    return 0;
}

int main() {
    int tamanhoHash, tamanho = 6, valorBusca;

    printf("Qual o tamanho da tabela?\n");
    scanf("%d", &tamanho);

    tamanhoHash = criarTabela(tamanho);

    TabelaHash *tabela = malloc(sizeof(TabelaHash) * tamanhoHash);
    inicializar(tabela, tamanhoHash);

    inserirTabela(tabela, 27, tamanhoHash);
    inserirTabela(tabela, 5, tamanhoHash);
    inserirTabela(tabela, 87, tamanhoHash);
    inserirTabela(tabela, 9, tamanhoHash);

    for(int i = 0; i < tamanhoHash; i++){
        if(tabela[i].lista)
            printf("%d\n", tabela[i].lista->prio);
    }

    int entrada;
    scanf("%d", &entrada);

    valorBusca = buscarTabela(tabela, entrada, tamanhoHash);
    printf("VALOR AQ O %d", valorBusca);
}
