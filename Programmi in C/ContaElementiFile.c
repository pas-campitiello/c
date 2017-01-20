#include <stdio.h>

int main ()
{
    FILE* fpp;
    int cont;
    //char v[3];
    int v;
     
    fpp = fopen("LABs/Numeri.txt","r"); 
    
    cont=0;
    
    if (fpp)
    {
           
        fscanf(fpp,"%d",&v);
        printf("%d\n",v);
        while ( !feof(fpp) )
        {   
            cont++;
            
            fscanf(fpp,"%d",&v);
            printf("%d\n",v);
        }
        
        fclose(fpp);
    }
    else 
    {
         printf("\nERRORE NELL'APERTURA DEL FILE!\n\n");
         system("PAUSE");
         return 0;
    }
    
    printf("\nGli elementi presenti nel file sono %d",cont+1);
    
    printf("\n\n");
    system("PAUSE");
}
