#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funsaoes.h"

int* bubl(int arr[], int tam){
    int temp = 0, vali = 0;
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam - 1; j++)
            while(arr[j]<arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                if(arr[j] == 1)
                    printf("a");
            }
    }
}

int main(){
    printf("vetor aleatorio\n");
    int tes[] = {10, 2 , 4 ,5 ,3 ,4};
    for(int i = 0; i < 6; i++){
        printf("%d ", tes[i]);
    }
    printf("\n");
    bubl(tes, 6);
     printf("vetor ordenado\n");
    for(int i = 0; i < 6; i++){
        printf("%d ", tes[i]);
    }
}
