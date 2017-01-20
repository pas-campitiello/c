// 678542 Pasquale Campitiello
// Computer n°2

#include <stdio.h>
#define MaxCar 20

typedef struct
{
    char nome[MaxCar+1];
    char cognome[MaxCar+1];
    int media;
    
} Studente;

typedef struct ListaStudente
{
    Studente info;
    struct ListaStudente *next;
} Lista_t;

Lista_t * inserisciLista(Lista_t *t, Studente stud);
void StampaLista (Lista_t *t);

int main ()
{
    Lista_t *testa = NULL;
    Studente s;
    int scelta;
    
// CARICA LISTA
    printf("CARICA LA LISTA\n\n");
    printf("Nome studente (per terminare inserisci ""N""): ");
    scanf("%s",s.nome);
    
    if (s.nome[0]=='N')
    {
         printf("\n\n");
         system("PAUSE"); 
         return 0;
    }
    else
     while(s.nome[0]!='N')
     {
          printf("Cognome studente: ");
          scanf("%s",s.cognome);
          
          printf("Media dello studente studente: ");
          scanf("%d",&s.media);

          testa = inserisciLista(testa,s);
         
          printf("Nome studente (per terminare inserisci ""N""): ");
          scanf("%s",s.nome);
    }
    
    
    printf("\n---MENU---\n");
    printf("\n1-> Inserimento nuovo nominativo");
    printf("\n2-> Stampa la lista dei nominativi ");    
    printf("\n3-> Uscita\n\n");
    printf("Inserisci la tua scelta: ");
    scanf("%d",&scelta);
    printf("\n");
    
    switch (scelta)
    {
         case 1: 
          
          printf("Nome studente (per terminare inserisci ""N""): ");
          scanf("%s",s.nome);
    
          printf("Cognome studente: ");
          scanf("%s",s.cognome);
          
          printf("Media dello studente studente: ");
          scanf("%d",&s.media);

          testa = inserisciLista(testa,s);
          
          printf("\n--------------------------------------------------------------------\n");
          printf("\nLa lista creata con inserisciLista e':\n\n");
          StampaLista(testa);
          printf("--------------------------------------------------------------------\n");     
         
          break;
          
         case 2:
             
          printf("\n--------------------------------------------------------------------\n");
          printf("\nLa lista creata con inserisciLista e':\n\n");
          StampaLista(testa);
          printf("--------------------------------------------------------------------\n");     
         
          break;
          
         case 3:
                       
          printf("\n\n\n");
          system("PAUSE");
          return 0;
    }
    
    system("PAUSE");
}

Lista_t * inserisciLista(Lista_t *t,Studente stud)
{
    Lista_t * prec;
    Lista_t * corr;
    Lista_t * nuovoNodo;
    int i;
    
    if ( nuovoNodo = (Lista_t*)malloc(sizeof(Lista_t)) )
    {
         for (i=0; i<MaxCar; i++) nuovoNodo->info.nome[i] = stud.nome[i];
         for (i=0; i<MaxCar; i++) nuovoNodo->info.cognome[i] = stud.cognome[i];
         nuovoNodo->info.media = stud.media;
         nuovoNodo->next = NULL;
         
         prec = NULL;
         corr = t;
          
         while ( (corr!= NULL) && (corr->info.cognome > stud.cognome) )
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
    else printf("MEMORIA ESAURITA!");
    
    return t;
}

void StampaLista (Lista_t *t)
{
    while (t)
    {
        printf(" Nome: %s\n",t->info.nome);
        printf(" Cognome: %s\n",t->info.cognome);
        printf(" Media: %d",t->info.media);
        printf("\n");
        
        t = t->next;
    }
}
