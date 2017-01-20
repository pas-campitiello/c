#include <stdio.h>
#define ORD 20

int main ()
{
    int ordUtente,matrice[ORD][ORD],ruotata[ORD][ORD],i,j;
    
    printf("Inserire l'ordine della matrice da caricare: ");
    scanf("%d",&ordUtente);
    while ((ordUtente<1) || (ordUtente>20))
    {
          printf("L'ordine della matrice deve essere compreso tra 1 e 20!");
          printf("\nInserire l'ordine della matrice da caricare: ");
          scanf("%d",&ordUtente);
    }
    
    printf("\n");
    
    for(i=0; i<ordUtente; i++)
     for(j=0; j<ordUtente; j++)
     {
          printf("Elemento [%d][%d]: ",i,j);
          scanf("%d",&matrice[i][j]);
     }
    
    printf("\nLa matrice e':\n");
    for(i=0; i<ordUtente; i++)
    { 
     for(j=0; j<ordUtente; j++)
          printf("%d ",matrice[i][j]);
     printf("\n");
    }
    
// Salvataggio della ruotata
    
    for(i=0; i<ordUtente; i++) 
     for(j=0; j<ordUtente; j++)
          ruotata[j][(ordUtente-1)-i]=matrice[i][j];
    
// Stampa della ruotata
    printf("\n\nLa matrice ruotata di 90 gradi verso destra e':\n");
    for(i=0; i<ordUtente; i++)
    { 
     for(j=0; j<ordUtente; j++)
          printf("%d ",ruotata[i][j]);
     printf("\n");
    }
    
// Stampa della ruotata senza salvataggio in un altra matrice
    printf("\n\nLa matrice (non salvata) ruotata di 90 gradi verso destra e':\n");
    for(i=0; i<ordUtente; i++)
    { 
     for(j=ordUtente-1; j>=0; j--)
          printf("%d ",matrice[j][i]);
     printf("\n");
    }
    
    printf("\n\n");
    system("Pause");
}
