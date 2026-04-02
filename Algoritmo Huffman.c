#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funsaoes.h"

typedef struct{
    int sla;
    char seinao;
}paunocu;

Pintao* ini(Pintao *aux, int val, char val2){
    aux = malloc(sizeof(Pintao));
    aux->prio = val;
    aux->valor = val2;
    aux->pontfila = NULL;
    aux->pontdireito = NULL;
    aux->pontesquerdo = NULL;
    return aux;
}



void addprio(Pintao **princ, Pintao *aux, Pintao *aux2){
    
    if(!(*princ)){
        *princ = malloc(sizeof(Pintao));
        (*princ)->valor = aux->valor;
        (*princ)->prio = aux->prio;
        (*princ)->pontfila = NULL;
        (*princ)->pontdireito = NULL;
        (*princ)->pontesquerdo = NULL;
        return;
    } else if(!aux2->pontfila || aux2->prio > aux->prio || aux2->prio == aux->prio){
        if(!aux2->pontfila){
            if(aux2->prio > aux->prio){
                if(aux2 == *princ){
                    aux->pontfila = aux2;
                    *princ = aux;
                } else {
                    Pintao *lili = *princ;
                    while(lili->pontfila != aux2){
                        lili = lili->pontfila;
                    }
                    aux->pontfila =aux2;
                    lili->pontfila = aux;
                }
            } else {
                aux2->pontfila = aux;
            }
            
            return;
        } else{
            Pintao *jak = NULL;
            jak = *princ;
            if(jak != aux2){
                while(jak ->pontfila != aux2){
                    jak = jak->pontfila;
                }
                aux->pontfila = aux2;
                jak->pontfila = aux;
            }
            else{
                aux->pontfila = aux2;
                *princ = aux;
            }
               
        }
        return;
    } else if(aux2->prio < aux->prio){
        addprio(princ, aux, aux2->pontfila);
    }
}

int verf(paunocu *ku, char a, int herpes){
    for(int i = 0; i < herpes; i++){
        if(ku[i].seinao == a)
        return 1;
    }
    return 0;
}

paunocu* tabvet(char pau[]){
    
    paunocu *ku;
    ku = malloc(sizeof(paunocu) * (strlen(pau) + 9));
    ku->seinao = 0;
    ku->sla = '\0';
    for(int i = 0; i<strlen(pau); i++){
        int b = 0;
        if(!verf(ku, pau[i], i)){
            for(int j = 0; j<strlen(pau); j++){
                if(pau[i] == pau[j])
                b++;
            }
           
            
        }
        ku[i].seinao = pau[i];
        ku[i].sla = b;
    }

    for(int i = 0; i<strlen(pau); i++)
        printf(" %c %d\n", ku[i].seinao,ku[i].sla);

    return ku;
}

Pintao* tabfren(char text[]){
   Pintao *fren = NULL, *aux = NULL;
   paunocu *aux2 = tabvet(text);
   //printf("%d", aux2[5].sla);
   int lolo = strlen(text);
   for(int i = 0; i < lolo; i++){
        if(aux2[i].sla){
            aux = ini(aux, aux2[i].sla, aux2[i].seinao);
            printf("%c", aux->valor);
            printf("%d ", aux->prio);
            addprio(&fren, aux, fren);
            aux = NULL;
            free(aux);
        } 
           
        
    }
   return fren;
}

Pintao* buscar(Pintao *aux,Pintao *encon, char val){
    if(!aux){
        return aux;
    } else if (aux->valor == val){
        return aux;
    } else{
        if(aux->pontesquerdo)
            encon = buscar(aux->pontesquerdo, encon, val);
        if(aux->pontdireito)
            encon = buscar(aux->pontdireito, encon, val);
        return encon;
    }
}


char* codif(Pintao *aux, char *cod, char busc){
    int i = 1, b = 0;
    char num[1000] = {'\0'};
    aux = buscar(aux, NULL, busc);
    while(aux->pontfila){
        if(aux->pontfila->pontesquerdo == aux){
            i++;
            num[b] = '0';
           aux = aux->pontfila;
        } else if(aux->pontfila->pontdireito == aux){
            i++;
            num[b] = '1';
            aux = aux->pontfila;
        }
        b++;
    }
    
    cod = malloc(sizeof(char) * strlen(num));
    for(i = 0; i <= b; i++){
        cod[i] = num[i];
    }
    return cod;
}

void prep(Pintao *arvhuff){
    if(!arvhuff || (!arvhuff->pontdireito && !arvhuff->pontesquerdo) )
        return;
    else{
        if(arvhuff->pontdireito && arvhuff->pontesquerdo){
            arvhuff->pontdireito->pontfila = arvhuff;
            arvhuff->pontesquerdo->pontfila = arvhuff;
        } else if (!arvhuff->pontdireito && arvhuff->pontesquerdo){
            arvhuff->pontesquerdo->pontfila = arvhuff;
        } else{
            arvhuff->pontdireito->pontfila = arvhuff;
        }
        prep(arvhuff->pontesquerdo);
        prep(arvhuff->pontdireito);
    }
    
}



//criação de arvore
Pintao* arvhuff(char text[], Pintao *arq, int esc){
    Pintao *princ;
    if(esc)
    princ = tabfren(text);
    else
    princ = arq;
    while(princ->pontfila){
        Pintao *aux = ini(aux, princ->prio + princ->pontfila->prio, '\0');
        if(princ->prio > princ->pontfila->prio){
            aux->pontdireito = princ;
            aux->pontesquerdo = princ->pontfila;
        } else {
            aux->pontesquerdo = princ;
            aux->pontdireito = princ->pontfila;
        }
    
        addprio(&princ, aux, princ);
        princ = princ->pontfila->pontfila;
        
    }
    return princ;
}

int main(){
    Pintao *aux = malloc(sizeof(Pintao)), *fila = NULL, *auxe = NULL;
    int i = 1;
    printf("Codigo tabela huffman C\n");
    printf("Tabela de frequencia em arquivo e texto codificado, ou desenvolvida agora?\n");
    scanf("%d", &i);
    if(i==1){
        //segfault desconhecido na variavel file arv
        FILE *arv;
        arv = fopen("tabfren.bin", "rb");
        Pintao  *x = NULL;
        int k = 1;
        auxe = ini(auxe, 1, '\0');
        fila = auxe;
        while(fread(&fila->valor, sizeof(char), 1, arv) == 1 && fread(&fila->prio, sizeof(int), 1, arv) == 1){
            fila->pontfila = ini(fila->pontfila, k, '\0');
            fila = fila->pontfila;
            k++;
        }
         
        fclose(arv);
        x = auxe;
        while(x->pontfila != fila){
            printf("%c %d\n", x->valor, x->prio);
            x = x->pontfila;
        }
        x->pontfila = NULL;
        free(fila);
        auxe = arvhuff("\0", auxe, 0);
        prep(auxe);
       
        //implementar função de decodificação  abaixo
        FILE *dec;
        dec = fopen("cod.txt", "r");
        char r;
        fila = auxe;
        while(fread(&r, sizeof(char), 1, dec) == 1){
            if(r == '0'){
                  fila = fila->pontesquerdo;
                if(fila->valor != '\0'){
                    printf("%c", fila->valor);
                    fila = auxe;
                 }
            } else if (r == '1'){
                 fila = fila->pontdireito;
                if(fila->valor != '\0'){
                    printf("%c", fila->valor);
                    fila = auxe;
                }
             }
            
            
        }
    }
    else if (i == 2) {
        FILE *arv = fopen("tabfren.bin", "wb+"), *cod = fopen("cod.txt", "w");
        Pintao *princ;
        char input[1000];
        int l = 0;
        printf("insira o texto: ");
        getchar();
        scanf("%1000[^\n]", input);
        princ = tabfren(input);
        fila = princ;
        while(fila){
            if(fila->valor == ' ')
            printf("ta certo porra");
            fwrite(&fila->valor, sizeof(char), 1,arv);
            fwrite(&fila->prio, sizeof(int), 1,arv);
            fila = fila->pontfila;
        }
         fclose(arv);
        princ = arvhuff('\0', princ, 0);
        prep(princ);
        while(input[l]){
            char *bob;
            
            bob = calloc(sizeof(char), 100);
            printf(" %c", input[l]);
            // ERRO NO CODIF, CARACTERE = ESPAÇO..............................................................................
            
            bob = codif(princ, NULL, input[l]);
            printf("%s", bob);
            for(int i = strlen(bob) - 1; i >= 0; i--){
                fputc(bob[i], cod);
            }
            l++;
            free(bob);
        }
        
        
        fclose(cod);
        
       
    }
}
