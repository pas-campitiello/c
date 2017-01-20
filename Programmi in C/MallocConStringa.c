#include <stdio.h>
#define N 30

int main ()
{
    char stringa1[N+1];
    char *p;
    int i;
     
    printf("Inserisci la prima stringa: ");
    gets(stringa1);
    
    if (p = malloc( strlen(stringa1) * sizeof(char)))
    {
         for (i=0; stringa1[i]!='\0'; i++) *(p+i) = stringa1[i];
         
         printf("\nStampa della stringa inserita (dal puntatore): ");
         
         for (i=0; i<strlen(stringa1); i++) printf("%c",*(p+i));
          
         free(p);
    }
    else printf("\n\nMemoria esaurita!");
    
    printf("\n\n");
    system("Pause");
}
