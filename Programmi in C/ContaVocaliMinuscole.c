// Domanda 2 - 2ª prova in itinere - 30 gennaio 2004

#include <stdio.h>
#define MaxCar 10

int ContaVocaliMinuscole(char []);

int main()
{
    char stringa[MaxCar+1];
    int NumVocMin;
    
    printf("Inserisci la stringa: ");
    gets(stringa);
    
    NumVocMin = ContaVocaliMinuscole(stringa);
    
    printf("\nIl numero di vocali minuscole nella stringa %s e' %d",stringa,NumVocMin);
    
    printf("\n\n");
    system("PAUSE");
}

int ContaVocaliMinuscole(char s[])
{
    int i,c;
    
    c = 0;
    for (i=0; s[i]!='\0'; i++)
    if ( (s[i]=='a') || (s[i]=='e') || (s[i]=='i') || (s[i]=='o') || (s[i]=='u') ) c++;
    
    return c;
}
