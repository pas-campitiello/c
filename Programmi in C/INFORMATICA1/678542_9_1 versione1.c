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
    
    printf(".. Inserire una lista ordinata in senso decrescente ..\n");
    printf("Inserisci un numero (termina con 0): ");
    scanf("%d",&Nm);
    
    while (Nm)
    {
        testa = InsCodaCrea(testa,Nm);
        
        printf("Inserisci un numero (termina con 0): ");
        scanf("%d",&Nm);
    }
    
    printf("\nLa lista creata e': ");
    StampaLista(testa); 
    
    printf("\n\nNuovo elemento da inserire nella lista: ");
    scanf("%d",&Nm);
    
    testa = InsOrd(testa,Nm);
    
    printf("\n\nLa lista dopo l'inserimento di %d e': ",Nm);
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

    if ((num%2)==0)
    {
      if (t==NULL)
      {
         if ( nuovoNodo = (Lista_t *) malloc(sizeof(Lista_t)) )
         {
            nuovoNodo->info = num;
            nuovoNodo->next = NULL;
         
            return nuovoNodo;
         }
         else printf("\n\nMemoria esaurita!");
      }
      else 
       if (t->info<num)
       {
           if ( nuovoNodo = (Lista_t *) malloc(sizeof(Lista_t)) )
           {
              nuovoNodo->info = num;
              nuovoNodo->next = t;
         
              return nuovoNodo;
            }
            else printf("\n\nMemoria esaurita!");
       }
      else
      {   
         prec = t;
         corr = t->next;
         while (corr != NULL)
         {
             if (corr->info < num)
             {
                 if ( nuovoNodo = (Lista_t *) malloc(sizeof(Lista_t)) )
                 {
                     nuovoNodo->info = num;
                     nuovoNodo->next = corr;
                     prec->next = nuovoNodo;
         
                     return t;
                 }
                 else printf("\n\nMemoria esaurita!!!");
             }
             else
             {
                 prec = corr;
                 corr = corr->next;
             }
         }
         if (prec->info > num)
         {
             if ( nuovoNodo = (Lista_t *) malloc(sizeof(Lista_t)) )
             {
                 nuovoNodo->info = num;
                 nuovoNodo->next = NULL;
                 prec->next = nuovoNodo;
         
                 return t;
              }
              else printf("\n\nMemoria esaurita!!!");
         }
         return t;
      }
    }
    else 
    {
        printf("Il numero non e' pari!");
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
