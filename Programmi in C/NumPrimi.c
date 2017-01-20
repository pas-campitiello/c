#include <stdio.h>

int IsPrime(int n);
int main()
{
    int x,i,c;
    
    printf("Quanti numeri primi vuoi sapere a partire da 0? ");
    scanf("%d",&x);
    
    c=0;
    printf("\n");
    for (i=0; i<x; i++)
     if ( IsPrime(i) )
     {
          c=c+1;
          printf("[%d] ",i);
     }
    
    printf("\n\nI numeri primi trovati sono %d",c);
    
    printf("\n\n");
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
