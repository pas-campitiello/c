#include <stdio.h>

int main ()
{
    long sumOfSquares=0, squareOfSum=0;
    int i;    
    
    for(i=0; i<=100; i++)
    {
        printf("%d\n",i*i);
        sumOfSquares = sumOfSquares + i*i;
    }
    
    printf("--------------------- Somma dei singoli quadrati: %lu\n",sumOfSquares);

    
    for(i=0; i<=100; i++)
    {
        printf("%d\n",i);
        squareOfSum = squareOfSum + i;
    }
    
    
    
    printf("--------------------- Quadrati della somma: %lu * %lu = ",squareOfSum,squareOfSum);
    squareOfSum = squareOfSum*squareOfSum;
    printf("%lu\n\n",squareOfSum);
    
    printf("Differenza: [somma dei singoli quadrati] - [quadrati della somma] = %lu\n\n",squareOfSum - sumOfSquares);
}
