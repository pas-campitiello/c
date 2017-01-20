
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#define M 3                // Massimo numero di cifre per indicare il nome di un'immagine senza estensione
#define NumImgDir 50       // Numero delle immagini presenti in ciascuna cartella

char * ConcatenaStringhe(char [], char []);

int main()
{
    time_t tempo;          //<<| Tipo aritmetico time_t per memorizzare l'ora e la data corrente.
    struct tm *segnatempo; //<<| Struttura tm che permette poi di utilizzare le informazioni data e ora.
    int caso,i;            //  | La funzione srand(int) permette di impostare il valore del "seed" (numero a caso da cui partire 
    char numIMG[M+1];      //  | a generare numeri pseudo-casuali) e quindi di generare sequenze sempre diverse.  Per generare  
    char *nameIMG;         //  | sequenze sempre diverse, occorre scegliere un seed diverso per ogni esecuzione del programma. 
                           //  | Una possibile soluzione consiste nell'utilizzare come seed il timer del calcolatore ovvero 
    srand(time(0));        //<<| il numero di secondi trascorsi dalla mezzanotte del 1 gennaio 1970. Questo è reso possibile dalla
                           //  | funzione time(0) presente in time.h. Omettere l'istruzione srand(...); è come scrivere srand(1).
    char *cmd;             //<<| Conterrà il comando per convertire il file JPG in BMP.
    char *nomeSenzaEst;    //<<| Nome del file senza estensione.
    
    
    for(i=1; i<=50; i++)
    {
      itoa(i,numIMG,10);
      printf("Stringa del numero a caso generato %s",numIMG);
      nomeSenzaEst = ConcatenaStringhe("C:\\Docume~1\\Pasqua~1\\Desktop\\Programming\\C\\Progra~1\\Sfondo.c\\Primavera\\",numIMG); 
      nameIMG = ConcatenaStringhe(nomeSenzaEst,".bmp"); 
      printf("\n\n%s\n\n",nameIMG); 
      //Creo il comando per convertire il file JPG in BMP
                   
      cmd = ConcatenaStringhe("C:\\Docume~1\\Pasqua~1\\Desktop\\Programming\\C\\Progra~1\\Sfondo2\\PVW32Con ",nameIMG); 
      cmd = ConcatenaStringhe(cmd," -j");
      
      // Converto la JPG selezionata in BMP con il comando PVW32Con
      system(cmd);
    }
    
    printf("\n\n");
    system("Pause");
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
