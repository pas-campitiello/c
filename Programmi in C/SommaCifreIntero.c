#include <stdio.h>

int main() 
{
    int n, somma;
    
    printf("Inserisci l'intero di cui vuoi sommare le cifre: ");
    scanf("%d",&n);
    
    printf("\nLa somma delle cifre di %d e' ",n);
    somma = 0;
    
    while(n > 0)
    {
        somma = somma + (n % 10);
        n = n / 10;
    }
    printf("%d",somma);
    
    printf("\n\n");
    system("PAUSE");
}
