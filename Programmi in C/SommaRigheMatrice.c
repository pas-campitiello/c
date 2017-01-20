// Domanda 1 - 2ª prova in itinere - 30 gennaio 2004

#include <stdio.h>
#define R 20
#define C 20

void StampaMat(int Mstamp[][C],int righe,int col);
int CTRL_sommaRighe(int m[][C],int R_ut,int C_ut);

int main()
{
    int righeUtente,colonneUtente,Mat[R][C],i,j,CTRLris;

// ACQUISIZIONE DEL NUMERO DI RIGHE e COLONNE DELLA MATRICE
    printf("Inserire il numero di RIGHE della matrice da caricare: ");
    scanf("%d",&righeUtente);
    while ((righeUtente<1) || (righeUtente>R))
    {
          printf("Il numero delle righe della matrice deve essere compreso tra 1 e %d!",R);
          printf("\nInserire il numero di RIGHE della matrice da caricare: ");
          scanf("%d",&righeUtente);
    }

    printf("Inserire il numero di COLONNE della matrice da caricare: ");
    scanf("%d",&colonneUtente);
    while ((colonneUtente<1) || (colonneUtente>C))
    {
          printf("Il numero delle colonne della matrice deve essere compreso tra 1 e %d!",C);
          printf("\nInserire il numero di COLONNE della matrice da caricare: ");
          scanf("%d",&colonneUtente);
    }

// CARICAMENTO MATRICE    
    printf("\n");
    
    for(i=0; i<righeUtente; i++)
     for(j=0; j<colonneUtente; j++)
     {
          printf("Elemento [%d][%d]: ",i,j);
          scanf("%d",&Mat[i][j]);
     }
    
// STAMPA MATRICE PRIMA DEL CONTROLLO
    printf("\nLa matrice creata e':\n");
    StampaMat(Mat,righeUtente,colonneUtente);
    
    CTRLris = CTRL_sommaRighe(Mat,righeUtente,righeUtente);
    
    if (CTRLris) printf(" --> 1 \n\nL'ultimo elemento di ciascuna riga e' pari alla somma di tutti\ngli altri elementi della riga stessa");
    else printf(" --> 0 \n\nAlmento in una riga l'ultimo elemento non e' pari alla somma di tutti\ngli altri elementi (della riga stessa)");
    
    printf("\n\n");
    system("Pause");
}


int CTRL_sommaRighe(int m[][C],int R_ut,int C_ut)
{
    int i,j,sum;
    
    for(i=0; i<R_ut; i++)
    {
       sum = 0;
       for(j=0; j<C_ut-1; j++) sum = sum + m[i][j];
       
       if (sum != m[i][j]) return 0;
    }
    
    return 1;
}

void StampaMat(int Mstamp[][C],int righe,int col)
{
    int i,j;
    
    for(i=0; i<righe; i++)
    { 
         for(j=0; j<col; j++)
         printf("%d ",Mstamp[i][j]);
         
         printf("\n");
    }
    printf("\n");
}
