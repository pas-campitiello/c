#include <stdio.h>

typedef struct listas 
{
    int info;
    struct listas *next;
} Lista_t;

Lista_t * InsCodaCrea(Lista_t *t,int num);
Lista_t * Concatena(Lista_t *t1,Lista_t *t2);
void StampaLista(Lista_t *t);

int main()
{
    Lista_t *testa1 = NULL;
    Lista_t *testa2 = NULL;
    Lista_t *n;
    int num;

    
    printf("=============== CARICAMENTO DELLA LISTA 1 CON InsCodaCrea ===============\n\n");
    printf("Inserisci un numero della lista (termina con 0): ");
    scanf("%d",&num);
    
    while (num)
    {
        testa1 = InsCodaCrea(testa1,num);
        
        printf("Inserisci un numero della lista (termina con 0): ");
        scanf("%d",&num);
    }
    
    printf("\nLa lista 1 creata con InsCodaCrea e': ");
    StampaLista(testa1);
    
    printf("\n\n\n=============== CARICAMENTO DELLA LISTA 2 CON InsCodaCrea ===============\n\n");
    printf("Inserisci un numero della lista (termina con 0): ");
    scanf("%d",&num);
    
    while (num)
    {
        testa2 = InsCodaCrea(testa2,num);
        
        printf("Inserisci un numero della lista (termina con 0): ");
        scanf("%d",&num);
    }
    
    printf("\nLa lista 2 creata con InsCodaCrea e': ");
    StampaLista(testa2);
    
    testa1 = Concatena(testa1,testa2);
    
    printf("\n\n\nLa lista creata per concatenazione delle prime due e': ");
    StampaLista(testa1);
    
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

Lista_t * Concatena(Lista_t *t1,Lista_t *t2)
{
    Lista_t *tmp;
    
    if (!t1) return t2;
    
    for(tmp=t1; tmp->next!=NULL; tmp=tmp->next) ;
    
    tmp->next = t2;
    
    return t1;
}

void StampaLista (Lista_t *t)
{
    Lista_t *tmp;
    
    tmp = t;
    
    while (tmp)
    {
        printf("%d ",tmp->info);
        
        tmp = tmp->next;
    }
}
