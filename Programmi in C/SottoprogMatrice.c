// Ricevuta in ingresso una matrice di numeri interi, questo programma restituisce 
// la posizione dell'ultimo numero primo trovato, con valore assoluto minimo.

#include <stdio.h>
#define N 20

int Assoluto(int num);
int PrimoCTRL(int x);
void PosizioneMinAssPrimo(int m[][N],int ord, int *R, int *C);

int main ()
{
    int ordUtente,Mat[N][N],i,j,posR,posC;

// ACQUISIZIONE ORDINE MATRICE DA UTENTE
    printf("Inserire l'ordine della matrice da caricare: ");
    scanf("%d",&ordUtente);
    while ((ordUtente<1) || (ordUtente>20))
    {
          printf("L'ordine della matrice deve essere compreso tra 1 e 20!");
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
    
/* //STAMPA
    printf("\nLa matrice e':\n");
    for(i=0; i<ordUtente; i++)
    { 
     for(j=0; j<ordUtente; j++)
          printf("%d ",Mat[i][j]);
     printf("\n");
    }
*/
    
    posR=-1;
    posC=-1;
    
    PosizioneMinAssPrimo(Mat,ordUtente,&posR,&posC);
    
    if (posR==-1) printf("\nNella matrice inserita non esistono numeri primi!\n\n");
    else printf("\nPosizione dell'ultimo numero primo trovato, con valore assoluto minimo = [%d][%d]\n\n",posR,posC);
    
    system("Pause");
    
}

int Assoluto(int num)
{
    if (num<0) return -num;
    else return num;
}

int PrimoCTRL(int x)
{
    int i,divisori;

    i=1;
    divisori=0;
    while (i<=x)
    {
        if (x%i==0) divisori++; 
        i++;
        
        if (divisori>2) return 0;
    }
             
    if (x!=0) return 1;
    else return 0;
}

void PosizioneMinAssPrimo(int m[][N],int ord, int *R, int *C)
{
    int minAss,i,j,p;
    
    p=0;
    for(i=0; i<ord; i++) 
     for(j=0; j<ord; j++)
     {   
         if ( PrimoCTRL(Assoluto(m[i][j]))==1 )
           if (!p)
           {
               minAss = Assoluto(m[i][j]);
               *R=i; 
               *C=j;
               p=1;
           }
           else if (Assoluto(m[i][j]) <= minAss)  //<-- minore o UGUALE (<=) perchè se esistono più MinAssPrimo 
                {                                 // deve restituire l'ultimo trovato
                    minAss = Assoluto(m[i][j]);
                    *R=i; 
                    *C=j;
                }
     }
}      
