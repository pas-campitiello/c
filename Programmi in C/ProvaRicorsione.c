#include <stdio.h>

void StampaElem(int dato);
int Somma(int dato);

int main ()
{
    int n;
    int sum;
    
    do
    {
        printf("Inserisci il valore di n: ");
        scanf("%d",&n);
    }
    while (n<=0);
    
    printf("\nI primi %d numeri sono: ",n);
    StampaElem(n);

    sum = Somma(n);
    printf("\nLa somma dei primi %d numeri e': %d",n,sum);
    
    printf("\n\n");
    system("Pause");
}

void StampaElem(int dato)
{
     if (dato>0)
     {   
         StampaElem(dato-1);
         printf("%d ",dato);
         //StampaElem(dato-1);
     }
}

int Somma(int dato)
{
    if (dato==1) return 1;
    else return (dato + Somma(dato-1));
}
