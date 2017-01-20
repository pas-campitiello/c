#include<stdio.h>

int main()
{
    int c;
    
    printf("Inserisci ");
    scanf("%d",&c);

    if (c>10) goto Mag10;
    else goto Min10;
          
Mag10: 
    printf("\n\nMaggiore di 10\n\n");
    goto fine;
    
Min10: 
    printf("\n\nMinore di 10\n\n");

fine:
    
    system("PAUSE");
}
