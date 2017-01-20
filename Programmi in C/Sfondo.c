/* ___________________________________________________..:: S F O N D O . c ::..___________________________________________________
                                                       Pasquale Campitiello (c) 
 
 SFONDO.c imposta lo sfondo del desktop seguendo 2 criteri (le immagini sono numerate da 1 in poi e divise in diverse cartelle
 PRIMAVERA, ESTATE, AUTUNNO, INVERNO):
  1) genera un numero a caso compreso tra 0 e NumImgDir (che � il numero delle immagini presenti in ciascuna cartella);
  2) dalla data di sistema vede qual'� il mese al momento dell'esecuzione. Seguendo poi questo schema:
      INVERNO   >> Dicembre 12  Gennaio 1   Febbraio 2
      PRIMAVERA >> Marzo 3      Aprile 4    Maggio 5
      ESTATE    >> Giugno 6     Luglio 7    Augusto 8
      AUTUNNO   >> Settembre 9  Ottobre 10  Novembre 11
     va a selezionare nella cartella relativa (PRIMAVERA, ESTATE, AUTUNNO, INVERNO) l'immagine che si chiama col numero generato
     al punto (1) e la imposta come sfondo chiamando un API.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#define M 3                // Massimo numero di cifre per indicare il nome di un'immagine senza estensione
#define NumImgDir 50       // Numero delle immagini presenti in ciascuna cartella

char * ConcatenaStringhe(char [], char []);

int main()
{
    time_t tempo;          //<- Tipo aritmetico time_t per memorizzare l'ora e la data corrente
    struct tm *segnatempo; //<- Struttura tm che permette poi di utilizzare le informazioni data e ora */
    int caso,i;            //  | La funzione srand(int) permette di impostare il valore del "seed" (numero a caso da cui partire 
    char numIMG[M+1];      //  | a generare numeri pseudo-casuali) e quindi di generare sequenze sempre diverse.  Per generare  
    char *nameIMG;         //  | sequenze sempre diverse, occorre scegliere un seed diverso per ogni esecuzione del programma. 
                           //  | Una possibile soluzione consiste nell'utilizzare come seed il timer del calcolatore ovvero 
    srand(time(0));        //<<| il numero di secondi trascorsi dalla mezzanotte del 1 gennaio 1970. Questo � reso possibile dalla
                           //  | funzione time(0) presente in time.h. Omettere l'istruzione srand(...); � come scrivere srand(1).
    
    caso = 1+(rand()%NumImgDir);
    printf("Numero generato -> %d\n",caso);

// Trasformo il numero pseudo-casuale in stringa (che sar� il nome del file immagine BMP)
    itoa(caso,numIMG,10);
    printf("Stringa del numero a caso generato %s",numIMG);
    
// Recupero la data per poi impostare la cartella in cui andare a pescare l'immagine dello sfondo
    tempo = time(&tempo);                    //<- Si recupera la data e l'ora corrente
	segnatempo = localtime(&tempo);          //<- Si riempie la struttura segnatempo a partire dall'ora recuperata 
	                                         //  con la funzione time tramite la funzione localtime
    switch (segnatempo->tm_mon+1)
    {
           case 12: ;
           case 1: ;
           case 2: nameIMG = ConcatenaStringhe("Inverno\\",numIMG); 
                   nameIMG = ConcatenaStringhe(nameIMG,".bmp"); 
                   printf("\n\n%s",nameIMG); 
                   break;
           case 3: ;
           case 4: ;
           case 5: nameIMG = ConcatenaStringhe("Primavera\\",numIMG);
                   nameIMG = ConcatenaStringhe(nameIMG,".bmp"); 
                   printf("\n\n%s",nameIMG); 
                   break;
           case 6: ;
           case 7: ;
           case 8: nameIMG = ConcatenaStringhe("Estate\\",numIMG); 
                   nameIMG = ConcatenaStringhe(nameIMG,".bmp"); 
                   printf("\n\n%s",nameIMG); 
                   break;
           case 9: ;
           case 10: ;
           case 11: nameIMG = ConcatenaStringhe("Autunno\\",numIMG); 
                    nameIMG = ConcatenaStringhe(nameIMG,".bmp"); 
                    printf("\n\n%s",nameIMG); 
                    break;
           default: MessageBox(0,"ERRORE NEL PROGRAMMA CHE IMPOSTA LO SFONDO!","ATTENZIONE!",0);
                    // Lancia a video un messagebox con il pulsante OK, l'etichetta indicata e titolo "ATTENZIONE!"
    }
    
    
    //printf ("\nMese: %d\n",segnatempo->tm_mon+1);
    SystemParametersInfo(20,0,nameIMG,0);          // API per impostare lo sfondo. Accetta solo immagini BMP.

    //printf("\n\n");
    //system("Pause");
}

char * ConcatenaStringhe(char str1[], char str2[])
{
     char *strConcatPTR;
     int i,j;
         
     if ( strConcatPTR = malloc ( ( strlen(str1)+ strlen(str2) + 1 ) * sizeof(char) ) )
     {
          for (i=0; str1[i]!='\0'; i++) *(strConcatPTR + i) = str1[i];
          for (j=0; str2[j]!='\0'; i++, j++) *(strConcatPTR + i) = str2[j];
     
          *(strConcatPTR + i) = '\0';
     }
     else printf("\n\nMemoria esaurita!"); 
     
     return strConcatPTR;
}
