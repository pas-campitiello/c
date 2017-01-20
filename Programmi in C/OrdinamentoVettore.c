#include <stdio.h>
#define LimVet 5

int main ()
{
    int vet[LimVet],temp,i,j;
    
    for (i=0;i<LimVet;i++)
    {
        printf("Inserisci il numero di posizione %d: ",i+1);
        scanf("%d",&vet[i]);
    }
    
    for (i=0;i<LimVet;i++)
     for (j=i+1;j<LimVet;j++)
      if (vet[i]>vet[j])
         {
          temp=vet[i];
          vet[i]=vet[j];
          vet[j]=temp;
         }
    
    printf("\nVettore ordinato:  ");
    
    for (i=0;i<LimVet;i++)
        printf("%d  ",vet[i]);
    
    printf("\n\n");
    
    system("Pause");

}
 
