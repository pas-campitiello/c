#include <stdio.h>

int main ()
{
    printf("%-13s%-10s%s\n","PRIMO","SECONDO","TERZO");
    printf("123456789012345678901234567890");
    printf("\n%s %-4s %s\n","PRIMO","STR","TERZO");
        // Col meno davanti alla stringa da stampare si posiziona il cursore nella posizione indicata [+1] a partire dalla prima
        // lettera a SINISTRA della stringa (verso destra). ES.: con  printf("%-4s","STR")  si avrà -> "STR "
        
    printf("\n%+4s %+8s %s\n","STR","SECONDO","TERZO");
        // Col meno davanti alla stringa da stampare si inseriscono [NumeroSpeficicato-LunghezzaStringa] spazi davanti alla stringa
        // a partire dalla prima lettera a DESTRA della stringa (verso sinistra).
        // ES.: con  printf("%+4s","STR")  si avrà -> " STR"
        
        
    printf("\n%+5s","STR");
    
    printf("\n");
    system("PAUSE");
}      
