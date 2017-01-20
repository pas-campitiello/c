#include <stdio.h>
#include <math.h>

typedef struct{int x,y;} punto;

int main ()
{                
    punto P1,P2;
    int i,L1,L2;    

    do{
       printf("\nATTENZIONE! \nSi opera nel primo quadrante quindi le coordinate devono essere tutte positive!\n\n");
    
       printf("PUNTO P1 ----\n");
       printf("x = ");
       scanf("%d",&P1.x);
    
       printf("y = ");
       scanf("%d",&P1.y);
       
       printf("\nPUNTO P2 ----\n");
       printf("x = ");
       scanf("%d",&P2.x);
    
       printf("y = ");
       scanf("%d",&P2.y);
      }
    while ((P1.x<0) || (P1.y<0) || (P2.x<0) || (P2.y<0));
    
    if ((P1.x-P2.x)<0) L1=-1*(P1.x-P2.x);
    else L1=(P1.x-P2.x);
    
    if ((P1.y-P2.y)<0) L2=-1*(P1.y-P2.y);
    else L2=(P1.y-P2.y);
    
    if (L1==L2)
              {
               printf("\nIl poligono sotteso fra i punti P1(%d,%d) e P2(%d,%d) e' un quadrato",P1.x,P1.y,P2.x,P2.y);
               printf("\nPerimetro = %d    Area = %.0f\n\n",(L1*4),pow(L1,2));
              }
    else 
              {
               printf("\nIl poligono sotteso fra i punti P1(%d,%d) e P2(%d,%d) e' un rettangolo",P1.x,P1.y,P2.x,P2.y);
               printf("\nPerimetro = %d    Area = %d\n\n",((L1+L2)*2),(L1*L2));
              }
              
    system("pause");
}
