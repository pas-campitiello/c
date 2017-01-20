// Campitiello Pasquale
// 678542
// PC n 10

#include <stdio.h>
#define C 8
#define INT 10

int main ()
{
    FILE* MioFile;
    int val,freq[INT],i,aster;
    char nome[C+1];
     
    printf("Inserire il nome del file da caricare: "); 
    gets(nome);
    
    for(i=0; i<INT; i++) freq[i]=0;

    if ( MioFile = fopen(nome,"r") )
    {
      printf("\nContenuto del file:\n");
      
      fscanf(MioFile,"%d",&val);
      printf("%d\n",val);
      if ( (val>=0) && (val<=INT-1) ) freq[val] = freq[val]+1;
      while( !feof(MioFile) )
      {
          fscanf(MioFile,"%d",&val);
          printf("%d\n",val);    
          if ( (val>=0) && (val<=INT-1) ) freq[val] = freq[val]+1;
      }
      
      fclose(MioFile);
      
      printf("\n\nFrequenze:\n");
      
      for (i=0; i<INT; i++)
       if (freq[i]>=1)
       {
           printf("%d: ",i);
           for (aster=0; aster<freq[i]; aster++) printf("*");
           printf("\n");
       }
    }
    else printf("Il file indicato NON esiste!");

    printf("\n\n");
    system("PAUSE");
}
