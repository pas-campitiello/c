#include <stdio.h>
#define N 50
#define NomeFile "datiConnessione.txt"

void ConcatenaStringhe(char [], char [], char []);

int main()
{
    char nome[N+1];
    char password[N+1];
    char concatenamento[N+1];
    char sC[(2*N)+1];
    FILE *fp;
       
    printf("Inserire il nome dell'utente PostgreSQL: ");
    gets(nome); 
    
    printf("Inserire la password dell'utente PostgreSQL: ");
    gets(password);
    
    fp = fopen(NomeFile,"w"); 
    
    fprintf(fp,"%s\n",&nome); 
    
    fprintf(fp,"%s",&password); 

    fclose(fp);

    system("chmod +x installDBLINUX");      
    system("./installDBLINUX");
    
    printf("\n\n");
    system("Pause");
}

void ConcatenaStringhe(char strConcat[], char str1[], char str2[])
{
     int i,j;
     
     for (i=0; str1[i]!='\0'; i++) strConcat[i] = str1[i];
     for (j=0; str2[j]!='\0'; i++, j++) strConcat[i] = str2[j];
     
     strConcat[i]='\0';
     
     //printf("\nConcatenata dal SOTTOPROGRAMMA: %s\n",strConcat);
}
