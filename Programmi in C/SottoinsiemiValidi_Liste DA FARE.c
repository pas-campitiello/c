#include <stdio.h>
#include <string.h>
#define NC 5

typedef struct listas 
{
    char info;
    struct listas *next;
} Lista_t;


Lista_t * InsCodaCrea(Lista_t *t,char c);
Lista_t * CreaListaSottoinsiemi(char vet[],int dim);
void StampaLista(Lista_t *t);

int main()
{
    Lista_t *testaSotIns = NULL;
    char str[NC+1];
    int lung;
    
    printf("=============== CARICAMENTO DEL VETTORE DI CARATTERI ===============\n\n");
    printf("Inserisci la stringa: ");
    gets(str);
    
    lung = 0;
    while (str[lung]!='\0') lung++;
    
    printf("\nLa stringa e': %s",str);
    printf("\nLa sua lunghezza e': %d",lung);
   
    testaSotIns = CreaListaSottoinsiemi(str,lung);
    
    printf("\n\nLa lista dei sottoinsiemi validi e': ");
    StampaLista(testaSotIns);
   
    printf("\n\n\n");
    system("Pause");
}

Lista_t * InsCodaCrea(Lista_t *t,char c)
{
    Lista_t *n,*p;
    
    if ( n = (Lista_t *) malloc(sizeof(Lista_t)) )
    {
         n->info = c;
         n->next = NULL;
         
         if ( t == NULL ) return n;
         
         for(p=t; p->next!=NULL; p=p->next) ;

         p->next = n;
         
         return t;
    }
    else printf("\n\nMemoria esaurita!");
}

Lista_t * CreaListaSottoinsiemi(char vet[],int dim)
{
    Lista_t *testa = NULL;
    int i,iter;
    
    // L'insieme dei sottoinsiemi validi è formato da dim liste
    for (iter=0; iter<dim; iter++)
    {
        // Creo la prima lista di sottoinsiemi formata dai singoli caratteri dell'array
        for (i=0; i<dim; i++) testa = InsCodaCrea(testa,vet[i]);
    
        // Creo la seconda lista di sottoinsiemi formata dalle coppie di caratteri dell'array
        for (i=0; i<dim; i++) testa = InsCodaCrea(testa,vet[i]);
    }
    
    
    return testa;
}

void StampaLista (Lista_t *t)
{
    while (t)
    {
        printf("%c ",t->info);
        
        t = t->next;
    }
}

