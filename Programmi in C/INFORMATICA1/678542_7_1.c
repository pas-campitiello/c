// Campitiello Pasquale
// 678542
// PC n 10

#include <stdio.h>
#define N 30

int* crea(int vet[], int dim, int numP);

int main ()
{
    int a[N];
    int m,i,pari;
    int *nuovo;
    
// CHIUDO ALL'UTENTE QUANTI NUMERI VUOLE INSERIRE
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d",&m);       

    while ((m<0) || (m>N))
    {
        printf("ATTENZIONE! Max %d numeri!\n\nQuanti numeri vioi inserire? ",N);
        scanf("%d",&m); 
    }
    printf("\n");
    
    for (i=0; i<m; i++)
    {
        printf("Elemento [%d]: ",i);
        scanf("%d",&a[i]);
    }

// CONTO I NUMERI PARI PRESENTI NELL'ARRAY
    pari=0;
    for (i=0; i<m; i++)
     if ( a[i]%2==0 ) pari++;
    
    nuovo=crea(a,m,pari);
    printf("\nI numeri pari sono: ");

// STAMPO IL CONTENUTO DELLA MEMORIA ALLOCATA
    for(i=0; i<pari; i++)
     printf("%d ",*(nuovo+i));
    
    printf("\n\n");
    system("Pause");
}

int* crea(int vet[], int dim, int numP)
{
    int *p;
    int i,j;
    
    if (p = (int*) malloc(numP * sizeof(int)))
    {
       i=0; 
       j=0;
        
        while(i<dim)
        {       
           if ( vet[i]%2==0 ) 
           {
               *(p+j)=vet[i]; 
               j++; 
           } 
           
           i++;   
        }    
    }
    else printf("MEMORIA ESAURITA!");
    
    return p; 
}
