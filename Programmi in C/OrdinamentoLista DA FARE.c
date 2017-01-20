#include <stdio.h>

typedef struct listas 
{
    int info;
    struct listas *next;
} Lista_t;

Lista_t * InsCodaCrea(Lista_t *t,int num);
Lista_t * Ordinamento(Lista_t *t, int value);
void StampaLista (Lista_t *t);

int main()
{
    Lista_t *testa = NULL;
    Lista_t *tmp = NULL;
    int val;
    
    printf("=============== CARICAMENTO DELLA LISTA CON InsCodaCrea ===============\n\n");
    printf("Inserisci un numero della lista (termina con 0): ");
    scanf("%d",&val);
    
    while (val)
    {
        testa = Ordinamento(testa,val);

        printf("Inserisci un numero della lista (termina con 0): ");
        scanf("%d",&val);
    }
    
    printf("\nLa lista creata e': ");
    StampaLista(testa);
    
    /*tmp = testa;
    while (tmp!=NULL) 
    {
         tmp = Ordinamento(testa,tmp->info);
         
         tmp = tmp->next;
    }
    
    printf("\nLa lista ordinata e': ");
    StampaLista(testa);
   */
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

Lista_t * Ordinamento(Lista_t *t, int value)
{
    Lista_t *newPTR;
    Lista_t *previousPTR;
    Lista_t *currentPTR;
    
    if ( newPTR = malloc(sizeof(Lista_t)) )
    {
         newPTR->info = value;
         newPTR->next = NULL;
         
         previousPTR = NULL;
         currentPTR = t;
         
         while ( (currentPTR != NULL) && (value > currentPTR->info) )
         {
              previousPTR = currentPTR;
              currentPTR = currentPTR->next;
         }
         
         if ( previousPTR == NULL )
         {
              newPTR->next = t;
              return newPTR;
         }
         else
         {
              previousPTR->next = newPTR;
              newPTR->next = currentPTR;
              
              return t;
         }
    }
    else printf("Memoria esaurita!");
}

void StampaLista (Lista_t *t)
{
    while (t!=NULL)
    {
        printf("%d ",t->info);
        
        t = t->next;
    }
}
