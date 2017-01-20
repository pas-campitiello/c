// Domanda 4 - 2ª prova in itinere - 30 gennaio 2004

#include <stdio.h>
#define LimVet 5
#define MaxCar 20
#define M 3

typedef struct
{
    float gradi;
    int ora;
} Dati_temp;

typedef struct Listas
{
    Dati_temp info;
    struct Listas *next;
} Lista_t;

Lista_t * InsCodaCrea(Lista_t *t, Dati_temp Dati);
void StampaLista (Lista_t *t);
float MediaTemp(Lista_t *t, int eInf, int eSup);
Lista_t * CancellaTemp(Lista_t *t, int ora);

int main ()
{
    Lista_t *testa = NULL;
    Dati_temp t;
    float estr1,estr2,media;
    int oraCanc;
    
    printf("================== CARICAMENTO DELLA LISTA CON InsCodaCrea ==================\n");
    printf("\nTemperatura in centigradi (per terminare inserisci -333): ");
    scanf("%f",&t.gradi);
    while( (t.gradi < -273.15) && (t.gradi!=-333) )
    {
         printf("ATTENZIONE! TEMPERATURA < -273.15!\nTemperatura in centigradi (per terminare inserisci -333): ");
         scanf("%f",&t.gradi);
    }
    
    if (t.gradi==-333)
    {
         printf("\n\n");
         system("PAUSE"); 
         return 0;
    }
    else
     while(t.gradi!=-333)
     {
          printf("Ora: ");
          scanf("%d",&t.ora);
          while ( (t.ora<0) || (t.ora>23) )
          {
              printf("ATTENZIONE! ORA < 0 oppure > 23!\nOra: ");
              scanf("%d",&t.ora);
          }
         
          testa = InsCodaCrea(testa,t);
        
          printf("\nTemperatura in centigradi (per terminare inserisci -333): ");
          scanf("%f",&t.gradi);
          while( (t.gradi < -273.15) && (t.gradi!=-333) )
          {  
              printf("ATTENZIONE! TEMPERATURA < -273.15!\nTemperatura in centigradi (per terminare inserisci -333): ");
              scanf("%f",&t.gradi);
          }
     }
    
    printf("\n--------------------------------------------------------------------------\n");
    printf("La lista creata con InsCodaCrea e':\n");
    StampaLista(testa);
    printf("--------------------------------------------------------------------------\n");

// RICERCA DELLE TEMPERATURE E VISUALIZZAZIONE DELLA MEDIA
    printf("\n:: Ricerca delle temperatura e visualizzazione della media ::\n\n");

    printf("Intervallo temperature -> Estremo inferiore: ");
    scanf("%f",&estr1);
    while( (estr1 < -273.15))
    {
         printf("ATTENZIONE! TEMPERATURA < -273.15!\nIntervallo temperature -> Estremo inferiore: ");
         scanf("%f",&estr1);
         printf("\n");
    }

    printf("Intervallo temperature -> Estremo superiore: ");
    scanf("%f",&estr2);
    while( (estr2 < -273.15) || (estr2<=estr1))
    {
         printf("ATTENZIONE! TEMPERATURA < -273.15 oppure <= dell'estremo inf!\nIntervallo temperature -> Estremo inferiore: ");
         scanf("%f",&estr2);
         printf("\n");
    }
    
    media = MediaTemp(testa,estr1,estr2);
    
    printf("\nLa media delle temperature dell'intervallo [%.2f,%.2f] e': %.2f",estr1,estr2,media);

// CANCELLAZIONE TEMPERATURA AD UNA DATA ORA
    printf("\n\n\n:: Cancellazione temperature ad una data ora ::\n\n");
    
    printf("Ora: ");
    scanf("%d",&oraCanc);
    while ( (oraCanc<0) || (oraCanc>23) )
    {
        printf("ATTENZIONE! ORA < 0 oppure > 23!\nOra: ");
        scanf("%d",&oraCanc);
    }
    
    testa = CancellaTemp(testa,oraCanc);
    
    printf("\n--------------------------------------------------------------------------\n");
    printf("La lista dopo la cancellazione e':\n");
    StampaLista(testa);
    printf("--------------------------------------------------------------------------\n");
    
    printf("\n\n\n");
    system("PAUSE");
}

Lista_t * InsCodaCrea(Lista_t *t, Dati_temp Dati)
{
    Lista_t *n,*p;
    
    if ( n = (Lista_t *) malloc(sizeof(Lista_t)) )
    {
         n->info.gradi = Dati.gradi;
         n->info.ora = Dati.ora;
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
        printf("\n Indirizzo: %d\n",t);
        printf(" Gradi: %.2f\n",t->info.gradi);
        printf(" Ora: %d\n",t->info.ora);
        
        t = t->next;
    }
}

float MediaTemp(Lista_t *t, int eInf, int eSup)
{
    float sum;
    int c;
    
    c = 0;
    sum = 0;
    while (t)
    {   
        if ((t->info.gradi >= eInf) && (t->info.gradi <= eSup))
        {
            sum = sum + t->info.gradi;
            c++;
        }

        t = t->next;
    }
    
    if (sum>0) return (sum/c);
    else
    {
        printf("\nNella lista non esistono temperature comprese nell'intervallo specificato!");
        return 0;
    }
}

Lista_t * CancellaTemp(Lista_t *t, int ora)
{
    Lista_t *prec, *corr, *tmp;
    
    prec = NULL;
    corr = t;
    while (corr != NULL)
    {
        if (corr->info.ora == ora)
        {
           if (prec==NULL)
           {
               tmp = t;
               t = t->next;
               
               corr = t;
                  
               free(tmp);
           }
           else
           {
               tmp = corr;
               prec->next = corr->next;
               
               corr = prec->next;
               
               free(tmp);
           }
        }
        else
        {
              prec = corr;
              corr = corr->next;
        }
    }
         
    return t;
}
