#include <stdio.h>

typedef struct listas 
{
    int info;
    struct listas *next;
} Lista_t;

Lista_t * InsTestaCrea(Lista_t *t, int num);
Lista_t * InsCoda(Lista_t *t, Lista_t *n);
void StampaLista (Lista_t *t);

int main()
{
    Lista_t *testa = NULL;
    Lista_t *n;
    int num;
    
    printf("=============== UTILIZZO DELLE LISTE CON InsTestaCrea InsCoda ===============\n\n");
    printf("Inserisci un numero della lista (termina con 0): ");
    scanf("%d",&num);
    
    while (num)
    {
        testa = InsTestaCrea(testa,num);
    
        printf("Inserisci un numero della lista (termina con 0): ");
        scanf("%d",&num);
    }
    
    printf("\nLa lista crea con InsTestaCrea e': ");
    StampaLista(testa);
    
    printf("\n\n================================================================================\n");
    printf("Inserisci un numero da posizionare IN CODA alla lista: ");
    scanf("%d",&num);
    
    if ( n = (Lista_t *) malloc(sizeof(Lista_t)) )
    {
         n->info = num;
         n->next = NULL;
    
         testa = InsCoda(testa,n);
         
         printf("\nLa nuova lista e': ");
         StampaLista(testa);
    }
    else printf("\n\nMemoria esaurita!");
   
    
    printf("\n\n\n");
    system("Pause");
}


Lista_t * InsTestaCrea(Lista_t *t, int num)
{
    Lista_t *n;
    
    if ( n = (Lista_t *) malloc(sizeof(Lista_t)) )
    {
         n->info = num;
         n->next = t;
         t=n;
    }
    else printf("\n\nMemoria esaurita!");
    
    return t;
}

Lista_t * InsCoda(Lista_t *t, Lista_t *n)
{
    Lista_t *tmp;
    
    /*
    tmp=t;

    while(tmp->next!=NULL)
     tmp=tmp->next;
    */
    
    for(tmp=t; tmp->next!=NULL; tmp=tmp->next) ;
    
    //Dopo il FOR in tmp c'è l'indirizzo dell'ultimo elemento della lista
    
    tmp->next = n;
    
    return t;
}

void StampaLista (Lista_t *t)
{
    while (t)
    {
        printf("%d ",t->info);
        
        t = t->next;
    }
}
