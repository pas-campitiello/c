// Domanda 4 - 2ª prova in itinere - 4 febbraio 2005

#include<stdio.h>
#define N 30

char * ConcatenaStringhe(char [], char []); // Il nome dei parametri non è obbligatorio nei prototipi

int main()
{
     char stringa1[N+1];
     char stringa2[N+1];
     char *sC;
     
     printf("Inserisci la prima stringa: ");
     gets(stringa1);
     printf("Inserisci la seconda stringa: ");
     gets(stringa2);
     
     sC = ConcatenaStringhe(stringa1,stringa2);
     
     printf("Concatenata dal MAIN: %s\n",sC);
     
     free(sC);
     
     printf("\n");
     system("pause");          
}

char * ConcatenaStringhe(char str1[], char str2[]) // Il nome dei parametri è obbligatorio nel codice del sottoprogramma
{
     char *strConcatPTR;
     int i,j;
         
     if ( strConcatPTR = malloc ( ( strlen(str1)+ strlen(str2) + 1 ) * sizeof(char) ) )
     {
          for (i=0; str1[i]!='\0'; i++) *(strConcatPTR + i) = str1[i];
          for (j=0; str2[j]!='\0'; i++, j++) *(strConcatPTR + i) = str2[j];
     
          *(strConcatPTR + i) = '\0';
     
          printf("\nConcatenata dal SOTTOPROGRAMMA: %s\n",strConcatPTR);
     }
     else printf("\n\nMemoria esaurita!"); 
     
     return strConcatPTR;
}
