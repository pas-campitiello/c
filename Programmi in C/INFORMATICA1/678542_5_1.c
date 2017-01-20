//Campitiello Pasquale
//678542

#include <stdio.h>
#define N 50

int main()
{
    char s[N+1];
    int i;
    
    printf("Scrivi la stringa: ");
    gets(s);//scanf("%s",s);
    
    i=0;
    while (s[i]!='\0') i++;
       
    printf("\nLa lunghezza della stringa e' %d",i);
    
    printf("\n\n");
    system("Pause");

}
