// Domanda 1 - 2ª prova in itinere - 4 febbraio 2005

#include <stdio.h>
#define R 20
#define C 20

void StampaMat(int Mstamp[][C],int righe,int col);
void ModifMatrice(int m[][C],int R_ut,int C_ut);

int main()
{
    int righeUtente,colonneUtente,Mat[R][C],i,j;

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
    
    
// STAMPA MATRICE PRIMA DELLA MODIFICA
    printf("\nLa matrice prima della modifica e':\n");
    StampaMat(Mat,righeUtente,colonneUtente);
    

    if (righeUtente==1) printf ("La matrice non e' stata modificata (ha solo una riga!):\n");
    else 
    {
         ModifMatrice(Mat,righeUtente,colonneUtente);    // <-- uguale a ModifMatrice(&Mat,righeUtente,colonneUtente);
         printf("\nLa matrice dopo la modifica e':\n");
    }
    
    
// STAMPA MATRICE DOPO LA MODIFICA
    StampaMat(Mat,righeUtente,colonneUtente);
    
    printf("\n");
    system("Pause");
}


//___________ SOTTOPROGRAMMI ___________

void ModifMatrice(int m[][C],int R_ut,int C_ut)
{
    int i,j;

    for(i=1; i<R_ut; i++)
     for(j=0; j<C; j++)
      if (m[i-1][j]==1) m[i][j]=0;
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
