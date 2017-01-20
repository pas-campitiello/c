//Campitiello Pasquale
//678542

#include <stdio.h>
#define GIUDICI 7

int main ()
{
    int voto,max,min,cont,somma;
    float MediaVoti;
    
    voto=0;
    cont=0;
    max=0;
    min=10;
    somma=0;
    
    do 
    {
        cont++;
        
        do 
        {
            printf("Inserisci il voto del %do giudice: ",cont);
            scanf("%d",&voto);
        }    
        while ((voto<0)||(voto>10));
       
        if (voto>max) max=voto;
        if (voto<min) min=voto;                
        somma=somma+voto;        
    }    
    while (cont!=GIUDICI);
    
    MediaVoti=(float)(somma-max-min)/5;

    printf("\nPUNTEGGIO FINALE = %.3f\n",MediaVoti);
    
    system("PAUSE");
}      
