#include <stdio.h>

int main ()
{
    long precedente = 1; 
    long successivo = 2; 
    long sum, total = 2;    
    printf("%lu\n",precedente);        
    printf("%lu\n",successivo);
    
    while (successivo<4000000)
    {        
        sum = precedente + successivo;
        
                
        precedente = successivo;
        successivo = sum;
        
        if ( (sum%2==0) && successivo<4000000) 
        {
            printf("%lu <---\n",sum);
            total = total + sum;
        }
        else printf("%lu\n",sum);
    }
    
    printf("\n\nLa somma totale dei soli pari è %lu\n\n",total);
}
