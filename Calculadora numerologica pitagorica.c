#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funsaoes.h"

int tabpita(char array[], int tam){
    int nume = 0;
    char alf[3][9] = {"abcdefghi", "jklmnopqr", "stuvwxyz"};
    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 9;j++){
            for(int k = 0; k < tam; k++){
                if (array[k] == alf[i][j]){
                    nume+=j;
                    nume++;
                }
                
            }
        }
       
    }
    printf("\n%d\n", nume);
    return nume;
}

int main() {
    int aux;
    char *a;
    printf("tamanho do pau: ");
    scanf("%d", &aux);
    a = malloc(sizeof(char) * aux);
    getchar();
    fgets(a , aux, stdin);
    printf("%s", a);
    int cu;
    cu = strlen(a);
    tabpita(a, cu);
}
