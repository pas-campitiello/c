#include <stdio.h>

int main ()
{
    long i=0;
    int j=0, trovato=0;
    
    for(i=20; trovato==0; i++)
    {
        trovato = 1;
        for(j=1; j<=20 && trovato==1; j++)
        {
            if (i%j!=0) 
            {
                if (j>17) printf("i = %lu -> KO per %d\n",i,j);
                trovato = 0;
            }
        }
        
        if (trovato==1) printf("Trovato!!!! Il numero più piccolo divisibile per tutti i numeri da 1 a 20 è: %lu\n\n", i);
    }
}
