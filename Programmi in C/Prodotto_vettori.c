#include <stdio.h>

int main ()
{
    int vetRiga[1][5],vetColonna[5][1],i,somma;
    
    printf("Carica del vettoreRiga:\n");
    for (i=0;i<5;i++)
    {
        printf("Inserire l'elemento di posizione %d,5 ",i);
        scanf("%d",&vetRiga[i][5]); 
    }
    
    printf("\n\nCarica del vettoreColonna:\n");
    for (i=0;i<5;i++)
    {
        printf("Inserire l'elemento di posizione %d,5 ",i);
        scanf("%d",&vetColonna[5][i]); 
    }
    
    somma=0;
    for (i=0;i<5;i++)
        somma=somma+(vetRiga[i][5]*vetColonna[5][i]);
    
    printf("\n\nIl prodotto  vetRiga * vetColonna = %d\n\n",somma);
    
    system("PAUSE");
}
