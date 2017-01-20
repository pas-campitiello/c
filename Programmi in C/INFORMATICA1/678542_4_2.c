//Campitiello Pasquale
//678542

#include <stdio.h>
#include <math.h>
typedef struct { int x,y;} coordinate;
int main() {
    coordinate p1,p2,pmedio;
    float lunghezza;
    
    
    printf("inserire le coordinate del primo punto: \n");
    scanf("%d %d", &p1.x , &p1.y);
    
    printf("inserire le coordinate del secondo punto: \n");
    scanf("%d %d", &p2.x , &p2.y);
    
    pmedio.x = (p1.x + p2.x)/2;
    pmedio.y = (p1.y + p2.y)/2;
    
    lunghezza= sqrt(pow((p1.x - p2.x),2) + pow((p1.y - p2.y),2));
    
    printf("la lunghezza del segmento con un estremi %d %d e %d %d e' %g\n", p1.x, p1.y, p2.x, p2.y, lunghezza);
    printf("il suo punto medio ha coordinate %d %d\n",  pmedio.x, pmedio.y);
    
    system("PAUSE");
    
}
    
