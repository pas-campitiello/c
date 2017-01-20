#include <stdio.h>

typedef struct listas 
{
    int info;
    struct listas *next;
} Lista_t;

Lista_t * InsCodaCrea(Lista_t *t,int num);
void StampaLista (Lista_t *t);
int Cancella(Lista_t *t);

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
    
    num = Cancella(testa);
    printf("\nNumero di elementi cancellati: %d\n",num);
         
    printf("\nNuova lista stampata dal Main");
    printf("\n(eventuali errori sono dovuti al fatto che la testa non e' stata passata per indirizzo (doppio puntatore)): ");
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

void StampaLista (Lista_t *t)
{
    while (t)
    {
        printf("%d ",t->info);
        
        t = t->next;
    }
}

int Cancella(Lista_t *t)
{
    Lista_t *prec, *corr, *tmp;
    int cont,elem;
    
    if (t==NULL) {printf("LISTA VUOTA!"); return 0;}
    else
    {
        printf("\nElemento da cancellare: ");
        scanf("%d",&elem);
        
        prec = NULL;
        corr = t;
        cont = 0;
        
        while (corr != NULL)
        {
           if (corr->info == elem)
           {
              if (prec==NULL)
              {
                  tmp = t;
                  t = t->next;
               
                  corr = t;
                   
                  free(tmp); cont++;
              }
              else
              {
                  tmp = corr;
                  prec->next = corr->next;
               
                  corr = prec->next;
               
                  free(tmp); cont++;
              }
           }
           else
           {
                prec = corr;
                corr = corr->next;
           }
        }
    }
    
    printf("\nLa nuova lista e': ");
    StampaLista(t);
    
    return cont;
}
