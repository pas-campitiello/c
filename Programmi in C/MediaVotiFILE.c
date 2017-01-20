#include <stdio.h>
#define NV 10

int main ()
{
    FILE* fpp;
    int i,somma,num,voto[NV];
    float media;
    
    do
    {
          printf("Inserisci il numero di voti da acquisire: ");
          scanf("%d",&num);
    }
    while ((num<0) || (num>10));    //<-- (num>10) perch� se si dovesse modificare il programma la modifica � solo l�
    
    fpp = fopen("Voti.txt","r"); 
    
    i=0;
    
    if (fpp)
    {
        fscanf(fpp,"%d",&voto[i]);
        
        while (!feof(fpp))
        {
            i++;
            fscanf(fpp,"%d",&voto[i]);
        }
        
        if ((i+1)<num)
        {
            printf("\nATTENZIONE! Si sono potuti caricare solo %d voti.\n",i+1);
            num = i+1;            //<-- in num ora ci sar� il numero effettivo (cio� senza partire da 0) dei voti caricati
        }
        
        fclose(fpp);
    }
    else 
    {
         printf("\nERRORE NELL'APERTURA DEL FILE!\n\n");
         system("PAUSE");
         return 0;
    }
    
    somma=0;
    
    printf("\nI numeri letti sono: \n");
    for (i=0; i<num; i++)
    {
        printf("%d ",voto[i]);
        somma = somma + voto[i];
    }
    
    media = (float)somma/num;
    
    printf("\n\n%d La media dei voti e' %f",somma,media);
 
    printf("\n\n");
    system("PAUSE");
}
