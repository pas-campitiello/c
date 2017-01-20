#include <stdio.h>

typedef struct listas 
{
    int info;
    struct listas *next;
} Lista_t;

Lista_t * InsCodaCrea(Lista_t *t,int num);
Lista_t * InsTesta(Lista_t *t, Lista_t *n);
void StampaLista (Lista_t *t);

int main()
{
    Lista_t *testa = NULL;
    Lista_t *n;
    int num;
    
    /*printf("TESTA = NULL = %d\n",testa);
    printf("num = %d\n",num);
    getch();*/
    
    printf("=============== UTILIZZO DELLE LISTE CON InsCodaCrea e InsTesta ===============\n\n");
    printf("Inserisci un numero della lista (termina con 0): ");
    scanf("%d",&num);
    
    while (num)
    {
        testa = InsCodaCrea(testa,num);
        
        /*printf("*TESTA = %d  TESTA.info = %d  TESTA.next = %d\n",testa,testa->info,testa->next);
        printf("num = %d\n",num);
        getch();*/
        
        printf("Inserisci un numero della lista (termina con 0): ");
        scanf("%d",&num);
    }
    
    printf("\nInserisci un numero\n(per visualizzarne i multipli fra quelli inseriti precedentemente): ");
    scanf("%d",&num);
    
    printf("\nI multipli di %d fra i numeri inseriri sono: ",num);
    
    n = testa;

    while (n)
    {
        if ( !(n->info % num) ) printf("%d ",n->info);
        
        n = n->next;
    }
    
    printf("\n\nLa lista creata con InsCodaCrea e': ");
    StampaLista(testa);
    
    printf("\n\n================================================================================\n");
    printf("Inserisci un numero da posizionare IN TESTA alla lista: ");
    scanf("%d",&num);
    
    if ( n = (Lista_t *) malloc(sizeof(Lista_t)) )
    {
         n->info = num;
    
         testa = InsTesta(testa,n);
         
         printf("\nLa nuova lista e': ");
         StampaLista(testa);
    }
    else printf("\n\nMemoria esaurita!");
   
    
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
         
         //printf("*n = %d  n.info = %d  n.next = %d\n",n,n->info,n->next);
         
         if ( t == NULL ) return n;    // n è un indirizzo ad un elemento Lista_t con i campi "info" e "next"
         
         for(p=t; p->next!=NULL; p=p->next) ;
         
         p->next = n; // -> questa istruzione serve per indirizzare il puntatore del penultimo elemento 
                      // all'indirizzo dell'ultimo elemento
         
         //printf("*p = %d  p.info = %d  p.next = %d\n",p,p->info,p->next);
         
         return t;
    }
    else printf("\n\nMemoria esaurita!");
}

Lista_t * InsTesta(Lista_t *t, Lista_t *n)
{
    if (n!=NULL) n->next=t;
    
    t=n;       // }
               // }} return n;
    return t;  // }
}

void StampaLista (Lista_t *t)
{
    while (t)
    {
        printf("%d ",t->info);
        
        t = t->next;
    }
}
