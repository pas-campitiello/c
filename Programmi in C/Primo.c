#include <stdio.h>

int main()
{
    int x,i,divisori;
    
    printf("Inserisci il numero da controllare: ");
    scanf("%d",&x);
    
    i=1;
    divisori=0;
    while (i<=x)
    {
        if (x%i==0) divisori++; 
        i++;
        
        if (divisori>2) 
        {
            printf("\nIl numero inserito non e' primo\n\n"); 
            system("PAUSE");
            return;
        }
    }
    
    if (x!=0) printf("\nIl numero inserito e' un numero primo\n\n");
    else printf("\nIl numero inserito non e' primo\n\n");
    
    system("PAUSE");
}  
