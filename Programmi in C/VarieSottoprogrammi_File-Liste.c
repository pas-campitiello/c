#include <stdio.h>
#define NOME "Dati0.txt"

typedef struct listas
{
    int info;
    struct listas *next;
} Lista_t;

Lista_t * InsCodaCrea(Lista_t *t,int num);
void StampaLista(Lista_t *t);
void Cerca(Lista_t *,int);
int IsPrime(int n);
void PrimiLista(Lista_t *t);
int SommaLista(Lista_t *t);

int main()
{
    Lista_t *testa = NULL;
    int num,cerc,sum;
    FILE * MioFile;
    
    if (MioFile = fopen(NOME,"r"))
    {    
        fscanf(MioFile,"%d",&num);
        
        while(!feof(MioFile))
        {
            testa = InsCodaCrea(testa,num);
            fscanf(MioFile,"%d",&num);
        }
        
        fclose(MioFile);
    }
    else 
    {
         printf("\nErrore nell'apertura del file!\n\n");
         system("PAUSE");
         return 0;
    }
    
    printf("La lista creata dal file con InsCodaCrea e': ");
    StampaLista(testa);
    
    printf("\n\nInserisci il numero da cercare: ");
    scanf("%d",&cerc);
    
    Cerca(testa,cerc);
    
    printf("\nStampa dei numeri primi presenti nella lista: ");
    PrimiLista(testa);
    
    sum = SommaLista(testa);
    printf("\n\nSomma dei numeri presenti nella lista: %d",sum);
    
    printf("\n\n\n");
    system("PAUSE");
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

void StampaLista(Lista_t *t)
{
     while(t)
     {
          printf("%d ",t->info);
          t = t->next;
     }
}

void Cerca(Lista_t *t, int n)
{
     if (t!=NULL)

       if (t->info == n) printf(" -----> TROVATO\n");
       else Cerca(t->next,n);

     else printf(" -----> NON TROVATO\n");
}

int IsPrime(int n)
{
    int i;
    
    if (n==2) return 1;
    
    if ((n%2)==0) return 0;
   
    i = 3;
    while ( (n%i) && (i < (n+1)/2) ) i = i + 2;
   
    if ( (n%i) || (n==3) ) return 1;
   
    return 0;
}


void PrimiLista(Lista_t *t)
{
     while(t!=NULL)
     {
         if (IsPrime(t->info)) printf("%d ",t->info);
         t = t->next;
     }
}

int SommaLista(Lista_t *t)
{
    if (t->next == NULL) return (t->info);                               // qui all'ultimo passaggio non somma nulla 
    // if (t == NULL) return 0;    Versione mia -> Fa però un passaggio in più: all'ultimo passaggio somma 0
    else return (t->info + SommaLista(t->next));
}
