#include <stdio.h>
#define N 5

void Assoluto(int *vet); // <-- Uguale a vet[]

int main ()
{
    int i,X[N];

    for (i=0; i<N; i++)
    {
        printf("Elemento [%d]: ",i);
        scanf("%d",&X[i]);
    }
    
    printf("\nIl vettore e':\n");
    for (i=0; i<N; i++) 
     printf("%d  ",X[i]);
     
    Assoluto(X);
    
    printf("\n\nTrasformando in valore assoluto tutti i suoi elementi sara':\n");
    for (i=0; i<N; i++) 
     printf("%d  ",X[i]);
    
    printf("\n\n");
    system("Pause");
}

void Assoluto(int *vet)
{
     int i;
     
     for (i=0; i<N; i++) 
      if ( *(vet+i)<0 ) *(vet+i) = - *(vet+i);
}

// UGUALE A   >>

/*
void Assoluto(int vet[])
{
     int i;
     
     for (i=0; i<N; i++) 
      if (vet[i]<0) vet[i] = - vet[i];
      
}
*/
