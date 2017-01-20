//Campitiello Pasquale
//678542

#include <stdio.h>
#define N_MAX 20

int main() {

int n,i,j;
int matrix[N_MAX][N_MAX];

   printf("inserire la dimensione della matrice: ");
   scanf("%d", &n);
      while ((n < 1) || (n > N_MAX))
      {
         printf("ERRORE inserire una matrice di dimensioni comprese tra 1 e 20: ");
         scanf("%d", &n);
      }
      
      for(i=0; i < n; i++)
      {
            for(j=0; j < n; j++)
              {
               printf("inserire il valore della matrice nel punto %d %d: ", i+1,j+1);         
               scanf("%d", &matrix[i][j]);         
              }        
      } 
      
      for(i=0; i < n; i++)
      {
            for(j=0; j < n; j++) printf("%d ", matrix[i][j]); 
            
            printf("\n");
      } 
           printf("\n"); 
                   
      for(i=0; i < n; i++)
      {
            for(j=n-1; j >= 0; j--)
            printf("%d ", matrix[j][i]); 
            
            printf("\n");                    
      }          
  
  printf("\n\n");          
  system("PAUSE");
}
