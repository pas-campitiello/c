#include <stdio.h>
long minsotm(long n,long min)
{
    if(n<3)return n;
    long m=min;
    while(m<=(n/m))
    {
        if(!(n%m))return m;
        m++;
    }
    return n;
}        
int main(int argc, char **args)
{
    long n,div=2;
    printf("Inserisci un numero : ");
    scanf("%ld",&n);
    while(n!=1)
    {
        printf("%ld\n",div=minsotm(n,div));
        n/=div;
    }
}     
