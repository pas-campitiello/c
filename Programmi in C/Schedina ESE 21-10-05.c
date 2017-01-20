#include <stdio.h>
#define NP 3

struct SP 
{int golC,golFC;
 char ris;};

typedef struct SP Partita;

int main()
{
    Partita partite[NP];
    int Max,diff,i,j,TotCasa,TotFuori;
    char StatGol[100][2];
    
    TotCasa=0;
    TotFuori=0;
    for (i=0; i<NP; i++)
    {
        printf("PARTITA %d Gol squadra in casa ",i+1);
        scanf("%d",&partite[i].golC);
        
        printf("PARTITA %d Gol squadra fuori casa ",i+1);
        scanf("%d",&partite[i].golFC);
        
        TotCasa=TotCasa+partite[i].golC;
        TotFuori=TotFuori+partite[i].golFC;
        printf("\n");
    }
    
    for (i=0; i<NP; i++)
        if (partite[i].golC==partite[i].golFC) partite[i].ris='X';
        else if (partite[i].golC>partite[i].golFC) partite[i].ris='1';
             else partite[i].ris='2';
    
    for (i=0; i<NP; i++) printf("\nIl risultato della partita %d e': %c\n",i+1,partite[i].ris);

// GRAFICO 1    
    printf("\n\n   TOT Gol in casa: ");
    for (i=0; i<TotCasa; i++)
        printf("*");
    
    printf("\nTOT Gol fuori casa: ");
    for (i=0; i<TotFuori; i++)
        printf("*");

// GRAFICO 2 con matrice
    printf("\n\n");
    if (TotCasa>=TotFuori) 
    {
       Max=TotCasa;
       diff=TotCasa-TotFuori;
       printf("GolC GolFC");
    }
    else 
    {
       Max=TotFuori;
       diff=TotFuori-TotCasa;
       printf("GolFC GolC");
    }

    for (i=0; i<Max; i++) StatGol[i][0]='*';
    
    for (i=Max-1; i>=diff; i--) StatGol[i][1]='*';
    
    printf("\n\n");
    for (i=0; i<Max; i++)
    { 
        for (j=0; j<2; j++)
            if (StatGol[i][j]=='*') printf(" %c     ",StatGol[i][j]);
        
        printf("\n");  
    }

// GRAFICO 3 senza matrice

    printf("\n\n");
    if (TotCasa>=TotFuori) 
    {
       Max=TotCasa;
       printf("GolC GolFC");
    }
    else 
    {
       Max=TotFuori;
       printf("GolFC GolC");
    }
    printf("\n");
    if (TotCasa>=TotFuori) diff=TotCasa-TotFuori;
                      else diff=TotFuori-TotCasa;

    for (i=0; i<Max; i++)
        if (i!=diff) printf("\n *");
        else
        {
            for(j=i; j!=Max; j++) printf("\n *      *");
            i=Max;
        }
    
    printf("\n\n");
    system("Pause");
}
