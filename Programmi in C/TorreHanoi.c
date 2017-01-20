/* Le colonne sulla torre di Hanoi sono:
      
   |            |            |
   |1           |            |
   |2           |            |
   |3           |            |
   =            =            =
sorgente       aux       destinazione

Portare gli anelli 1, 2 e 3 nella colonna destinazione. Gli anelli si possono spostare uno per volta e si possono sovrapporre
solo ad anelli più grandi.

*/

#include <stdio.h>

void Hanoi(int anelli, int sorgente, int destinazione, int aux);

int main ()
{
    printf("---------------------------------------------------------\n");
    printf(" ^ ^ ^ ^ ^ ^ ^   T O R R E  di  H A N O I   ^ ^ ^ ^ ^ ^ ^\n");
    printf("---------------------------------------------------------\n");
    Hanoi(64,1,3,2);
    
    printf("\n\n");
    system("Pause");
}

void Hanoi(int anelli, int sorgente, int destinazione, int aux)
{
     if (anelli==1) printf(" Sposta da %d a %d.\n",sorgente,destinazione);
     else
     {
         Hanoi(anelli-1,sorgente,aux,destinazione);
         Hanoi(1,sorgente,destinazione,aux);
         Hanoi(anelli-1,aux,destinazione,sorgente);
     }
}
