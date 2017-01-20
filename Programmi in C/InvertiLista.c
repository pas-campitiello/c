#include <stdio.h>

typedef struct listas 
{
    int info;
    struct listas *next;
} Lista_t;

Lista_t * InsCodaCrea(Lista_t *t,int num);
Lista_t * InsTesta(Lista_t *t, Lista_t *n);
Lista_t * InvertiLista(Lista_t *t);
void StampaLista(Lista_t *t);

int main()
{
    Lista_t *testa = NULL;
    Lista_t *n;
    int num;

    
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
    
    testa = InvertiLista(testa);
    
    printf("\n\nLa lista invertita e': ");
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

Lista_t * InsTesta(Lista_t *t, Lista_t *n)
{
    if (n!=NULL) n->next=t;
    
    t=n;
    
    return t;
}

Lista_t * InvertiLista(Lista_t *t)
{
    Lista_t *h=NULL;
    Lista_t *p;
    
    //printf("\n\n");
    while( t!=NULL )
    {
        /*if ( t!=NULL ) printf("*t = %d  t.info = %d  t.next = %d\n",t,t->info,t->next);
                  else printf("*t = %d\n",t);
        
                       printf("*p = %d  p.info = %d  p.next = %d\n",p,p->info,p->next);
        
        if ( h!=NULL ) printf("*h = %d  h.info = %d  h.next = %d\n\n",h,h->info,h->next);
                  else printf("*h = %d\n\n",h);
        */
        p=t;
        t=t->next;
        
        /*if ( t!=NULL ) printf("*t = %d  t.info = %d  t.next = %d\n",t,t->info,t->next);
                  else printf("*t = %d\n",t);
        
                       printf("*p = %d  p.info = %d  p.next = %d\n",p,p->info,p->next);
        
        if ( h!=NULL ) printf("*h = %d  h.info = %d  h.next = %d\n\n\n",h,h->info,h->next);
                  else printf("*h = %d\n\n\n",h);
        */          
        h=InsTesta(h,p);
    }
    
    return h;
}

void StampaLista (Lista_t *t)
{
    while (t)
    {
        printf("%d ",t->info);
        
        t = t->next;
    }
}
