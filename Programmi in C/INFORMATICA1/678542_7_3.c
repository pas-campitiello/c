// Campitiello Pasquale
// 678542
// PC n 10

/* 
1) Spiegare che compito esegue la funzione verifica riportata di seguito.
2) Scrivere un main() che la contenga. 
3) Modificare quindi la funzione in modo da gestire anche il caso in cui s non contenga il carattere "#".
4) Indicare anche quali sono le ipotesi da fare, relative al parametro ss, che consentono di essere certi 
   del risultato della funzione.
==================================================================================================================================
Il sottoprogramma "verifica" riceve in ingresso due puntatori ai primi caratteri di due stringhe.
Se il primo carattere della prima stringa è uguale da '#' il compilatore evita il blocco dell'IF ed esegue l'istruzione
"return n;" restituendo 0.
Se il primo carattere della prima stringa è diverso da '#', si incrementa la variabile "i" (che precedentemente era stata
azzerata insieme alla variabile "n"). Poi si esegue un ciclo WHILE finquando il primo carattere della prima stringa
è diverso da '#'. Nel blocco del WHILE si controlla se: 

il carattere in posizione "i" della prima stringa è uguale al carattere in posizione 0 della seconda stringa, 

e contemporaneamente, se: 

il carattere in posizione "i-1" della prima stringa è uguale al carattere in posizione 1 della seconda stringa.

Se tali condizioni risultano entrambe vere si andrà ad incrementare la variabile n. 
Dopo l'IF sempre nel ciclo WHILE si incrementa anche la variabile "i".

Finito il ciclo WHILE si esegue l'istruzione "return n;" restituendo la n (che rappresenta il numero delle volte in cui si sono
verificate le condizione sopradescritte).

In pratica il sottoprogramma "verifica", ricevute due stringhe in ingresso, conta le uguaglianza fra due coppie di caratteri
delle 2 stringhe. La coppia di caratteri della seconda stringa è fissa (sono il primo e il secondo carattere); la coppia 
di caratteri della prima stringa è individuata opportunamente tramite l'indice "i". 
Si tratta di una sorta di controllo a X in quanto la coppia di caratteri della prima stringa viene considerata invertita:
il 2° della coppia di caratteri della prima stringa è controllatto col 1° della coppia di caratteri della seconda stringa e
il 1° della coppia di caratteri della prima stringa è controllatto col 2° della coppia di caratteri della seconda stringa.

Il compito del sottoprogramma "verifica" può essere indicato anche in questo modo: conta il numero delle presenze dei
primi 2 caratteri delle seconda stringa nella prima stringa ma in senso invertito.
----------------------------------------------------------------------------------------------------------------------------------           
Per esempio (questo per il punto 4) se la stringa s è "teiote" e la stringa ss è "etmondo": i primi due caratteri della stringa ss
sono "et" in senso invertito diventano "te"; "te" è presente due volte nella prima stringa, s quindi il sottoprogramma "verifica" 
restituisce 2.
----------------------------------------------------------------------------------------------------------------------------------
Per il punto 3.
Se la stringa s non contiene il carattere "#" il ciclo WHILE va il loop, quindi una delle soluzioni possibili potrebbe essere 
quella di creare un'altra condizione per uscire dal ciclo per esempio: while ( (s[i] != '#') ||  (s[i] != '\0') ).
In questo modo il ciclo termina quando viene trovato il carattere "#" oppure quando la stringa è finita, cioè quando si incontra
il carattere terminatore.

*/

#include<stdio.h>
#define C 10

int verifica(char *s,char *ss);

int main()
{
    int i,funz;
    char str1[C+1],str2[C+1];
    
    printf("  Inserisci la prima stringa: ");
    gets(str1);
    printf("Inserisci la seconda stringa: ");
    gets(str2);
    
    funz = verifica(str1,str2);
    
    if (funz==0) printf("\nI primi due caratteri della 2a stringa, in senso inverso,\nnon sono presenti nella 1a stringa");
    else if (funz==1) printf("\nI primi due caratteri della 2a stringa, in senso inverso,\nsono presenti 1 volta nella 1a stringa");
         else printf("\nI primi due caratteri della 2a stringa, in senso inverso,\nsono presenti %d volte nella 1a stringa",funz);
    
    printf("\n\n");
    system("pause");          
}

int verifica(char *s, char *ss) 
{
    int i,n;
    
    i = n = 0;
    
    if (s[i] != '#') 
    {
        i++;
        
        while ( (s[i] != '#') &&  (s[i] != '\0') )
        {
            if ( (s[i] == ss[0]) && (s[i - 1] == ss[1]) ) n++;
            
            i++;
        }
    }
    
    return n;
}
