//Campitiello Pasquale
//678542
//Computer n° 2

#include <stdio.h>

typedef struct listas 
{
    int info;
    struct listas *next;
} Lista_t;

Lista_t * InsCodaCrea(Lista_t *t,int num);
Lista_t * LiberaMemoria(Lista_t *t);
void StampaLista(Lista_t *t);

int main()
{
    Lista_t *testa = NULL;
    Lista_t *n;
    int num;

    
    printf("=============== CARICAMENTO DELLA LISTA CON InsCodaCrea ===============\n\n");
    printf("Inserisci un numero della lista (termina con un numero negativo): ");
    scanf("%d",&num);
    
    while (num>=0)
    {
        testa = InsCodaCrea(testa,num);
        
        printf("Inserisci un numero della lista (termina con un numero negativo): ");
        scanf("%d",&num);
    }

// Stampo a video i numeri acquisiti dal primo all'ultimo

    printf("\nLa lista creata con InsCodaCrea e': ");
    StampaLista(testa);

// Libero la memoria precedentemente allocata
    LiberaMemoria(testa);

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


Lista_t * LiberaMemoria(Lista_t *t)
{
    Lista_t *prec;
  
    while (t!=NULL)
    {   
        prec = t; 
        t = t->next;
        
        free(prec);
    }
}

void StampaLista (Lista_t *t)
{
    while (t!=NULL)
    {
        printf("%d ",t->info);
        
        t = t->next;
    }
}
