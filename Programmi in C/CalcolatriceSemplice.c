#include <stdio.h>

int main ()
{
    int err;
    float a,b,ris;
    char op;
    
    scanf("%c %f %f",&op,&a,&b);
    
    if (op=='a') printf("== 'a'");
           else  printf("!= 'a'");
    
    getch();
    err=0;
    switch (op)
    {
           case '+': ris=a+b; break;
           case '-': ris=a-b; break;
           case '*': ris=a*b; break;
           case '/': if (b!=0) ris=a/b;
                     else {
                          err=1;
                          if (a!=0) printf("\nInfinito\n\n");
                          else printf("\nOperazione indeterminata\n\n");
                          }
                     break;
           default: err=1;
                    printf("\nOperatore non valido\n\n");
    }
    
    if (!err) printf("\n%f\n\n",ris);
    
    system("Pause");
}
