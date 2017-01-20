#include <stdio.h>

int main ()
{
    FILE *in,*out;
    int *Mem,i,contNum;     

    if (in = fopen("in.txt","r"))                        // Apro in.txt in lettura
    {
        // Conteggio elementi presenti in in.txt   
        contNum=0;  
        while (!feof(in))
        {
            fscanf(in,"%s");
            contNum++;
        }
        
        fclose(in);
        if (in = fopen("in.txt","r"))                    // Chiudo e riapro in.txt per riposizionarmi all'inizio del file 
        {
            // Richiedo la memoria
            if (Mem = (int *) malloc(contNum * sizeof(int)))        
            {           
                if (out = fopen("out.txt","w"))          // Apro out.txt in scrittura
                {
                    // Metto gli elementi di in.txt nella memoria allocata
                    for (i=0; i<contNum; i++) fscanf(in,"%d",(Mem+i));
                    
                    printf("I numeri di in.txt in ordine inverso sono: ");
                    for (i--; i>=0; i--)
                    {
                        fprintf(out,"%d ",*(Mem+i));
                        printf("%d ",*(Mem+i));
                    }

                    fclose(out);
                }
                else 
                {
                    printf("ERRORE NELLA CREAZIONE DEL FILE out.txt!\n\n");
                    system("PAUSE");
                    return 0;
                }

                free(Mem);                                  // Libero la memoria
            }
            else printf("\n\nMemoria esaurita!");  

            fclose(in);
        }
        else 
        {
            printf("ERRORE NELLA SECONDA APERTURA DEL FILE in.txt!\n\n");
            system("PAUSE");
            return 0;
        }
    }
    else 
    {
         printf("ERRORE NELLA PRIMA APERTURA DEL FILE in.txt!\n\n");
         system("PAUSE");
         return 0;
    }

// Visualizzazione del file out.txt 
    printf("\n\nVisualizzazione del file out.txt: ");
    
    if (Mem = (int *) malloc(contNum * sizeof(int)))        
    {           
         if (out = fopen("out.txt","r"))                // Apro out.txt in lettura
         {   
            // Visualizzo gli elementi
            for (i=0; i<contNum; i++)
            {
                fscanf(out,"%d",(Mem+i));
                printf("%d ",*(Mem+i));
            } 
            
            free(Mem);                                  // Libero la memoria
         }
         else 
         {
             printf("ERRORE NELLA SECONDA APERTURA DEL FILE out.txt!\n\n");
             system("PAUSE");
             return 0;
         }
    } 
    else printf("\n\nMemoria esaurita!");  

    
    printf("\n\n");
    system("PAUSE");
}
