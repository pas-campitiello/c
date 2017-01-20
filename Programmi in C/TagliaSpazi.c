#include<stdio.h>
#define N 100

int vuoto(char vet[],int posCorr);

int main()
{
    char a[N+1];
    int i,p;

    printf("Inserire la stringa: ");
    gets(a);
    
    printf("\nLa stringa inserita e': ---%s---\n\n",a);
    
    printf("Cancellando gli spazi finali e iniziali la stringa e':\n\n---");
    
    i=0;
    p=0;
    
    while (a[i]!='\0')
    {
       if ((a[i]==' ') && (p!=1) ) i++;
       else
       {
          printf("%c",a[i]);
          
          i++; p=1;
          
          if ( vuoto(a,i)==0 ) a[i]='\0';
          else 
          {
              printf("%c",a[i]);
              
              i++;
          }
       }
    }

    printf("---");
    
    printf("\n\n");
    system("pause");          
}

int vuoto(char vet[],int posCorr)
{
    int i;
   
    for(i=posCorr; (vet[i]!='\0'); i++) 
     if (vet[i]!=' ') return i;
    
    return 0;
}
