#include <stdio.h>
#include <math.h>
typedef struct {float x,y;} Punto;
typedef struct {Punto iniz,fine,medio;
                float lung;} Segmento;

int main ()
{
    Segmento linea;    
    
    printf("PUNTO P1 ----\n");
    printf("x = ");
    scanf("%f",&linea.iniz.x);
    printf("y = ");
    scanf("%f",&linea.iniz.y);
       
    printf("\nPUNTO P2 ----\n");
    printf("x = ");
    scanf("%f",&linea.fine.x);
    printf("y = ");
    scanf("%f",&linea.fine.y);
    
    linea.medio.x=(linea.iniz.x + linea.fine.x)/2;
    linea.medio.y=(linea.iniz.y + linea.fine.y)/2;
    linea.lung=sqrt( pow((linea.iniz.x - linea.fine.x),2) + pow((linea.iniz.y - linea.fine.y),2) );
    
    printf("\nDATI DEL SEGMENTO:");
    printf("\nPunto iniziale = (%.3f , %.3f)",linea.iniz.x,linea.iniz.y);
    printf("\n  Punto finale = (%.3f , %.3f)",linea.fine.x,linea.fine.y);
    printf("\n   Punto medio = (%.3f , %.3f)",linea.medio.x,linea.medio.y);
    printf("\n     Lunghezza = %.3f",linea.lung);
    
    printf("\n\n");
    system("Pause");
}
