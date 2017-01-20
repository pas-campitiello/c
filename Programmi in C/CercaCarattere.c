//Campitiello Pasquale
//678542

#include <stdio.h>
#define Z 20

int indexOf(char stringa[],char carCerca, int x);

int main ()
{
    char s[Z+1],c;
    int n,trova,L;
    
    printf("Inserisci la stringa: ");
    gets(s);
   
    printf("Inserisci il carattere da cercare: ");
    scanf("%s",&c);
    
    do
    {
        printf("Inserisci il numero di caratteri in cui cercare (MAX %d): ",Z);
        scanf("%d",&n);
    }    
    while ((n<0)||(n>Z));
    
    trova = indexOf(s,c,n);
    
    if (trova!=-1) printf("\nIl carattere [%c] e' stato trovato in posizione %d.",c,trova+1);
              else printf("\nIl carattere [%c] NON e' stato trovato",c);
    
    printf("\n\n");
    system("PAUSE");
}

int indexOf(char stringa[],char carCerca, int x)
{
    int i;
    
    for (i=0; i<x; i++)
        if (stringa[i]==carCerca) return i;
    
    return -1;
}
