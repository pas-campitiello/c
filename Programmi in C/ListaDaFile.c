#include <stdio.h>

typedef struct listas 
{
    int info;
    struct listas *next;
} Lista_t;

Lista_t * InsCodaCrea(Lista_t *t,int num);
void StampaLista (Lista_t *t);

int main()
{
    Lista_t *testa = NULL;
    FILE *FileIn;
    int num;
    
    if ( FileIn = fopen("Interi.txt","r") )
    {
        fscanf(FileIn,"%d",&num);
        testa = InsCodaCrea(testa,num);
        
        while (!feof(FileIn))
        {
            fscanf(FileIn,"%d",&num);
            testa = InsCodaCrea(testa,num);
        }
        
        fclose(FileIn);
    }
    else 
    {
         printf("\nERRORE NELL'APERTURA DEL FILE!\n\n");
         system("PAUSE");
         return 0;
    }
    
    printf("La lista acquisita da file e creata con InsCodaCrea e': ");
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
