//Campitiello Pasquale
//678542

#include <stdio.h>
#define END_OF_SEQ 555

int main ()
{
    int val,cont,somma;
    float media;
      
    cont=0;
    val=0;
    somma=0;
 
    while (val!=END_OF_SEQ)
    {
        printf("Inserisci il numero: ");
        scanf("%d",&val);
        if ((val>=0) && (val<=50))
        {      
            somma=somma+val;
            cont++;
        }

        if ((cont==0)&&(val==555))
            printf("\nImpossibile calcolare la media; sequenza vuota\n");
    }
    
    if (cont>0)
    {
        media=(float)(somma)/cont;
        printf("\nLa sequenza e' composta da %d elementi; la media e' %.2f\n",cont,media);
    }
    
    system("PAUSE");
}
