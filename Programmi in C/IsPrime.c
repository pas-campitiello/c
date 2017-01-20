#include <stdio.h>

int IsPrime(int n);
int main()
{
    int x;
    
    printf("Inserisci il numero da controllare: ");
    scanf("%d",&x);
    
    if (IsPrime(x)==1) printf("\nIl numero inserito e' un numero primo\n\n");
    else printf("\nIl numero inserito non e' primo\n\n");
    
    system("PAUSE");
} 

int IsPrime(int n)
{
    int i;
    
    if (n==2) return 1;
    
    if ((n%2)==0) return 0;
   
    i = 3;
    while ( (n%i) && (i < (n+1)/2) ) i = i + 2;
   
    if ( (n%i) || (n==3) ) return 1;
   
    return 0;
}
