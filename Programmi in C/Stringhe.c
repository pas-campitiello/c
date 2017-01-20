#include <stdio.h>
#define N 20

int main ()
{
    char str1[N+1],str2[N+1];
    int i,j;
    char *e;
    
    gets(str1);
    gets(str2);
    gets(&e);
    
    j=0;
    
    for (i=0;str1[i]!='\0' && str2[i]!='\0' && j<4; i++)
        if (str1[i]!=str2[i]) j++;
    
    for (; str1[i]!='\0' && j<4; i++) j++;

    for (; str2[i]!='\0' && j<4; i++) j++;    
    
    if (j>=4) printf("\nLa stringa '%s' differisce dalla stringa '%s' per almeno 4 caratteri", str1,str2);
    else printf("\n0");
    
    
    printf("\n\n");
    system("Pause");
}
