#include <stdio.h>

int main ()
{
    int i; 
    double sum;
    
    for(i=0; i<1000; i++)
    {
        if ( (i%3==0) || (i%5==0) )
        {
            printf("%d ",i);
            sum = sum + i;
        }
    }
    
    printf("\n\nLa somma totale è %f\n\n",sum);
}    
