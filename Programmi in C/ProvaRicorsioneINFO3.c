#include <stdio.h>

int m = 4;
int n = 16;

int main()
{
    int m = 100;
    if (n>0 && m >83) 
    {
       printf ("INIZIO ::>  m = %d\n",m);
       m = f();       
    }
    else m = 0;
    
    printf ("FINE ::>  m = %d\n",m);
    system("PAUSE");
}

int f()
{
    int k = 3;
    int n = 4;
    
    if (m==1) 
    {
       printf ("Sono nell'IF di f() infatti m==1 ::>  m = %d\n",m);
       return 4;
    }
    else
    {
        printf ("Prima dell'ELSE di f() ::>  m=%d  n=%d  k=%d\n",m,n,k);
        n = m-- +k;
        printf ("Prima del return nell'ELSE di f() ::>  m=%d  n=%d  k=%d\n",m,n,k);
        return(n*f());
    } 
}
