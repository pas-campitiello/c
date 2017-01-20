#include <stdio.h>
#define N 50

int EsistenzaFile(char s[]);

int main ()
{
    int es;
    char nomef[N+1];
    
    printf("Inserisci il nome del file ");
    gets(nomef);
    
    es=EsistenzaFile(nomef);
    
    if (es) printf("Il file indicato esiste");
    else printf("Il file indicato NON esiste");
    
    printf("\n\n");
    system("Pause");
}

//----------- SOTTOPROGRAMMA --------------
int EsistenzaFile(char s[])
{
    FILE *fp;
       
    if (fp=fopen(s,"r")) 
    {
      fclose(fp);
      return 1;
    }
    else return 0;        
}
