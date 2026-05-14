#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char sponge(char str[]){

char alfalw[27] = {"abcdefghijklmnopqrstuvwxyz"}, alfaup[27] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int i= 0;
    i= strlen(str);
    char pint[i];
    strcpy(pint, str);
    for (int h=0; h<i; h+=2){
        int b = 0, j = 0;
        while(str[h]!=alfalw[b] && b != 26){
            b++;
            if(str[h] == alfaup[b])
            j++;
        }
        
      if(str[h] != alfalw[b]){
        if(!j){
            h--;
        }
      }else
        pint[h] = alfaup[b];
            
        

    }
    
    for (int h=1; h<i; h+=2){
        int b = 0, j = 0;
        while(str[h]!=alfaup[b] && b != 26){
            b++;
            if(str[h] == alfalw[b])
            j++;
        }
        
      if(str[h] != alfaup[b]){
        if(!j){
            h--;
        }
      }else
        pint[h] = alfalw[b];
            
        

    }

    printf("%s", pint);
}

int main(){
    sponge("PAUNOCU");
}
