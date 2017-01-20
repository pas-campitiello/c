#include <stdio.h>

int main ()
{
    int N,i;
    int *p;

    printf("---- PROGRAMMA PER L'ALLOCAZIONE DINAMICA DELLA MEMORIA ----\n");
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d",&N);
    printf("\n");
    
   /* p = (int *) malloc(N * sizeof(int));                   <--|
      if (p != NULL)                                         <--|        */
    if (p = malloc(N * sizeof(int)))                // Uguale a |
    {
          for (i=0; i<N; i++)
          {
            printf("%d) Inserisci il numero: ",i); 
            scanf("%d",(p+i));
          }
          
          printf("\n");
          printf("Stampa in ordine inverso dei numeri inseriti: ");
          
          for (i--; i>=0; i--) printf("%d ",*(p+i)); 
          
          free(p);
    }
    else printf("\n\nMemoria esaurita!"); 
    
    printf("\n\n");
    system("Pause");
}
