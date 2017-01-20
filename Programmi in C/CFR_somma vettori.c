//Campitiello Pasquale
//678542
//PC n° 10

#include <stdio.h>
#define N 5

int arrcmp(int uno[],int due[], int VALIDI1, int VALIDI2);

int main ()
{
    int sumCTRL,i,vet1[N],vet2[N],nVal1, nVal2;
    
// INSERIMENTO E CONTROLLO NUMERO DEI VALORI DA INSERIRE NEL PRIMO VETTORE
    printf("Quanti numeri vuoi inserire nel primo vettore? ");
    scanf("%d",&nVal1);

    while ((nVal1<0) || (nVal1>N))
    {
         printf("\nAttenzione! MAX %d valori! Quanti numeri vuoi inserire nel primo vettore? ",N);
         scanf("%d",&nVal1);
    }

// INSERIMENTO E CONTROLLO NUMERO DEI VALORI DA INSERIRE NEL PRIMO VETTORE
    printf("\nQuanti numeri vuoi inserire nel secondo vettore? ");
    scanf("%d",&nVal2);

    while ((nVal2<0) || (nVal2>N))
    {
         printf("\nAttenzione! MAX %d valori! Quanti numeri vuoi inserire nel secondo vettore? ",N);
         scanf("%d",&nVal2);
    }
    
    printf("\n");
    
// ACQUISIZIONE PRIMO VETTORE
    for (i=0; i<nVal1; i++)
    {
        printf("Inserire l'elemento n. %d del vettore1: ",i);
        scanf("%d",&vet1[i]);
    }
    
    printf("\n");

// ACQUISIZIONE SECONDO VETTORE    
    for (i=0; i<nVal2; i++)
    {
        printf("Inserire l'elemento n. %d del vettore 2: ",i);
        scanf("%d",&vet2[i]);
    }
    
    sumCTRL = arrcmp(vet1,vet2,nVal1,nVal2);

    if (sumCTRL==1) printf("\nLe somme degli elementi validi dei vettori sono uguali\n\n");
               else printf("\nLe somme degli elementi validi dei vettori sono diverse\n\n");
    
    system("PAUSE");
}

int arrcmp(int uno[],int due[],int VALIDI1,int VALIDI2)
{
    int j,sum1,sum2;
    
    sum1=0;
    sum2=0;
    for (j=0; j<VALIDI1; j++)
        sum1 = sum1 + uno[j];
    
    for (j=0; j<VALIDI2; j++)
        sum2 = sum2 + due[j];
         
    if (sum1==sum2) return 1;
    else return 0;
}
