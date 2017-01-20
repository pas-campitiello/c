/* Esempio: stampa della data odierna */
#include <stdio.h>
#include <time.h>

int main()
{
    time_t tempo;          // tipo aritmetico time_t per memorizzare l'ora e la data corrente
	
    struct tm *segnatempo; // struttura tm che permette poi di utilizzare le informazioni data e ora */
	
    tempo = time(&tempo);  // recuperiamo la data e ora corrente */
	
	segnatempo = localtime(&tempo); // riempiamo la struttura segnatempo a partire dall'ora recuperata 
	                                // con la funzione time tramite la funzione localtime
    
    printf ("%d\n",segnatempo->tm_hour);
	printf ("%s\n", asctime(segnatempo)); // per stampare in modo comprensibile la struttura segnatempo possiamo usare asctime
	
	printf("\n");
	system("PAUSE");
}
