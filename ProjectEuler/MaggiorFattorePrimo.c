#include <stdio.h>

int IsPrime(int n);
double sqrt(double x);

int main()
{ 
    double number = 183;//600 851 475 143; //13195;     // 71 è divisore primo
    int i=0, MaxFattPrimo=0;
    
    for (i=2; i<=((int)(number/2)); i++)
    {
        printf("\n%d- Radice %d:",i,(int) sqrt(number));
        //  non è pari          è divisore                   è primo        è il più grande
        if ( (i%2!=0) && (number-(((int)(number/i))*i)==0) && (IsPrime(i)) && (i>MaxFattPrimo) )  // Vietato l'operatore modulo "%" con un numero double
        {
            printf("\nDivisiore %d: ",i);
            printf("[OK]  %f-((%f/%d)*%d) = %f",number,number,i,i,number-((number/i)*i));
            if (IsPrime(i)) printf(" E' anche primo. ");
            
            MaxFattPrimo = i;
        }
    }
    
    printf("\n\nIl più grande fattore primo di %f è %d\n\n",number,MaxFattPrimo);
} 

int IsPrime(int n)
{
    int k;
    
    if (n==2) return 1;
    
    if ((n%2)==0) return 0;
   
    k = 3;
    while ( (n%k) && (k < (n+1)/2) ) k = k + 2;
   
    if ( (n%k) || (n==3) ) return 1;
   
    return 0;
}

double sqrt(double x)
{
    if ((x<0) || (!x)) return 0;
    
    double h=x/2;
    int i;
    for(i=0;i<64;i++)h=(h+(x/h))/2;
    return h;
} 
