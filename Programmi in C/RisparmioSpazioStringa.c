#include<stdio.h>
#define M 10

char *strMem(char *s);

int main()
{
    int x;
    char stringa[M+1];
    char *newstr;
     
    printf("Inserisci la stringa: ");
    gets(stringa);

    printf("\nLa stringa inserita e':\n--- %s ---\n",stringa);
    printf("\nLa stringa dopo la chiamata a ""strMem"" e':\n--- %s ---",strMem(stringa));
    
    printf("\n\n");
    system("pause");          
}

char *strMem(char *s)
{
    int i;
    char *p;
     
    if ( p = (char *) malloc(sizeof(char)*strlen(s)+1) )          
    {
         for (i=0; s[i]!='\0'; i++)
          *(p+i)=s[i];
         
         *(p+i)='\0';
    }
    else printf("Memoria esaurita!\n");
     
    return p;
}
