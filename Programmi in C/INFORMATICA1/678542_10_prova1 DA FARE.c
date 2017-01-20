// 678542 Pasquale Campitiello
// Computer n°2

#include <stdio.h>
#define NC 10

int ContaCar(char *s, char t);

int main()
{
    char str[NC+1], cerca;
    int pres,i;
    FILE *IN,*OUT;
         
    printf("Inserisci il carattere da cercare nelle stringhe del file in.txt: ");
    scanf("%c",&cerca);
    
    if ( IN = fopen("in.txt","r") )
    {
        if ( OUT = fopen("out.txt","w") )
        {
          while (!feof(IN))
          {
              fgets("%s",str,IN);
           
              printf("%s",str); getch();
              fprintf(OUT,"%d\n",ContaCar(str,cerca));
          }
          
          fclose(OUT);
        }    
        else 
        {
            printf("\nERRORE NELLA CREAZIONE DEL FILE out.txt!\n\n");
            system("PAUSE");
            return 0;
        }
        
        fclose(IN);
    }
    else 
    {
         printf("\nERRORE NELL'APERTURA DEL FILE in.txt!\n\n");
         system("PAUSE");
         return 0;
    }

    printf("\n\n");
    system("PAUSE");
}

int ContaCar(char *s, char t)
{
    int cont,i;
    
    cont = 0;
    for (i=0; s[i]!='\0'; i++)
     if (s[i]==t) cont++;
    
    return cont;
}
