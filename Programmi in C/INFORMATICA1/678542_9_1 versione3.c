#include <stdio.h>

typedef struct listas 
{
    int info;
    struct listas *next;
} Lista_t;

Lista_t * InsCodaCrea(Lista_t *t,int num);
Lista_t * InsOrd(Lista_t *t,int num);
void StampaLista (Lista_t *t);

int main()
{
    Lista_t *testa = NULL;
    Lista_t *n;
    int Nm;
    
    printf(".. Inserire una lista ordinata in senso decrescente di numeri pari ..\n\n");
    printf("Inserisci un numero (termina con 0): ");
    scanf("%d",&Nm);
    
    while (Nm)
    {
        testa = InsOrd(testa,Nm);
        
        printf("Inserisci un numero (termina con 0): ");
        scanf("%d",&Nm);
    }
    
    printf("\nLa lista creata e': ");
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
    else printf("\n\nMemoria esaurita!!!");
}

Lista_t * InsOrd(Lista_t *t,int num)
{
    Lista_t * prec;
    Lista_t * corr;
    Lista_t * nuovoNodo;
    
    if (num%2==0)
    {if ( nuovoNodo = (Lista_t*)malloc(sizeof(Lista_t)) )
     {
          nuovoNodo->info = num;
          nuovoNodo->next = NULL;
          
          prec = NULL;
          corr = t;
          
          while ( (corr!= NULL) && (corr->info > num) )
          {
               prec = corr;
               corr = corr->next;
          }
          
          if (prec == NULL)
          {
              nuovoNodo->next = t;
              t = nuovoNodo;
          }
          else
          {
              prec->next = nuovoNodo;
              nuovoNodo->next = corr;
          }
     }
    }
    else 
    { 
         printf("\nIl numero da inserire non e' pari!\n\n"); 
         return t;
    }
    
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
