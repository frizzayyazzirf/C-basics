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

void imprimirLista(NoLista *lista){
    NoLista *aux = lista;
    while(aux){
        printf("%d ", aux->prio);
        aux = aux->prox;
    }
}

void imprimirTabela(TabelaHash *tabela, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("indice %d: ", i);
        imprimirLista(tabela[i].lista);
        printf("\n");
    }
}

int criarTabela(int tamanho){
    int candidato, naoPrimo = 1;
    candidato = tamanho * 2;

    while(naoPrimo){
        naoPrimo = 0;
        for(int i = 2; i < candidato; i++){
            if(candidato % i == 0){
                candidato++;
                naoPrimo = 1;
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

void inserirLista(NoLista **topo, int valor){
    NoLista *novo = malloc(sizeof(NoLista));
    novo->prio = valor;
    novo->prox = *topo;
    *topo = novo;
}

void inserirValor(TabelaHash tabela[], int valor, int tamanho){
    int indice = funcaoHash(valor, tamanho);
    inserirLista(&tabela[indice].lista, valor);
    printf("Valor inserido!\n");
}

int buscarValor(TabelaHash tabela[], int valor, int tamanho){
    int indice = funcaoHash(valor, tamanho);
    NoLista *aux = tabela[indice].lista;

    while(aux){
        if(aux->prio == valor){
            printf("Valor encontrado\n");
            return aux->prio;
        }
        aux = aux->prox;
    }

    printf("Valor nao encontrado\n");
    return 0;
}

int main() {
    int tamanhoHash, tamanho = 0, valorBusca, opcao = 1, valorInserir;

    while(!tamanho){
        printf("Qual o tamanho da tabela?\n");
        scanf("%d", &tamanho);
    }

    tamanhoHash = criarTabela(tamanho);

    TabelaHash *tabela = malloc(sizeof(TabelaHash) * tamanhoHash);
    inicializar(tabela, tamanhoHash);

    while(opcao){
        printf("1 Para imprimir, 2 para inserir, 3 para buscar e 0 para fechar\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 2:
                scanf("%d", &valorInserir);
                inserirValor(tabela, valorInserir, tamanhoHash);
                break;

            case 1:
                imprimirTabela(tabela, tamanhoHash);
                break;

            case 3:
                scanf("%d", &valorBusca);
                valorBusca = buscarValor(tabela, valorBusca, tamanhoHash);
                if(valorBusca)
                    printf(": %d\n", valorBusca);
                break;

            case 0:
                break;

            default:
                printf("Escolha invalida!\n");
        }
    }
}
