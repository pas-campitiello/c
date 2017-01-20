//esercitazione 11 novembre
//ricevutu un array di caratteri fare la correzzione, ovvero sostituire 
//le triplette di lettere uguali con doppie uguali

#include<stdio.h>
#define END 30

int main(){
     int i,volte,cont;
     char vett[END+1];
     
     printf("inserisci una parola ");
     gets(vett);
     
     cont=0;
     for(i=0;vett[i]!='\0';i++)
     {
         if(vett[i]==vett[i+1])
             cont++;
         else 
             cont=0;
         
         if(cont<2)                        
            printf("%c",vett[i]);
         else 
            cont=0;
     }

     printf("\n\n");
     system("pause");
               
}
