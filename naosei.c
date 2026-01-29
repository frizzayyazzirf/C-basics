#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char p[10] = {"fulano"};
    //printf("%d", strlen(p));
    int x;
    x = strlen(p);
    
    for(int i = 0; i < x; i++){
         for(int k = x; k > i;k--){
            printf(" ");
        }
        for(int k = x - (i+1); k <= x; k++){
            printf("%c", p[k]);
        }
        
        
        for(int k = x; k >= x - (i+1); k--){
            
            printf("%c", p[k]);
        }
        for(int k = 0; k < i;k++){
            printf(" ");
        }

        printf("\n");
    }      
}
