#include <stdio.h>

typedef struct listas 
{
    char info;
    struct listas *next;
} Lista_t;

Lista_t * InsCodaCrea(Lista_t *t,char c);
Lista_t* CopiaL1(Lista_t *copia, Lista_t *orig);
void StampaLista(Lista_t *t);

int main()
{
    Lista_t *testa1 = NULL;
    Lista_t *testa2 = NULL;
    Lista_t *testa3 = NULL;
    Lista_t *n;
    char car;
    
    printf("=============== CARICAMENTO DELLA LISTA-1 CON InsCodaCrea ===============\n\n");
    printf("Inserisci un carattere della lista (termina con 0): ");
    scanf("%c%*c",&car);
    
    while (car!='0')
    {
        testa1 = InsCodaCrea(testa1,car);
        
        printf("Inserisci un carattere della lista (termina con 0): ");
        scanf("%c%*c",&car);
    }
    
    printf("\nLa lista-1 creata con InsCodaCrea e':  ");
    StampaLista(testa1);
    
    printf("\n\n\n=============== CARICAMENTO DELLA LISTA-2 CON InsCodaCrea ===============\n\n");
    printf("Inserisci un carattere della lista (termina con 0): ");
    scanf("%c%*c",&car);
    
    while (car!='0')
    {
        testa2 = InsCodaCrea(testa2,car);
        
        printf("Inserisci un carattere della lista (termina con 0): ");
        scanf("%c%*c",&car);
    }
    
    printf("\nLa lista-2 creata con InsCodaCrea e':  ");
    StampaLista(testa2);
    
    testa3 = CopiaL1(testa3,testa1);
    
    printf("\n\nLa lista-3 creata con InsCodaCrea copiando la lista-1:  ");
    StampaLista(testa3);
  
    printf("\n\n\n");
    system("Pause");
}

Lista_t* CopiaL1(Lista_t *copia, Lista_t *orig)
{
    Lista_t *n;
    
    n = orig;

    while (n!=NULL)
    {
        copia = InsCodaCrea(copia,n->info);
        
        n = n->next;
    }
    
    return copia;
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

void StampaLista (Lista_t *t)
{
    while (t)
    {
        printf("%c ",t->info);
        
        t = t->next;
    }
}
