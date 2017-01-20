// Questo programma, ricevuta in ingresso una lista di interi, deve fare la sottrazione fra ogni coppia di numeri della lista,
// e deve controllare se il valore assoluto di tale sottrazione è un numero primo: se sì lo inserisce in una nuova lista,
// altrimenti nella nuova lista inserisce 0. Al termine dell'esecuzione ritorna la nuova lista.

#include <stdio.h>

typedef struct listas 
{
    int info;
    struct listas *next;
} Lista_t;

Lista_t * InsCodaCrea(Lista_t *t,int num);
void StampaLista(Lista_t *t);
int IsPrime(int n);
int Abs(int n);

int main()
{
    Lista_t *testa = NULL;
    Lista_t *newList = NULL;
    Lista_t *n;
    int num;
    int diffCTRL;

    
    printf("=============== CARICAMENTO DELLA LISTA CON InsCodaCrea ===============\n\n");
    printf("Inserisci un numero della lista (termina con 0): ");
    scanf("%d",&num);
    
    while (num)
    {
        testa = InsCodaCrea(testa,num);
        
        printf("Inserisci un numero della lista (termina con 0): ");
        scanf("%d",&num);
    }
    
    printf("\nLa lista creata con InsCodaCrea e': ");
    StampaLista(testa);
    
    n = testa;
    while ( (n!=NULL) && (n->next!=NULL) )
    {
        diffCTRL=(n->info)-(n->next->info);
        
        if ( IsPrime(Abs(diffCTRL)) ) newList = InsCodaCrea(newList,diffCTRL);
                                 else newList = InsCodaCrea(newList,0);
        
        n = n->next;
    }
    
    printf("\n\nLa lista creata dalla prima e': ");
    StampaLista(newList);
  
    printf("\n\n");
    system("Pause");
}


Lista_t * InsCodaCrea(Lista_t *t,int num)
{
    Lista_t *n,*p;
    
    if ( n = (Lista_t *) malloc(sizeof(Lista_t)) )
    {
         n->info = num;
         n->next = NULL;
         
         if ( t == NULL ) return n;
         
         for(p=t; p->next!=NULL; p=p->next) ;
         
         p->next = n;
         
         return t;
    }
    else printf("\n\nMemoria esaurita!");
}

void StampaLista (Lista_t *t)
{
    while (t)
    {
        printf("%d ",t->info);
        
        t = t->next;
    }
}

int IsPrime(int n)
{
    int i;
    
    if (n==2) return 1;
    
    if ((n%2)==0) return 0;
   
    i = 3;
    while ( (n%i) && (i < (n+1)/2) ) i = i + 2;
   
    if ( (n%i) || (n==3) ) return 1;
   
    return 0;
}

int Abs(int num)
{
    if (num<0) return -num;
    else return num;
}
