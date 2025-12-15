#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funsaoes.h"

typedef struct no{
	int valor;
	struct no *proximo;
} Lista;

int percorrer1(Lista *topo) {
    Lista *aux;
    aux = topo;
    int i = 1;
    printf("Lista\n");
    while(aux) {
        printf("Posicao numero %d: Endereco>%p , Valor>%d\n", i, aux, aux->valor);
        aux = aux->proximo;
        i++;
    }
    return i - 1;
}

Lista* percorreraux(Lista *topo) {
    Lista *aux;
    aux = topo;
    int i = 1;
    while(aux->proximo) {
        aux = aux->proximo;
        i++;
    }
    return aux;
}

Lista* percorrer2(Lista *topo2, Lista *topo3) {
    Lista *aux, *aux2;
    aux = topo2;
    aux2 = aux;
    int i = 1;
    while(aux->proximo) {
        aux = aux->proximo;
        i++;
    }
    aux->proximo = topo3;
    return aux2;
}

void alterar(Lista **topo, int ind) {
    if(*topo) {
        Lista *aux;
        aux = *topo;
        int i = 1;
        int val;
        for( i = 0; i < ind - 1; i++) {
            aux = aux->proximo;
        }
        printf("digite o valor para a posicao %d: ", i);
        scanf(" %d", &val);
        aux->valor = val;
    } else
        printf("Lista vazia!\n");

}

void retirar(Lista **topo, int esc) {
    if(!*topo) {
        printf("Lista vazia!\n");
    } else {
        int ajuda = 0;
        ajuda = percorrer1(*topo);
        int k;
        if (esc == 4) {
            printf("escolha a posicao da qual quer retirar: ");
            scanf("%d", &k);
        } else if (esc == 5) {
            k = 1;
        } else if(esc == 6) {
            k = ajuda;
        }

        if(k > ajuda) {
            printf("valor invalido\n");
        }
        else if(k == 1) {
            Lista *aux;
            aux = malloc(sizeof(Lista));
            aux = *topo;
            *topo = (*topo)->proximo;
            free(aux);
        } else if (k == ajuda) {
            printf("%d eh a ultima posicao\n", k);
            Lista *aux1;
            aux1 = *topo;
            for(int i = 0; i < k - 2; i++) {
                aux1 = aux1->proximo;
            }
            aux1->proximo = NULL;
        } else {
            Lista *aux, *aux1, *aux2;
            aux = malloc(sizeof(Lista));

            aux1 = *topo;
            aux2 = aux1->proximo;
            for(int i = 0; i < k - 2; i++) {
                aux1 = aux1->proximo;
                aux = aux1->proximo;
                aux2 = aux->proximo;
            }
            aux1->proximo = aux2;
            free(aux);
        }
    }
}

void inserir(Lista **topo, int valor, int esc) {
    if(!*topo) {
        printf("Lista vazia, adicionando valor...\n");
        Lista *aux;
        aux = malloc(sizeof(Lista));
        aux->valor = valor;
        aux->proximo = NULL;
        *topo = aux;
    } else {
        int ajuda = 0;
        ajuda = percorrer1(*topo);
        int k;
        if (esc == 1) {
            printf("escolha a posicao da qual quer inserir: ");
            scanf("%d", &k);
        } else if (esc == 2) {
            k = 1;
        } else if(esc == 3) {
            k = ajuda;
        }

        if(k > ajuda) {
            printf("valor invalido\n");
        }
        else if(esc == 2) {
            Lista *aux;
            aux = malloc(sizeof(Lista));
            aux->valor = valor;
            aux->proximo = *topo;
            *topo = aux;
        } else if (esc == 3) {
        
                printf("%d eh a ultima posicao\n", k);
                Lista *aux, *aux1;
                aux = malloc(sizeof(Lista));
                aux->valor = valor;
                aux->proximo = NULL;
                aux1 = *topo;
                while(aux1->proximo){
                    aux1 = aux1->proximo;
                }
                aux1->proximo = aux;
            
        } else {
            Lista *aux, *aux1, *aux2;
            aux = malloc(sizeof(Lista));
            aux->valor = valor;
            aux1 = *topo;
            aux2 = aux1->proximo;
            for(int i = 0; i < k - 2; i++) {
                aux1 = aux1->proximo;
                aux2 = aux1->proximo;
            }
            aux->proximo = aux2;
            aux1->proximo = aux;
        }
    }
}

Lista* unir(Lista *topo){
    Lista *aux;
    aux = NULL;
    while(topo){
        inserir(&aux, topo->valor, 3);
        topo = topo->proximo;
    }
    return aux;
}
Lista* separar(Lista *topo){
    Lista *topo2 = NULL;
    int esc = 0, i = 0;
    while(esc < 1 || esc > 2){
        printf("Impares ou pares? 1 para impares, 2 para pares\n");
        scanf("%d", &esc);
        if(esc < 1 || esc > 2)
        printf("escolha invalida\n");
        else{
            if(esc == 1){
                while(topo){
                    if(topo->valor % 2 != 0){
                        inserir(&topo2, topo->valor, 2);
                        i++;
                    }
                    topo = topo->proximo;
                }
                if(i)
                return topo2;
                else
                return NULL;
            } else if(esc == 2){
                while(topo){
                    if(topo->valor % 2 == 0){
                        inserir(&topo2, topo->valor, 2);
                        i++;
                    }
                    topo = topo->proximo;
                }
                if(i)
                return topo2;
                else
                return NULL;
            }
        }
    }
        
}

int main() {
    Lista *lista1 = NULL, *lista2 = NULL, *lista3 = NULL;
    int esc = 1, esc1 = 1;
    while(esc) {
        printf("Codigo de multiplas listas C\n 1 - Alterar primeira lista\n 2 - Alterar segunda lista\n 3 - Unir ambas em uma terceira lista\n 4 - Separar uma lista em impares e pares\n 0 - fechar\n");
        scanf("%d", &esc);
        int bixa = esc;
        if(esc > 4 || esc < 0) {
            printf("Escolha invalida\n");
        } else if(esc == 1) {
            esc1 = 1;
            while(esc1){
                printf("\nLista encadeada C, Lista %d\n 1 - inserir em posicao determinada pelo usuario\n 2 - inserir topo\n 3 - inserir final\n 4 - retirar em posicao determinada pelo usuario\n 5 - retirar topo\n 6 - retirar final\n 7 - alterar valor\n 8 - exibir\n 0 - fechar\n", bixa);
                scanf("%d", &esc1);
                if(esc1 > 8 || esc1 < 0) {
                    printf("valor invalido\n");
                } else if(esc1 == 1 || esc1 == 2 || esc1 == 3) {
                    printf("digite o valor: ");
                    int val = 0;
                    scanf("%d", &val);
                    inserir(&lista1, val, esc1);
                } else if(esc1 == 4 || esc1 == 5 || esc1 == 6) {
                    retirar(&lista1, esc1);
                } else if (esc1 == 7) {
                    percorrer1(lista1);
                    printf("escolha o valor a ser alterado: ");
                    int caraio;
                    scanf("%d", &caraio);
                    alterar(&lista1, caraio);
                } else if (esc1 == 8) {
                    percorrer1(lista1);
                    printf("digite para parar de exibir");
                    getchar();
                    getchar();

                }
            }
        }
            else if(esc == 2) {
            esc1 = 1;
            while(esc1){
                printf("\nLista encadeada C, Lista %d\n 1 - inserir em posicao determinada pelo usuario\n 2 - inserir topo\n 3 - inserir final\n 4 - retirar em posicao determinada pelo usuario\n 5 - retirar topo\n 6 - retirar final\n 7 - alterar valor\n 8 - exibir\n 0 - fechar\n", bixa);
                scanf("%d", &esc1);
                if(esc1 > 8 || esc1 < 0) {
                    printf("valor invalido\n");
                } else if(esc1 == 1 || esc1 == 2 || esc1 == 3) {
                    printf("digite o valor: ");
                    int val = 0;
                    scanf("%d", &val);
                    inserir(&lista2, val, esc1);
                } else if(esc1 == 4 || esc1 == 5 || esc1 == 6) {
                    retirar(&lista2, esc1);
                } else if (esc1 == 7) {
                    percorrer1(lista2);
                    printf("escolha o valor a ser alterado: ");
                    int caraio;
                    scanf("%d", &caraio);
                    alterar(&lista2, caraio);
                } else if (esc1 == 8) {
                    percorrer1(lista2);
                    printf("digite para parar de exibir");
                    getchar();
                    getchar();

                }
            }
        } else if(esc == 3){
            if(!lista1  || !lista2)
            printf("Impossivel concatenar, uma ou ambas listas vazias\n");
            else{
                lista3 = NULL;
                Lista *help, *uniao;
                help = percorreraux(lista1);
                lista3 = percorrer2(lista1,lista2);
                printf("lista3\n");
                percorrer1(lista3);
                uniao = unir(lista3);
                help->proximo = NULL;
                printf("uniao\n");
                percorrer1(uniao);
            }
        } else if(esc == 4){
            if(lista1 || lista2){
                Lista *par = NULL;
                int bap;
                printf("lista 1 ou 2?\n");
                scanf("%d", &bap);
                if(bap == 1){
                    par = separar(lista1);
                    if(par)
                    percorrer1(par);
                    else 
                    printf("Nenhum correspondente encontrado\n");
                } else if (bap == 2){
                    par = separar(lista2);
                    if(par)
                    percorrer1(par);
                    else 
                    printf("Nenhum correspondente encontrado\n");
                } else
                printf("who is he?\n");
                
            } else
            printf("vazioporra\n");
        
        }
         else if(esc == 0)
        break;
        
    } 
}