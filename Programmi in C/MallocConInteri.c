#include <stdio.h>
#define M 5

int main ()
{
    int N[M],i;
    int *p;

    for (i=0; i<M; i++)
    {
        printf("Inserisci il numero: ");
        scanf("%d",&N[i]);
    }
    
    if (p = malloc(M * sizeof(int)))
    {
          for (i=0; i<M; i++) *(p+i) = N[i]+1;

          printf("\nStampa dei numeri inseriti incrementati di 1 (dal puntatore): ");
          for (i=0; i<M; i++) printf("%d ",*(p+i)); 
          
          free(p);
    }
    else printf("\n\nMemoria esaurita!"); 
    
    printf("\n\n");
    system("Pause");
}
