// Domanda 3 - 2ª prova in itinere - 30 gennaio 2004

#include <stdio.h>
#define MaxCar 20

typedef struct
{
  char nome[MaxCar];
  char cognome[MaxCar];
  int eta;
} Anagrafe;

void RiempiDati(Anagrafe *p);

int main()
{
    Anagrafe persona;
    
    RiempiDati(&persona);
    
    printf("\nNOME: %s",persona.nome);
    printf("\nCOGNOME: %s",persona.cognome);
    printf("\nETA': %d",persona.eta);
    
    printf("\n\n");
    system("PAUSE");
}

void RiempiDati(Anagrafe *p)
{
     printf("Nome: ");
     gets(p->nome);
     printf("Cognome: ");
     gets(p->cognome);
     printf("Eta': ");
     scanf("%d",&p->eta);
}
