#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funsaoes.h"

typedef struct {
    NoArvore *ref;
} Visitado;

int verificarValor(NoArvore *a, NoArvore *c, int b[], int tam){
    int cont = 0;
    if(a){
        for(int i = 0; i < tam; i++){
            if(a->prio == b[i]){
                cont++;
            }
        }
    } else {
        return 9999;
    }
    return cont ? 1 : 0;
}

int jaVisitado(NoArvore *a, Visitado v[], int tam){
    if(a){
        for(int i = 0; i < tam; i++){
            if(a == (v + i)->ref)
                return 1;
        }
    }
    return 0;
}

void inserirArvore(NoArvore **raizArv, int val, int *tam){
    NoArvore *novo = malloc(sizeof(NoArvore));
    novo->prio = val;
    novo->pontdireito = NULL;
    novo->pontesquerdo = NULL;

    if(!*raizArv){
        *raizArv = novo;
    } else {
        NoArvore *aux = *raizArv;
        while(aux){
            if(val <= aux->prio){
                if(!aux->pontesquerdo){
                    aux->pontesquerdo = novo;
                    break;
                }
                aux = aux->pontesquerdo;
            } else {
                if(!aux->pontdireito){
                    aux->pontdireito = novo;
                    break;
                }#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funsaoes.h"

typedef struct{
    Arvore *salv;
} Ajuda;

int verificador(Arvore *a, Arvore *c , int b[], int tam){
    int ga = 0;
    if(a){
        for(int i = 0; i < tam; i++){
            if(a->prio == b[i]){  
                ga++;
            }
        }
    }
    else if(!a){
        return 9999;
    }
    if(ga){
        return 1;
    } else
    return 0;
}

int verificaVisitado(Arvore *a, Ajuda ei[], int tam){
    if(a){
        for(int i = 0; i < tam;i++){
            if(a == (ei + i)->salv)
            return 1;
        }
    }
    return 0;
}

void inserirarv(Arvore **raizarv, int val, int *tam){
    Arvore *raiz;
    raiz = malloc(sizeof(Arvore));
    raiz->prio = val;
    raiz->pontdireito = NULL;
    raiz->pontesquerdo = NULL;
    if (!*raizarv){
       *raizarv = raiz;
    } else {
        Arvore *aux = *raizarv;
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

Arvore* buscaarv(Arvore *arv, int busc){
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
int impressao(Arvore *arvbin, int tam, int esc){
    Arvore *aux, *aux2;
    Ajuda seinao[tam];
    for(int i = 0; i < tam; i++){
        (seinao + i)->salv = NULL;
    }
    aux = arvbin->pontesquerdo;
    aux2 = arvbin;
    int valid = 0, i = 0;
    if(arvbin){
        while(valid != 3){
            if(!arvbin->pontesquerdo && !arvbin->pontdireito){
                printf("%d ", arvbin->prio);
                break;
            }
            if(aux->pontesquerdo && verificaVisitado(aux->pontesquerdo, seinao, tam) == 0){
                if(aux2->pontesquerdo == aux)
                aux2 = aux2->pontesquerdo;
                else if(aux2->pontdireito == aux)
                aux2 = aux2->pontdireito;
                aux = aux->pontesquerdo;
                
            }
           else if(!aux->pontesquerdo || verificaVisitado(aux->pontesquerdo, seinao, tam) == 1){
                if(!aux->pontdireito || verificaVisitado(aux->pontdireito, seinao, tam) == 1){
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
                            //tentativa de correção aqui
                            if(aux->pontdireito){
                                aux = aux->pontdireito;
                                valid++;
                            }
                        }
                         else if (aux2->prio == aux->prio){
                            aux2 = aux2->pontesquerdo;
                        }
                    }
                } else if(aux->pontdireito && verificaVisitado(aux->pontdireito, seinao, tam) == 0){
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

Arvore* inserirsub(Arvore *arvbin,Arvore *sub, int tam, int valida, Arvore *aju, Arvore *da){
    Arvore *aux, *aux2;
    Ajuda seinao[tam];
    if(!valida){
    aux = arvbin->pontesquerdo;
    aux2 = arvbin;
    } else {
        if(sub->pontesquerdo && !sub->pontdireito){
            aux = sub->pontesquerdo;
        } else if (sub->pontdireito && !sub->pontesquerdo)
            aux = sub->pontdireito;
        else if (sub->pontesquerdo && sub->pontdireito)
        aux = sub->pontesquerdo;
        aux2 = sub;
    }
    
    int valid = 0, i = 0, l = 0, p = 0, g = 0;
    if(arvbin){
        while(valid != 3){
            if(!arvbin->pontesquerdo && !arvbin->pontdireito){
                printf("%d ", arvbin->prio);
                break;
            }
                if(aux == sub){
                    if(sub->pontdireito && sub->pontesquerdo){
                        g = 3;
                    } else if(!sub->pontdireito || !sub->pontesquerdo){
                        g = 2;
                    }
                    p++;
                }
                    
            if(aux->pontesquerdo && verificaVisitado(aux->pontesquerdo, seinao, tam) == 0){
                if(aux2->pontesquerdo == aux)
                aux2 = aux2->pontesquerdo;
                else if(aux2->pontdireito == aux)
                aux2 = aux2->pontdireito;
                aux = aux->pontesquerdo;
                if(p < g){
                        l++;
                    }
                
            }
           else if(!aux->pontesquerdo || verificaVisitado(aux->pontesquerdo, seinao, tam) == 1 ){
                if(!aux->pontdireito || verificaVisitado(aux->pontdireito, seinao, tam) == 1 ){
                    if (valid == 2){
                        if(valida)
                        (seinao + i)->salv = sub;
                        (seinao + i)->salv = arvbin;
                    } else
                    (seinao + i)->salv = aux;
                    i++;
                    

                    aux = aux2;
                    if(!valida)
                    aux2 = arvbin;
                    else
                    aux2 = sub;

                    while(aux2->pontesquerdo != aux && aux2->pontdireito != aux){
                        if(aux->prio > aux2->prio){
                            aux2 = aux2->pontdireito;
                        } else if (aux->prio < aux2->prio){
                            aux2 = aux2->pontesquerdo;
                        } else if(aux2 == aux){
                            aux = aux->pontdireito;
                            valid++;
                        }
                         else if (aux2->prio == aux->prio){
                            aux2 = aux2->pontesquerdo;
                        }
                    }
                } else if(aux->pontdireito && verificaVisitado(aux->pontdireito, seinao, tam) == 0){
                    if(aux2->pontdireito == aux){
                        aux2 = aux2->pontdireito;
                    }
                    else if(aux2->pontesquerdo == aux)
                    aux2 = aux2->pontesquerdo;
                    aux = aux->pontdireito;
                    if(p < g){
                        l++;
                    }
                }
            } 
        }
    }
    if(valida){
        for(int k = 0; k < i- 1; k++){
            if(k != tam - 1)
            inserirarv(&arvbin, (seinao + k)->salv->prio, &tam);
        }
        return arvbin;
    } else if (!valida){
        if (aju->pontdireito == da){
            aju->pontdireito = NULL;
         } else if (aju->pontesquerdo == da){
            aju->pontesquerdo = NULL;
        }
        inserirsub(arvbin, sub, l, valida + 1, aju, da);
        return arvbin;
    }
    
    
}

Arvore* remocao(Arvore *raiz, int val, int *tam){
    if(raiz){
        Arvore *aux, *aux2;
        aux = raiz;
        if(buscaarv(aux, val)){
           if(!raiz->pontdireito && !raiz->pontesquerdo)
                return NULL;
            aux2 = buscaarv(raiz, val);
            while(aux->pontdireito != aux2 && aux->pontesquerdo != aux2){
                if(aux->prio < aux2->prio)
                    aux = aux->pontdireito;
                else if (aux->prio > aux2->prio || aux->prio == aux2->prio )
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
            
            inserirsub(raiz, aux2, *tam, 0, aux, aux2);
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
    Arvore *arvbin = NULL;
    int tam = 0;
    inserirarv(&arvbin, 10, &tam);
    inserirarv(&arvbin, 7, &tam);
    inserirarv(&arvbin, 8, &tam);
    inserirarv(&arvbin, 6, &tam);
    inserirarv(&arvbin, 1, &tam);
    inserirarv(&arvbin, 4, &tam);
    inserirarv(&arvbin, 4, &tam);
    inserirarv(&arvbin, 8, &tam);
    inserirarv(&arvbin, 9, &tam);
    inserirarv(&arvbin, 9, &tam);
    inserirarv(&arvbin, 9, &tam);
    inserirarv(&arvbin, 9, &tam);
    inserirarv(&arvbin, 9, &tam);
    inserirarv(&arvbin, 9, &tam);
    inserirarv(&arvbin, 13, &tam);
    buscaarv(arvbin, 4);
    impressao(arvbin, tam, 0);
    remocao(arvbin, 13, &tam);
    impressao(arvbin, tam, 0);
}
