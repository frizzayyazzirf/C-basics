#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funsaoes.h"

typedef struct{
    Pintao *salv;
} ajudaa;

int pau(Pintao *a, ajudaa ei[], int tam){
    if(a){
        for(int i = 0; i < tam;i++){
            if(a == (ei + i)->salv)
            return 1;
        }
    }
    return 0;
}

void inserirarv(Pintao **raizarv, int val){
    Pintao *raiz;
    raiz = malloc(sizeof(Pintao));
    raiz->prio = val;
    raiz->pontdireito = NULL;
    raiz->pontesquerdo = NULL;
    if (!*raizarv){
       *raizarv = raiz;
    } else {
        Pintao *aux = *raizarv;
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
}

Pintao* buscaarv(Pintao *arv, int busc){
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
                arv =arv->pontesquerdo;
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
int impressao(Pintao *arvbin, int tam, int esc){
    if(!arvbin){
        printf("Vazio!\n");
        return 0;
    }
    Pintao *aux, *aux2;
    ajudaa seinao[tam];
    for(int i = 0; i < tam; i++){
        (seinao + i)->salv = NULL;
    }
    if(arvbin->pontesquerdo)
    aux = arvbin->pontesquerdo;
    else
    aux = arvbin->pontdireito;
    aux2 = arvbin;
    int valid = 0, i = 0;
    if(arvbin){
        
        while(valid != 3){
            if(!arvbin->pontesquerdo && !arvbin->pontdireito){
                printf("%d ", arvbin->prio);
                return 0;
                break;
            }
            if(aux->pontesquerdo && pau(aux->pontesquerdo, seinao, tam) == 0){
                if(aux2->pontesquerdo == aux)
                aux2 = aux2->pontesquerdo;
                else if(aux2->pontdireito == aux)
                aux2 = aux2->pontdireito;
                aux = aux->pontesquerdo;
                
            }
           else if(!aux->pontesquerdo || pau(aux->pontesquerdo, seinao, tam) == 1){
                if(!aux->pontdireito || pau(aux->pontdireito, seinao, tam) == 1){
                    if (valid == 2){
                        (seinao + i)->salv = arvbin;
                    } else
                    (seinao + i)->salv = aux;
                    i++;
                    aux = aux2;
                    aux2 = arvbin;
                    if(aux2 == aux){
                    if (!aux->pontdireito){
                         valid = 3;
                        (seinao + i)->salv = arvbin;
                         break;
                     }
                    }
                    while(aux2->pontesquerdo != aux && aux2->pontdireito != aux){
                        if(aux->prio > aux2->prio){
                            aux2 = aux2->pontdireito;
                        } else if (aux->prio < aux2->prio){
                            aux2 = aux2->pontesquerdo;
                        } else if(aux2 == arvbin && aux2 == aux){
                            if(aux->pontdireito){
                                aux = aux->pontdireito;
                                valid++;
                            }
                        }
                         else if (aux2->prio == aux->prio){
                            aux2 = aux2->pontesquerdo;
                        }
                    }
                } else if(aux->pontdireito && pau(aux->pontdireito, seinao, tam) == 0){
                    if(aux2->pontdireito == aux){
                        aux2 = aux2->pontdireito;
                    }
                    else if(aux2->pontesquerdo == aux)
                    aux2 = aux2->pontesquerdo;
                    aux = aux->pontdireito;
                }
            } 
        }
    }
    if(!esc){
        for(int k = 0; k < tam; k++){
         printf("%d ", (seinao + k)->salv->prio);
    }
    }
    else
    return i;
  printf("\n");
}

int tam2(Pintao *arv){
    if(!arv){
        return 1;
    }
    return tam2(arv->pontesquerdo) + tam2(arv->pontdireito);
}

int inser(Pintao **raiz, Pintao *subarv, Pintao *aux){
    if(subarv){
       if(subarv != aux)
        inserirarv(raiz, subarv->prio);
         inser(raiz, subarv->pontesquerdo, aux);
        inser(raiz, subarv->pontdireito, aux);
    } 
    
   
}

void remocao(Pintao **arv, int val){
    Pintao *arvbin;
    arvbin = *arv;
    if(arvbin){
        
        Pintao *a = buscaarv(arvbin, val);
        if(*arv == a){
            if(!(*arv)->pontdireito && !(*arv)->pontdireito)
            *arv = NULL;
            else{
                *arv = NULL;
                inser(arv, arvbin, arvbin);
            }

            return;
        }
        
        if(a){
            while(arvbin != a){
                if(a->prio < arvbin->prio || a->prio == arvbin->prio ){
                     if (arvbin->pontesquerdo == a){
                        arvbin->pontesquerdo = NULL;
                        inser(arv, a, a);
                        break;
                    }
                    arvbin = arvbin->pontesquerdo;
                } else{
                    if(arvbin->pontdireito == a){
                       
                        arvbin->pontdireito = NULL;
                        inser(arv, a, a);
                        break;
                    }
                    arvbin = arvbin->pontdireito;
                   
                }
                    
            }
            
        }
    }
  
}

int foleas(Pintao *arv){
    if(!arv){
        return 0;
    } else if (!arv->pontesquerdo && !arv->pontdireito)
    return 1;
    return foleas(arv->pontesquerdo) + foleas(arv->pontdireito);
}

int altura(Pintao *arv){
    if(!arv){
        return -1;
    } else{
        int esq = altura(arv->pontesquerdo);
        int dir = altura(arv->pontdireito);
        if(esq > dir){
            return esq + 1;
        } else
        return dir + 1;
    }
}

int main(){
    int esc = 1;
    int b;
    Pintao *arvbin = NULL;
    while(esc){
        printf("\nArvore binaria de busca C\n1-Inserir, 2-imprimir, 3 calcular folhas, 4-remover, 5-buscar, 6-tamanho, 7-altura, 0-sair\n");
        scanf("%d", &esc);
        switch(esc){
            case 1 : 
            printf("Valor a ser inserido: ");
            scanf("%d", &b);
            inserirarv(&arvbin, b);
            break;
            case 2 : 
            impressao(arvbin, tam2(arvbin) - 1, 0);
            break;
            case 3 : 
            printf("Essa arvore tem %d folhas\n", foleas(arvbin));
            break;
            case 4: 
            printf("Valor a ser removido: ");
            scanf("%d", &b);
            remocao(&arvbin, b);
            break;
            case 5 :
            printf("Valor a ser buscado: ");
            scanf("%d", &b);
            buscaarv(arvbin, b);
            break;
            case 6 :
            printf("Tamanho da arvore %d\n", tam2(arvbin) - 1);
            break;
            case 7: 
            printf("Altura da arvore %d\n", altura(arvbin));
            break;
            case 0 :
            printf("Fechando");
            break;
            default :
            printf("Escolha invalida\n");
            break;
        }
    }
}
