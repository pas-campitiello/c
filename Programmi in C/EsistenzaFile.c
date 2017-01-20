#include <stdio.h>
#define N 50

int main ()
{
    FILE *fp;
    char nomef[N+1];
    
    printf("Inserisci il nome del file ");
    gets(nomef);
    
    fp=fopen(nomef,"r");
    
    if (fp!=NULL)    //anche   if (fp)...   oppure   if (fp=fopen(nomef,"r")...
    {
      printf("Il file indicato esiste");
      fclose(fp);
    }
    else printf("Il file indicato NON esiste");
    
    printf("\n\n");
    system("Pause");
}
