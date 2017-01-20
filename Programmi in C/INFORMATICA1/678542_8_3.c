/* 1) Spiegare che compito esegue la funzione riportata di seguito. 
   2) Modificare quindi la funzione in modo che venga (quasi) dimezzato il tempo di esecuzione della stessa 
      nel caso più sfavorevole.

1) Il sottoprogramma "verifica" riceve in ingresso i puntatori a due array di caratteri. Se la lunghezza della prima stringa
è uguale alla lunghezza della seconda, tale lunghezza viene memorizzata nella variabile "len" e "n" (precedentemente azzerata)
viene impostata a 1. Poi esegue un ciclo FOR, per (len-1) iterazioni, controllando uno per volta tutti i caratteri della prima 
stringa: se questi sono uguali ai caratteri della seconda letti nel senso inverso (tramite s2[len - (i + 1)]) "n" viene azzerata.
Infine, come ultima istruzione, il sottoprogramma restituisce "n" al chiamante.
In pratica, il sottoprogramma "verifica" controlla se la prima stringa passatagli è uguale all'inverso della seconda, in tal caso
restituisce 1, altrimenti restituisce 0.

2) Intendendo come "caso più sfavorevole" quello in cui la prima stringa sia diversa dall'inverso della seconda, il ciclo FOR 
potrebbe fermarsi alla prima diversità trovata senza proseguire oltre. Questo è possibile sostituendo la riga:
"if ( s1[i] != s2[len - (i + 1)] ) n = 0;"  con  "if ( s1[i] != s2[len - (i + 1)] ) return 0;".
Naturalmente potrebbe anche essere evitato l'uso della variabile "n" restituendo con l'ultimo return il valore 1.

Domanda 4 - 2ª prova in itinere - 4 febbraio 2005
*/

#include<stdio.h>
#define N 30

int verifica(char *s1, char *s2);

int main()
{
     char stringa1[N+1];
     char stringa2[N+1];
     int verif;
     
     printf("Inserisci la prima stringa: ");
     gets(stringa1);
     printf("Inserisci la seconda stringa: ");
     gets(stringa2);
     
     verif = verifica(stringa1,stringa2);
     
     printf("\n verifica --> %d\n",verif);
     if (verif == 1) printf("\nLa prima stringa e' uguale all'inverso della seconda");
     else printf("\nLa prima stringa NON e' uguale all'inverso della seconda");
     
     printf("\n\n\n");
     system("pause");          
}

int verifica(char *s1, char *s2) 
{
    int i, len, n;
    
    n = 0;
    
    if (strlen(s1) == strlen(s2))
    {
        len = strlen(s1);
        
        n = 1;
        
        for (i=0; i<len; i++)
         //if ( s1[i] != s2[len - (i + 1)] ) n = 0;
         if ( s1[i] != s2[len - (i + 1)] ) return 0;
    }

    return n;
}
