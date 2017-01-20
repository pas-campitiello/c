#include <stdio.h>

int main ()
{
    FILE* fpp;
    int i,lung;
    char *p;
    
    if ( fpp = fopen("Stringhe.txt","r") )
    {
        while (!feof(fpp))
        {
           fscanf(fpp,"%d",&lung);
           printf("%d ",lung);
          
           if ( p = (char *) malloc(lung * sizeof(char)) )
           {
              for (i=0; i<lung; i++)
              {
                 fscanf(fpp,"\n%c",(p+i));
                 printf("%c",*(p+i));
              }
              
              fscanf(fpp,"\n");
              
              printf("\n");
              
              free(p);
           }
           else printf("\n\nMemoria esaurita!"); 
        }
        
        fclose(fpp);
    }
    else 
    {
         printf("\nERRORE NELL'APERTURA DEL FILE!\n\n");
         system("PAUSE");
         return 0;
    }
    
    printf("\n\n");
    system("PAUSE");
}
