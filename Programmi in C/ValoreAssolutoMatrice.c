#include <stdio.h>
#define N 3

void Assoluto(int *m, int ncol);               // Uguale a  void Assoluto(int m[][N]);  
void StampaMat(int Mstamp[][N],int ord);

int main ()
{
    int i,j,Mat[N][N];

// ACQUISIZIONE DATI MATRICE
    for(i=0; i<N; i++)
     for(j=0; j<N; j++)
     {
          printf("Elemento [%d][%d]: ",i,j);
          scanf("%d",&Mat[i][j]);
     }

// STAMPA PRIMA DELLA MODIFICA    
    printf("\nLa matrice prima della modifica e':\n");
    StampaMat(Mat,N);

// CHIAMATA AL SOTTOPROGRAMMA Assoluto
    Assoluto(&Mat[0][0],N);                    // Uguale a  Assoluto(Mat);

// STAMPA DOPO LA MODIFICA 
    printf("\nLa matrice DOPO la modifica e':\n");
    StampaMat(Mat,N);
    
    printf("\n\n");
    system("Pause");
}

void Assoluto(int *m, int ncol)
{
     int i,j;
     
     for (i=0; i<N; i++) 
      for (j=0; j<N; j++)  
       if ( *(m + (i*ncol + j)) <0 ) *(m + (i*ncol + j)) = - *(m + (i*ncol + j)); // Uguale a  if (m[i][j]<0) m[i][j] = - m[i][j];
}

void StampaMat(int Mstamp[][N],int ord)
{
    int i,j;
    
    for(i=0; i<ord; i++)
    { 
         for(j=0; j<ord; j++)
         printf("%d ",Mstamp[i][j]);
         
         printf("\n");
    }

    printf("\n");
}
