#include <stdio.h>
#define N 4
#define val 1

int main ()
{
    FILE* matFile;
    int i,r,c,num,cont,set,matrice[N][N];    
    
    matFile = fopen("Matrice.txt","r"); 

    if (matFile)
    {
        for(r=0; r<N; r++)
         for(c=0; c<N; c++)    
          fscanf(matFile,"%d",&matrice[r][c]);
        
        fclose(matFile);
    }
    else 
    {
         printf("ERRORE NELL'APERTURA DEL FILE!\n\n");
         system("PAUSE");
         return 0;
    }
    
    printf("Inserisci il numero da cercare nelle righe della matrice: ");
    scanf("%d",&num);
    
    printf("\n");
    
    set=0;
    
    for(r=0; r<N; r++)
    {
        cont=0;
        for(c=0; c<N; c++)
         if (matrice[r][c]==num) cont++;
        
        printf("Il numero di ricorrenze nella riga %d di %d e' %d\n",r,num,cont);
        
        if (cont>val)
        {
            set=1;
            for (i=0; i<N; i++)
             if (matrice[r][i]==num) matrice[r][i]=0;
        }   
    }
    
    if (set!=0)
    {
        printf("\nLa matrice modificata e':\n");
        for(r=0; r<N; r++)
        {
            for(c=0; c<N; c++)    
            printf("%d ",matrice[r][c]);
            printf("\n");
        }
    }
    else printf("\nLa matrice non e' stata modificata!\n");
    
    printf("\n");
    system("PAUSE");
}
