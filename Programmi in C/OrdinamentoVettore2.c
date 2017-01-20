#include <stdio.h>
#define LimVet 10

int main ()
{
    int vet[LimVet],temp,i,j;
    char s;
    
    for (i=0;i<LimVet; i++)
    {
        printf("Elemento %d: ",i+1);
        // (1) scanf("%d",&vet[i]);
        scanf("%d%*c", &vet[i]);
    }
    
   // (1) Se è stata messa la SCANF al (1) precedente deve essere inserita anche quest'altra SCANF 
   // scanf("%c",&s);     // che serve per evitare che la successiva scanf legga l'INVIO dato dopo l'ultimo elemento inserito
   // La soluzione suggerita dal libro "C Corso completo di programmazione " - D&D è scanf("\n%c", &s);
    
    printf("\nIn che senso si vuole ordinare il vettore? (c = crescente; d = decrescente) ");
    scanf("%s",&s);
    
    while ((s!='c') && (s!='C') && (s!='d') && (s!='D'))
    {
          printf("\nERRORE! Inserire 'c' (= crescente) oppure 'd' (= decrescente):  ");
          scanf("%s",&s);
    }
    
    if ((s=='c') || (s=='C'))
    {
     for (i=0;i<LimVet;i++)
      for (j=i+1;j<LimVet;j++)
         if (vet[i]>vet[j])
          {
           temp=vet[i];
           vet[i]=vet[j];
           vet[j]=temp;
          }
    }
    else
    {
     for (i=0;i<LimVet;i++)
      for (j=i+1;j<LimVet;j++)
         if (vet[i]<vet[j])
          {
           temp=vet[i];
           vet[i]=vet[j];
           vet[j]=temp;
          }
    }
    
    if ((s=='c') || (s=='C')) printf("\nVettore ordinato in senso crescente:  ");
                       else printf("\nVettore ordinato in senso decrescente:  ");
        
    for (i=0;i<LimVet;i++) printf("%d  ",vet[i]);
    
    printf("\n\n");
    system("Pause");
}
 
