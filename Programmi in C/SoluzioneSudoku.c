#include <stdio.h>
#define ORD 20

int main ()
{
    int S[9][9],regione[9],i,j,k,r,c,st,num,err;
    
//Caricamento della soluzione Sudoku
    printf("Inserire la soluzione del Sudoku:\n");
    for(i=0; i<9; i++)
     for(j=0; j<9; j++)
     {
          printf("Elemento [%d][%d]: ",i,j);
          scanf("%d",&num);   
          S[i][j]=num;    
          while ((num<1) || (num>9))
          {
                printf("ATTENZIONE!\n Nel Sudoku ogni numero inserito deve essere compreso tra 1 e 9!");
                printf("\nElemento [%d][%d]: ",i,j);
                scanf("%d",&num);
                S[i][j]=num;
          }
     }
    
    err=0;
    
   println("\n");
   
// Controllo righe
    for(i=0; (i<9)&&(err!=1); i++)
      for(j=0; (j<8)&&(err!=1); j++)
        for(k=j+1; (k<9)&&(err!=1); k++)
          if (S[i][j]==S[i][k]) err=1;
    
    if (err==1) printf("\nRIGHE SBAGLIATE");
           else printf("RIGHE ESATTE");

// (Se le righe risultano esatte) --> Controllo colonne
    if (err==0)
    {
       for(i=0; (i<9)&&(err!=1); i++)
        for(j=0; (j<8)&&(err!=1); j++)
          for(k=j+1; (k<9)&&(err!=1); k++)
            if (S[j][i]==S[k][i]) err=1;

       if (err==1) printf("\nCOLONNE SBAGLIATE");
              else printf("\nCOLONNE ESATTE");
   
       // (Se le colonne risultano esatte) --> Controllo per regione
       if (err==0)
       {
          for(r=0; (r<9)&&(err!=1); r=r+3)
           for(c=0; (c<9)&&(err!=1); c=c+3)
           { 
             k=0;
            
             for(i=r; (i<r+3)&&(err!=1); i++) 
              for(j=c; (j<c+3)&&(err!=1); j++,k++) regione[k]=S[i][j];
       
             for(i=0; (i<8)&&(err!=1); i++)
              for(j=i+1; (j<9)&&(err!=1); j++)
               if (regione[i]==regione[j]) err=1;
           }
 
          if (err==1) printf("\nREGIONI SBAGLIATE");
                else printf("\nREGIONI ESATTE\n\n LA SOLUZIONE DEL SUDOKU E' ESATTA!!!\n\n");
       }
    }

    printf("\n\n");
    
// Stampa
    for(i=0; i<9; i++)
    { 
     for(j=0; j<9; j++)
          printf("%d ",S[i][j]);
     printf("\n");
    }
    
    printf("\n\n");
    system("PauSe");
}
