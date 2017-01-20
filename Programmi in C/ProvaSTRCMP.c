#include<stdio.h>

int main()
{
    char SEQ[256];
    
    printf("Inserisci ");
    gets(SEQ);

    if ( strcmp(SEQ,"quit")==0 ) printf("\n\nUGUALE A QUIT\n\n");
    else printf("\n\nNON uguale\n\n");

   
    system("PAUSE");
}
