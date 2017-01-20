#include <stdio.h>

int main()
{
    int a,b,c;
    
    printf("Inserire a: ");
    scanf("%d",&a);
    
    printf("Inserire b: ");
    scanf("%d",&b);
    
    printf("Inserire c: ");
    scanf("%d",&c);
    
    if (a==b==c) printf("\n\n1o controllo: I NUMERI SONO TUTTI UGUALI");
            else printf("\n\n1o controllo: I NUMERI SONO DIVERSI");
    
    // L'uguaglianza sopra è verificata solo se i primi due sono uguali e l'ultimo è 1.
    // Perchè per es. 3=3=1?. Il compilatore parte da 3=3? VERO, quindi restituisce 1,
    // tale risultato viene a sua volta confrontato con l'ultima condizione, ossia 1=1? VERO
    // quindi restituisce 1; di conseguenza l'intera condizione è verificata e l'IF esegue
    // l'istruzione specificata per il VERO.
    
    if ((a==b) && (a==c)) printf("\n\n2o controllo: I NUMERI SONO TUTTI UGUALI\n\n");
                     else printf("\n\n2o controllo: I NUMERI SONO DIVERSI\n\n");

    
    system("Pause");
}
