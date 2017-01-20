#include <stdio.h>

int Moltiplica(int, int);

int main()
{
    int num1,num2;
    int prod;
    
    printf("Inserisci il moltiplicando: ");
    scanf("%d",&num1);
    printf("Inserisci il moltiplicatore: ");
    scanf("%d",&num2);
    
    prod = Moltiplica(num1,num2);
    
    printf("\nIl prodotto fra %d e %d e': %d",num1,num2,prod);
    
    printf("\n\n");
    system("PAUSE");
}

int Moltiplica(int a, int b)
{
    if ( (a==0)||(b==0) ) return 0;
    else if ( (a==1)||(b==1) ) return (a+b-1);
         else return(a + Moltiplica(a,b-1));

    return ;
}
