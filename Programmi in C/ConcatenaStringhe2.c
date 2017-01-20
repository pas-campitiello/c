// Domanda 4 - 2ª prova in itinere - 4 febbraio 2005

#include<stdio.h>
#define N 30

void ConcatenaStringhe(char [], char [], char []);

int main()
{
     char stringa1[N+1];
     char stringa2[N+1];
     char sC[(2*N)+1];

     printf("Inserisci la prima stringa: ");
     gets(stringa1);
     printf("Inserisci la seconda stringa: ");
     gets(stringa2);
     
     ConcatenaStringhe(sC,stringa1,stringa2);
     
     printf("Concatenata dal MAIN: %s",sC);
     // La stringa concatenata è stampabile anche dal MAIN perchè viene modificata
     // automaticamente (avendo passato l'indirizzo) nel sottoprogramma
     
     printf("\n\n");
     system("pause");
}

void ConcatenaStringhe(char strConcat[], char str1[], char str2[])
{
     int i,j;
     
     for (i=0; str1[i]!='\0'; i++) strConcat[i] = str1[i];
     for (j=0; str2[j]!='\0'; i++, j++) strConcat[i] = str2[j];
     
     strConcat[i]='\0';
     
     printf("\nConcatenata dal SOTTOPROGRAMMA: %s\n",strConcat);
}
