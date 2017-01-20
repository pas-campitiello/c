//Campitiello Pasquale
//678542

#include <stdio.h>
#define VET 15

int main()
{
    int cerca,i,num[VET],t;
    
    for (i=0;i<VET;i++)
    {
        printf("Inserisci il numero di posizione [%d]: ",i);
        scanf("%d",&num[i]);
    }    
        
    printf("\nInserisci il numero da cercare nel vettore: ");
    scanf("%d",&cerca);
    
    t=-1;
    i=0;    
    
    do
    {    
        if (num[i]==cerca) t=i;
        i++;
     }
    while ((t!=i-1) && (i<VET));
    
    if (t!=-1) printf("\nIl numero %d e` stato trovato per la prima volta in posizione %d",cerca,t);
    else printf("\n*** NUMERO NON TROVATO ***");
    
    printf("\n\n");   
    system("PAUSE");
}
