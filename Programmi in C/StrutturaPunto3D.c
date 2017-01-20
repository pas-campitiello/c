#include <stdio.h>

typedef struct {int x,y,z;} Punto_t;

void AcquisisciPunto(Punto_t *P);

int main()
{
    Punto_t Q;

    AcquisisciPunto(&Q);
    
    printf("\nx = %d  y = %d  z = %d",Q.x,Q.y,Q.z);
    
    printf("\n\n");
    system("Pause");
}

void AcquisisciPunto(Punto_t *P)
{
    do
    {
     printf("Inserisci la coordinata x: ");
     scanf("%d",&P->x);
    }
    while(P->x<=0);
    
    do
    {
     printf("Inserisci la coordinata y: ");
     scanf("%d",&P->y);
    }
    while(P->y<=0);
    
    do
    {
     printf("Inserisci la coordinata z: ");
     scanf("%d",&P->z);
    }
    while(P->z<=0);
}
