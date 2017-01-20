#include <stdio.h>

int i=10;
int k=20;

int pippo(int *m);

int pippo(int *m)
{
     int *n = &m;
     
     int ASTERISCOn;
     
     ASTERISCOn=*n;
     
     printf("&i=%d  i=%d\n",&i,i);
     printf("&k=%d  k=%d\n",&k,k);
     printf("&m=%d  m=%d\n",&m,m);
     printf("&n=%d  n=%d  *n=%d\n",&n,n,ASTERISCOn);
     
     *(n) = 30;
     n++;
     *n = 40;
     
     ASTERISCOn=*n;
     
     printf("\n&i=%d  i=%d\n",&i,i);
     printf("&k=%d  k=%d\n",&k,k);
     printf("&m=%d  m=%d\n",&m,m);
     printf("&n=%d  n=%d  *n=%d\n",&n,n,ASTERISCOn);
     
     return m;
}


int main()
{
    /*int a, *b;
    
    //a = *b;
    b=123;
    
    printf("INDIR a = %d\n\n",&a);
    printf("a = *b = %d\n\n",b);
    */
    
    printf("\n%d %d %d\n",pippo(&i),i,k);

    system("PAUSE");
}

