//Campitiello Pasquale
//678542

#include <stdio.h>
#define SEQ 10

int main ()
{
    int val,max,min,cont;
    
    cont=1;
    printf("Inserisci il numero: ");
    scanf("%d",&val);
    max=val;
    min=val;
    
    do 
    {
        printf("Inserisci il numero: ");
        scanf("%d",&val);
       
        if (val>max) max=val;
        if (val<min) min=val;       
        
        cont++;
     }    
     while (cont!=SEQ);
     
     printf("\nMIN = %d   MAX = %d\n",min,max);
    
     system("PAUSE");
}
     
