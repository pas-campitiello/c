//Campitiello Pasquale
//678542

#include <stdio.h>
#define N 30

int main()
{
    char str1[N+1],str2[N+1];
    int L1,L2,MaxL,contUG,i,OrdStr;
    
    printf("Scrivi la 1a stringa (max %d caratteri): ",N);
    gets(str1);        
    
    L1=0;
    while ((str1[L1]!='\n') && (str1[L1]!='\0')) L1++;  //Conta lunghezza stringa
    
    while(L1>N)
    {
        printf("ATTENZIONE! Max %d caratteri!\nScrivi la 1a stringa: ",N);
        gets(str1);
        
        L1=0;
        while ((str1[L1]!='\n') && (str1[L1]!='\0')) L1++;
    }
    
    printf("Scrivi la 2a stringa (max %d caratteri): ",N);
    gets(str2);
    L2=0;
    while ((str2[L2]!='\n') && (str2[L2]!='\0')) L2++;  
    
    while(L2>N)
    {
        printf("ATTENZIONE! Max %d caratteri!\nScrivi la 2a stringa: ",N);
        gets(str2);
        
        L2=0;
        while ((str2[L2]!='\n') && (str2[L2]!='\0')) L2++;
        
    }
    
// VERIFICA UGUAGLIANZA STRINGHE
    contUG=0;
    if (L1==L2)
        for (i=0; i<L1; i++)
            if (str1[i]==str2[i]) contUG++;
    
    if (contUG==L1) printf("\nLe stringhe sono uguali");
               else printf("\nLe stringhe non sono uguali");
    
    if (L1>L2) MaxL=L1;
          else MaxL=L2;

// ORDINAMENTO ALFABETICO STRINGHE
    OrdStr=0;
    i=0;
    while ((OrdStr!=1) && (i!=MaxL))
    { 
        if (str1[i]>str2[i]) 
           {
            printf("\n\nLe stringhe in ordine alfabetico sono:\n %s \n %s",str2,str1);
            OrdStr=1;
           }
        else if (str1[i]<str2[i]) 
                {
                 printf("\n\nLe stringhe in ordine alfabetico sono:\n %s \n %s",str1,str2);
                 OrdStr=1;
                }
             else if (str1[i]=str2[i]) i++;
    }
    
    if (i==MaxL) printf("\n\nLe stringhe in ordine alfabetico sono:\n %s \n %s",str1,str2);
    
    printf("\n\n");
    system("Pause");
}
