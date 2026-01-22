#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funsaoes.h"

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

void fatorcarga(int tam, int tamhash){
    float aux;
    //calculo fator de carga
    aux = (float)tam / tamhash;
    //avisos
    if(aux < 0.30)
    printf("Desperdicio de memoria\n");
    else if (aux > 0.70)
    printf("Pouco espaco vago\n");
}
int* funchash(int conjun[], int tamhash, int tam){
    int tab[tamhash][2], *a, aux = 0;
    a = malloc(criatab(tam) * sizeof(int));
    //espalhamento de indices
    for(int i = 0; i < tam; i++){
        tab[i][0] = conjun[i] % tamhash;
        tab[i][1] = conjun[i];
        printf("%d\n", tab[i][0]);
    }
    for(int i = 0; i<tamhash; i++)
    a[i] = 0;
//passar todos valroes registrados a tabela
        for(int j = 0; j<tam; j++){
            if(!a[tab[j][0]]){
                 a[tab[j][0]] = tab[j][1];
            } else {
               for(int i = 0; i <tamhash; i++){
                    if(!a[i]){
                 a[i] = tab[j][1];
                 break;
            }
               }
            }
    }
    printf("HASH\n");
      for(int i = 0; i<tamhash; i++)
      printf("%d\n", a[i]);
    return a;
}
void addhash(int **hash, int val, int tam){
    int aux, i = 0;
    aux = val % tam;
    printf("%d", aux);
    if(!hash[0][aux])
    hash[0][aux] = val;
    else {
        if(!hash[0][i]){
            hash[0][i] = val;
        }
        else
        while(hash[0][i]){
            if(!hash[0][i]){
                hash[0][i] = val;
                break;
            }
            i++;
        }
    }
    printf("\n\n\n\n");
    for(int i = 0; i<tam; i++){
        printf("%d\n", hash[0][i]);
    }
    printf("\n\n\n\n");
}
int* buscarHash(int hash[], int ind, int tam){
    int aux, b = 0;
    aux = ind % tam;
    if (hash[aux]!=ind){
        for(int i = 0; i < tam; i++){
            printf("valores percorridos: %d\n", hash[i]);
            if (hash[i]==ind){
                printf("valor encontrado mas na posicao incorreta %d\n", hash[i]);
                b++;
                return &hash[i];
            }
            if(b)
                break;
        }
    } else if (hash[aux]==ind){
        printf("valor encontrado %d\n", hash[aux]);
        return &hash[aux];
    }

} 
void retirar(int hash[], int ind, int tam){
    int *pont;
    pont = buscarHash(hash, ind, tam);
    printf("teste %d\n", *pont);
    *pont = 0;
    printf("teste %d", *pont);
}

int main() {
    int conjunt[100], *a = NULL, tam = 8, tamhash, p = 1;
    scanf("%d", &tam);
    for(int i = 0; i < tam; i++){
        scanf("%d", &conjunt[i]);
    }
    a = malloc(criatab(tam) * sizeof(int));
    tamhash = criatab(tam);
    fatorcarga(tam, tamhash);
   a = funchash(conjunt, tamhash, tam);
   addhash(&a, 2,tamhash);
   retirar(a, 2, tamhash);
   while(p == 1){
        int x;
        scanf("%d", &x);
        buscarHash(a, x, tamhash);
   } 
   
   
}
