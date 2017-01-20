#include <stdio.h>
#define N 10

int main()
{
    char P[N];
    int i,contLet,pal,NumCar;
    
    printf("Quanto e' lunga la stringa da controllare? (num. dei caratteri MAX=10) ");
    scanf("%d",&NumCar);
    
    printf("\n");    
    printf("Inserisci la stringa (%d caratteri): ",NumCar);
    scanf("%s",&P[0]);                 //==gets(P);  ma in questo caso la precedente scanf deve essere: scanf("%d%*d",&NumCar);
                                       //            deve acquisire P dopo NumCar e un INVIO; le istruzioni fra scanf e gets
    pal=NumCar/2;                      //            vengono eseguite dopo gets.
    for(i=0; i < ( (NumCar/2) ); i++)
        if (P[i]==P[(NumCar-1)-i]) pal--;
    
    if (pal==0) printf("\nLa stringa e' palindroma");
    else printf("\nLa stringa non e' palindroma");
    
    printf("\n\n");
    system("Pause");
}
