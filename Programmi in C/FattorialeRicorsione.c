#include <stdio.h>

int Fattor(int dato);

int main ()
{
    int n;
    long f;
    
    do
    {
        printf("Inserisci il numero da fattorializzare: ");
        scanf("%d",&n);
    }
    while (n<0);
    
    f = Fattor(n);
    printf("\nIl fattoriale di %d e': %d ",n,f);
    
    printf("\n\n");
    system("Pause");
}

int Fattor(int dato)
{
    if ((dato==1) || (dato==0)) return 1;
    else return (dato * Fattor(dato-1));
}
