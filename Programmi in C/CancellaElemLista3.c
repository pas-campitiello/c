#include <stdio.h>

typedef struct listas 
{
    int info;
    struct listas *next;
} Lista_t;

Lista_t * InsCodaCrea(Lista_t *t,int num);
Lista_t * CancellaElem(Lista_t *t, int canc);
void StampaLista (Lista_t *t);

int main()
{
    Lista_t *testa = NULL;
    Lista_t *n;
    int num;
    
    printf("=============== UTILIZZO DELLE LISTE CON InsCodaCrea e InsTesta ===============\n\n");
    printf("Inserisci un numero della lista (termina con 0): ");
    scanf("%d",&num);
    
    while (num)
    {
        testa = InsCodaCrea(testa,num);
        
        printf("Inserisci un numero della lista (termina con 0): ");
        scanf("%d",&num);
    }
    
    printf("\n\nLa lista creata con InsCodaCrea e': ");
    StampaLista(testa);
    
    printf("\n\n================================================================================\n");
    printf("Inserisci un numero da cancellare: ");
    scanf("%d",&num);
    
    testa = CancellaElem(testa,num);
         
    printf("\nLa nuova lista e': ");
    StampaLista(testa);
    
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

Lista_t * CancellaElem(Lista_t *t, int canc)
{
    Lista_t *prec, *corr, *tmp;
    
    if (t==NULL) return t;
    else 
    {
         prec = NULL;
         corr = t;
         while (corr != NULL)
         {
             if (corr->info == canc)
             {
                if (prec==NULL)
                {
                    tmp = t;
                    t = t->next;
                    
                    corr = t;
                    
                    free(tmp);
                }
                else
                {
                    tmp = corr;
                    prec->next = corr->next;
                    
                    corr = prec->next;
                    
                    free(tmp);
                }
             }
             else
             {
                 prec = corr;
                 corr = corr->next;
             }
         }
         
         return t;
    }
}


void StampaLista (Lista_t *t)
{
    while (t)
    {
        printf("%d ",t->info);
        
        t = t->next;
    }
}
