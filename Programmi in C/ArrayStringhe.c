// Programma per la gestione di un array di stringhe ::::> NON MIO ma identato e ordinato da me
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define N 40
#define MAXLUNG 50

void aggiungi (char *v[], char *, int *);
int ricerca (char *[], int , char *);
void sostituisci (char *v[], int quante, char * quale, char *conChi);
void stampaStringhe (char *v[], int quante);

int main()
{
    
    int i, scelta,
       numeroStringhe;      // Numero di stringhe che sono nell'array
    char *stringhe[N],      // Array di N stringhe
       buffer[MAXLUNG+1], buffer2[MAXLUNG+1];

    numeroStringhe=0;   // Inizializzazione del numero di stringhe presenti nell'array
    do 
    {
        printf(" -       MENU       -\n");
        printf(" - Aggiunta     (1) -\n");
        printf(" - Sostituzione (2) -\n");
        printf(" - Stampa       (3) -\n");
        printf(" - USCITA       (0) -\n\n::> ");

        scanf("\n%d", &scelta); printf("\n");
   
        switch (scelta) 
        {
            case 1: 
             printf("Stringa di al piu' %d caratteri (da inserire nell'array): ", MAXLUNG);
             scanf("%s", buffer);
             aggiungi(stringhe, buffer, &numeroStringhe);
            break;
            
            case 2: 
             printf("Stringa da sostituire: ");
             scanf("%s", buffer);              
             printf("Stringa con cui sostituirla: ");
             scanf("%s", buffer2);              
             sostituisci(stringhe, numeroStringhe, buffer, buffer2);
            break;

            case 3:
             printf("\n- L'array di stringhe e':\n");
             stampaStringhe(stringhe, numeroStringhe);
            break;
            
            case 0: printf(" - USCITA DAL PROGRAMMA\n"); break;
            
            default: printf(" - Opzione sbagliata!\n");
        }
        printf("\n");
    } 
    while (scelta!=0);
 
    printf("\nFINE DEL PROGRAMMA\n");
    system("Pause");
}

/* ************* Funzioni usate ********************** */

// Trova la stringa cercata nell'array v, sapendo che il numero di stringhe presenti in v e' quante 
// restituisce il puntatore alla stringa trovata o NULL
int ricerca (char *v[], int quante, char *cercata) 
{
    int trovata,i;
  
    trovata=0;
  
    for (i=0; ((i<quante)&&(!trovata)); i++)
     if (strcmp(v[i],cercata)==0) trovata=1;
    
/* Se ora i vale quante vuol dire che la ricerca della stringa non ha avuto successo (e si restituisce -1).
Se la stringa e' stata trovata, l'ultima iterazione del ciclo ha
- scoperto che v[i] conteneva la stringa cercata
- assegnato trovata a 1
- incrementato i di 1
poi il ciclo si e' interrotto quindi l'indice della stringa cercata e' i-1 */
  
    if (trovata==0) return -1;     // Stringa non trovata
               else return (i-1);  // Stringa trovata e restituisco l'indice della stringa che e' i-1
}

void aggiungi (char *v[], char *nuova, int *quante) 
{
    if (*quante>=N) printf(" - Array pieno!\n");
    else 
    {
      v[*quante] = malloc(strlen(nuova)+1);        // Allocazione memoria della stringa
      if (v[*quante]==NULL)
       printf("Errore nell'allocazione!\n");
      else 
      {
         strcpy(v[*quante], nuova);                          // Copia della stringa nuova in v[*quante]
         *quante +=1; // uguale a *quante = *quante+1;          e incremento del numero di stringhe
      }
    }
}


// Sostituisce la stringa quale con la stringa conChi nell'array v, sapendo che ci sono quante stringhe nelle'array
void sostituisci (char *v[], int quante, char * quale, char *conChi)
{
    int indiceStringa;

    indiceStringa = ricerca(v, quante, quale);

    if (indiceStringa==-1) printf("La stringa %s non e' stata trovata nell'array!\n",quale);
    else 
    {
       free(v[indiceStringa]);   // Si libera la memoria occupata dalla stringa da sostituire
       v[indiceStringa] = malloc(strlen(conChi));  //Si alloca memoria per la nuova
       
       if (v[indiceStringa]==NULL) printf("problemi in allocazione\n");       
       else strcpy(v[indiceStringa], conChi);       // Copia della stringa conChi in v[indiceStringa]
    }
}



void stampaStringhe (char *v[], int quante)
{
   int i;

   for (i=0; i<quante; i++) printf("%s\n",v[i]);
}
