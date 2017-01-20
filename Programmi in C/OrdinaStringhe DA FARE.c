#include <stdio.h>
int main()
{
    char str1[20],str2[20];
    int mag,i;
    
    printf("str1: ");
    gets(str1);
    printf("str2: ");
    gets(str2);
    
    mag = i = 0;
    while ((str1[i]!='\0') && (mag==0))
    {
        if (str1[i]>str2[i]) {mag = 1; printf("1");}
        if (str1[i]==str2[i]) {mag = 0; i++;}
        else {mag = 2; printf("2");}
    }
    
    if (mag == 1) printf("\n\n%s %s",str1,str2);
    else if (mag == 0) printf("\n\n%s %s STRINGHE UGUALI",str1,str2);
         else printf("\n\n%s %s",str1,str2);
    
   
    printf("\n\n");
    system("Pause");
}
