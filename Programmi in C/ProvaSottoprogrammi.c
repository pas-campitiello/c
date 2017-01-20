#include <stdio.h>

int SceltaMenu();
void StampaMenu();

int main ()
{
    int sel;
    
    sel=SceltaMenu();
    printf("\n");
    
    switch (sel)
    {
          case 1: printf("Hai scelto l'operazione 1 ..."); break;
          case 2: printf("Hai scelto l'operazione 2 ..."); break;
          case 3: printf("Hai scelto l'operazione 3 ..."); break;
          default: printf("ATTENZIONE!\nIL NUMERO SELEZIONATO NON RIENTRA NELL'ELENCO DELLE OPERAZIONI POSSIBILI."); break;
    }
    
    printf("\n\n\n");
    system("Pause");
    
}


// --------- SOTTOPROGRAMMI ------------

int SceltaMenu()
{
    int s;
    
    do
    {
        StampaMenu();                                      // chiamata a StampaMenu();
        printf("Inserire il numero dell'operazione da eseguire? (1/2/3) ");
        scanf("%d",&s);
    }
    while (s<0);
    
    return s;
}

void StampaMenu()
{
     printf("--- MENU ---------\n");
     printf("1: operazione1...\n");
     printf("2: operazione2...\n");
     printf("3: operazione3...\n\n");
}
