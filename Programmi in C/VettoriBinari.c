// Domanda 2 - 2ª prova in itinere - 4 febbraio 2005

#include <stdio.h>
#define LimVet 3

int domina(int arr1[], int arr2[]);

int main ()
{
    int vet1[LimVet],vet2[LimVet],i,num,CTRL;
    
    
    printf("- Caricare i vettori solo con 0 e 1 -\n\n");

// Carica e stampa di vet1
    i=0;
    do
    {
         printf("Elemento %d di vet1: ",i+1);
         scanf("%d",&num);
         if ((num==0)||(num==1)) 
         { 
             vet1[i] = num;
             i++;
         }
    }
    while(i<LimVet);
    printf("\nvet1[] = ");
    for(i=0; i<LimVet; i++) printf("%d ",vet1[i]);
    
// Carica e stampa di vet2
    printf("\n\n");
    i=0;
    do
    {
         printf("Elemento %d di vet2: ",i+1);
         scanf("%d",&num);
         if ((num==0)||(num==1))
         {
             vet2[i] = num;
             i++;
         }
    }
    while(i<LimVet);
    printf("\nvet2[] = ");
    for(i=0; i<LimVet; i++) printf("%d ",vet2[i]);

    CTRL = domina(vet1,vet2);
    
    if (CTRL == 1) printf("\n\n--> 1\n");
    else printf("\n\n--> 0\n");
    
    printf("\nIl programma restituisce 1 se gli array hanno gli 1 in ugual posizione\n");
    printf("ed il secondo array ha almeno un altro uno oltre a quelli gia' conteggiati,\n0 in caso diverso");
    
    printf("\n\n");
    system("PAUSE");
}

int domina(int arr1[], int arr2[])
{
    int contUNOarr1,contUNOarr2,i,contUguali,contExtra2;
/*
    // Conteggio degli '1' nel primo vettore
    contUNOarr1=0;
    for (i=0; i<LimVet; i++) if (arr1[i]==1) contUNOarr1++;
    printf("\n\nGli 1 nel primo array sono %d",contUNOarr1);

    // Conteggio degli '1' nel secondo vettore
    contUNOarr2=0;
    for (i=0; i<LimVet; i++) if (arr2[i]==1) contUNOarr2++;
    printf("\nGli 1 nel secondo array sono %d",contUNOarr2);
    
    if ((contUNOarr2 > contUNOarr1) && (contUNOarr1!=0))
    {
       // Conteggio degli '1' in ugual posizione in entrambi i vettori    
       contUguali=0;
       for(i=0; i<LimVet; i++) if ( (arr1[i]==arr2[i]==1) ) contUguali++;

       printf("\nGli '1' in ugual posizione in entrambi i vettori sono %d",contUguali);
    
       if (contUguali == contUNOarr1) return 1;
    }

    return 0;
*/
    contUguali = 0;
    cont Extra2 = 0;
    contUNOarr1 = 0;
    for(i=0; i<LimVet; i++)
    {
         if (arr1[i]==1) contUNOarr1++;    
         if (arr1[i]==arr2[i]==1) contUguali++;
         else if ((arr2[i]==1) && (arr1[i]==0)) contExtra2++;
    }
    
    if ((contExtra2>0) && (contUNOarr1==contUguali)) return 1;
    else return 0;
}
