#include<stdio.h>

int main()
{
    int a, *b;
    
    //a = *b;
    a=33;
    b=123;
    
    printf("INDIR a = %d\n\n",*a);
    printf("a = *b = %d\n\n",b);
    
    system("PAUSE");
}
