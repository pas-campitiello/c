#include <stdio.h>

typedef struct listas 
{
    int info;
    struct listas *next;
} Lista_t;

Lista_t * InsCodaCrea(Lista_t *t,int num);
Lista_t * Cancella(Lista_t *t,int num);
void StampaLista (Lista_t *t);

int main()
{
    Lista_t *testa = NULL;
    Lista_t *n;
    int val;
    
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
    
    printf("\n\nInserisci il numero da eliminare");
    printf("\n(tutti i numeri uguali a quello inserito verranno eliminati): ");
    scanf("%d",&val);
    
    testa = Cancella(testa,val);
    
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

Lista_t * Cancella(Lista_t *t,int num)
{
    Lista_t *tes_tmp = NULL;
    Lista_t *testa_iniziale = t;
    int found;
    
    found = 0;
    while (t!=NULL)
    {
         if ( (t->info)!=num ) tes_tmp = InsCodaCrea(tes_tmp,t->info);
         else 
         {
              found = 1;
              free(t);
         }
        
         t = t->next;
    }
    
    if (!found) 
    {
        printf("\nIL NUMERO %d NON E' STATO TROVATO NELLA LISTA!\n",num);
        return testa_iniziale;
    }
    else return tes_tmp;
}

void StampaLista (Lista_t *t)
{
    while (t)
    {
        printf("%d ",t->info);
        
        t = t->next;
    }
}
