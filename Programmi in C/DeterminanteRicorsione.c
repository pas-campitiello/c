#include <stdio.h>
#define ORD 20

int Determinante(int m[][ORD],int O_ut);

int main()
{
    int ordUtente,Mat[ORD][ORD],i,j,delta;

    printf(":::: CALCOLO DEL DETERMINANTE DI UNA MATRICE CON LA RICORSIONE ::::\n\n");
    
// ACQUISIZIONE DELL'ORDINE DELLA MATRICE
    printf("Inserire l'ordine della matrice da caricare: ");
    scanf("%d",&ordUtente);
    while ((ordUtente<1) || (ordUtente>ORD))
    {
          printf("L'ordine della matrice deve essere compreso tra 1 e %d!",ORD);
          printf("\nInserire l'ordine della matrice da caricare: ");
          scanf("%d",&ordUtente);
    }

// CARICAMENTO MATRICE    
    printf("\n");
    
    for(i=0; i<ordUtente; i++)
     for(j=0; j<ordUtente; j++)
     {
          printf("Elemento [%d][%d]: ",i,j);
          scanf("%d",&Mat[i][j]);
     }

// STAMPA MATRICE
    printf("\n");
    for(i=0; i<ordUtente; i++)
    { 
         for(j=0; j<ordUtente; j++)
         printf("%d ",Mat[i][j]);
         
         printf("\n");
    }
    
// CHIAMATA AL SOTTOPROGRAMMA
    
    delta = Determinante(Mat,ordUtente);
    
    printf("%d",delta);
    
    printf("\n\n");
    system("Pause");
}


int Determinante(int m[][ORD],int O_ut)
{
    int i;
    
    for (i=0; i<O_ut; i++)
     if (O_ut == 2) return ( (m[0][i] * m[1][i+1]) - (m[1][i] * m[0][i+1]) );
     else return Determinante(m,(O_ut-1));   
     
     //return 0;
}

