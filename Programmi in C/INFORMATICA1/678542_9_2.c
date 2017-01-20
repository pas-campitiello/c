#include <stdio.h>

void creaMatrice(int,int);
void inserisciMatrice(int *,int,int);

int main()
{
    int rUT,cUT;
        
    printf("Inserisci il numero di righe della matrice: ");
    scanf("%d",&rUT);
    
    printf("Inserisci il numero di colonne della matrice: ");
    scanf("%d",&cUT);
    
    creaMatrice(rUT,cUT);
    
    printf("\n\n");
    system("PAUSE");
    
}

void creaMatrice(int R, int C)
{
    int * p;
    
    p = (int *) malloc( R * C * sizeof(int));
    
    inserisciMatrice(p,R,C);
}

void inserisciMatrice(int * PTR,int nRig,int nCol)
{
    int i,j;
    FILE* matFile;
    
    for (i=0; i<nRig; i++)
     for (j=0; j<nCol; j++)
     {
         printf("Inserisci l'elemento [%d][%d] ",i,j);
         
         scanf("%d",( PTR + (i*nCol + j) ) );
     }    

// STAMPA
    printf("\n\nMatrice:\n\n");
    for (i=0; i<nRig; i++)
    {
         for (j=0; j<nCol; j++)
          printf("%d ",*( PTR + (i*nCol + j) ));  
         
         printf("\n");
    }

// Memorizzazione della matrice nel file Matrice.txt
    if ( matFile = fopen("Matrice.txt","w") )
    {
        for(i=0; i<nRig; i++)
         for(j=0; j<nCol; j++)    
          fprintf( matFile,"%d ",*( PTR + (i*nCol + j)) );
        
        fclose(matFile);
    }
    else printf("ERRORE NELLA CREAZIONE DEL FILE!\n\n");
}
