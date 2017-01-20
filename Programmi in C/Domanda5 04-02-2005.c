// Domanda 5 - 2ª prova in itinere - 4 febbraio 2005

#include <stdio.h>

typedef struct listas 
{
    int info;
    struct listas *next;
} Lista_t;

Lista_t * InsCodaCrea(Lista_t *t,int num);
int Divisori(Lista_t *t,int num);
void StampaLista (Lista_t *t);

int main()
{
    Lista_t *testa = NULL;
    int val;
    int quanti;
    
    printf("=============== CARICAMENTO DELLA LISTA CON InsCodaCrea ===============\n\n");
    printf("Inserisci un numero della lista (termina con 0): ");
    scanf("%d",&val);
    
    while (val)
    {
        testa = InsCodaCrea(testa,val);
    
        printf("Inserisci un numero della lista (termina con 0): ");
        scanf("%d",&val);
    }
    
    printf("\nLa lista creata e': ");
    StampaLista(testa);
    
    printf("\n\nInserisci il numero (verranno visualizzati tutti i numeri della lista\nche sono divisori del numero inserito): ");
    scanf("%d",&val);
    
    quanti = Divisori(testa,val);
    
    printf("\nIl numero dei divisori trovati nella lista e' %d",quanti);
    
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

int Divisori(Lista_t *t,int num)
{
    int c;
    
    printf("\nI divisori del numero inserito sono: ");
    c=0;
    while (t)
    {
        if ( (num % (t->info))==0 ) 
        {
             printf("%d ",t->info);
             c++;
        }
        
        t = t->next;
    }
    
    return c;
}


void StampaLista (Lista_t *t)
{
    while (t)
    {
        printf("%d ",t->info);
        
        t = t->next;
    }
}
