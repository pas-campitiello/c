// Domanda 3 - 2ª prova in itinere - 4 febbraio 2005

#include <stdio.h>
#define LimVet 5
#define MaxCar 20
#define M 3

typedef struct
{
    int matricola;
    char nome[MaxCar+1];
    char cognome[MaxCar+1];
    
} Studente;

typedef struct ListaStudente
{
    Studente info;
    struct ListaStudente *next;
} Lista_t;

Lista_t * InsCodaCrea(Lista_t *t, Studente stud);
void StampaLista (Lista_t *t);
int MatricoleMinori3500(Lista_t *t, Studente arr[], int dim);
void StampaVettore(Studente vet[],int dim);

int main ()
{
    Lista_t *testa = NULL;
    Studente s,vet[M];
    int err;
    
    printf("========= CARICAMENTO DELLA LISTA DATI DEGLI STUDENTE CON InsCodaCrea =========\n\n");
    printf("Matricola studente (per terminare inserisci 0): ");
    scanf("%d",&s.matricola);           // qui si dovrebbe controllare pure che la matricola non sia già stata inserita
    
    if (s.matricola==0)
    {
         printf("\n\n");
         system("PAUSE"); 
         return 0;
    }
    else
     while(s.matricola)
     {
          printf("Nome studente: ");
          scanf("%s",s.nome);
          printf("Cognome studente: ");
          scanf("%s",s.cognome);

          testa = InsCodaCrea(testa,s);
         
          printf("\nMatricola studente (per terminare inserisci 0): ");
          scanf("%d",&s.matricola);
     }
    
    printf("\n--------------------------------------------------------------------\n");
    printf("\nLa lista creata con InsCodaCrea e':\n\n");
    StampaLista(testa);
    printf("--------------------------------------------------------------------\n");

    err = MatricoleMinori3500(testa,vet,M);
    
    if (err==1) printf("\n -> 1 -> (il vettore e' stato riempito totalmente)");
    else printf("\n -> 0 (il vettore non e' stato riempito totalmente)");
    
    printf("\n\n\n");
    system("PAUSE");
}

Lista_t * InsCodaCrea(Lista_t *t, Studente stud)
{
    int i;
    Lista_t *n,*p;
    
    if ( n = (Lista_t *) malloc(sizeof(Lista_t)) )
    {
         n->info.matricola = stud.matricola;
         for (i=0; i<MaxCar; i++) n->info.nome[i] = stud.nome[i];
         for (i=0; i<MaxCar; i++) n->info.cognome[i] = stud.cognome[i];
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
        printf(" Matricola: %d\n",t->info.matricola);
        printf(" Nome: %s\n",t->info.nome);
        printf(" Cognome: %s\n",t->info.cognome);
        printf("\n");
        
        t = t->next;
    }
}

int MatricoleMinori3500(Lista_t *t, Studente arr[], int dim)
{
    int i,j;
    
    i=0;
    while (t)
    {
        if (t->info.matricola < 3500)
        {
            arr[i].matricola = t->info.matricola;
            for (j=0; j<MaxCar; j++) arr[i].nome[j] = t->info.nome[j];
            for (j=0; j<MaxCar; j++) arr[i].cognome[j] = t->info.cognome[j];
            i++;
        }
        
        t = t->next;
        
        if (i>M)
        {
            StampaVettore(arr,i); 
            return 1;
        }
    }
    
    StampaVettore(arr,i);
    return 0;
}

void StampaVettore(Studente vet[],int dim)
{
    int j;
    
    printf("\nStampa del vettore creato (con studenti aventi matricola < 3500):\n");
    for (j=0; j<dim; j++) 
    {
        printf(" MATR.: %d  ",vet[j].matricola);
        printf("NOME: %s  ",vet[j].nome);
        printf("COGNOME: %s  ",vet[j].cognome);
        printf("\n");
    }
}
