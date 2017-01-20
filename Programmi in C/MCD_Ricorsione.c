#include <stdio.h>

int MCDcalc(int dato1,int dato2);

int main ()
{
    int n1,n2;
    int x;
    
    do
    {
        printf("Inserisci il primo numero: ");
        scanf("%d",&n1);
    }
    while (n1<0);
    
    do
    {
        printf("Inserisci il secondo numero: ");
        scanf("%d",&n2);
    }
    while (n2<0);
    
    if ((n1==0) || (n2==0)) x=-1;
    else x = MCDcalc(n1,n2);
    
    if (x<0) printf("\nIl MCD non esiste: uno o entrambi i dati inseriti e' 0!");
    else printf("\nIl MCD di %d e %d e': %d ",n1,n2,x);
    
    printf("\n\n");
    system("Pause");
}

int MCDcalc(int dato1,int dato2)
{   
    if (dato1==dato2) return dato1;
    else if (dato1>dato2) return MCDcalc((dato1-dato2),dato2);
         else return MCDcalc(dato1,(dato2-dato1));
}
