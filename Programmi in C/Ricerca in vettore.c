#include <stdio.h>
#define LimVet 5

int main()
{
    int vet[LimVet],i,cerca,pos;
    
    for (i=0;i<LimVet;i++)
    {
        printf("Inserisci il numero di posizione %d: ",i+1);
        scanf("%d",&vet[i]);
    }
    
    printf("\nInserisci il numero da cercare nel vettore: ");
    scanf("%d",&cerca);
    
    i=0;
    while (i<LimVet)
    {
        if (vet[i]==cerca) 
           {
            printf("\nNumero trovato in posizione %d\n\n",i+1);
            i=LimVet+1;
           }
        else i++;
    }
    
    if (i!=LimVet+1) printf("\nNumero non trovato!\n\n");
    
    system("PAUSE");
}
