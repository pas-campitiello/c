#include <stdio.h>
#define N 1000

int main()
{
    char str[N+1];
    int L,i,contC,contPar;
    
    printf("Inserire la stringa (max %d caratteri; terminare con un punto \".\"):\n",N);
    gets(str);        
    
    L=0;
    while ((str[L]!='\n') && (str[L]!='\0')) L++;  //Conta lunghezza stringa
    
    while ((L>N) || (str[L-1]!='.'))
    {
        printf("ATTENZIONE! Max %d caratteri e terminare con un punto \".\"!\n\nInserire la stringa: ",N);
        gets(str);
        
        L=0;
        while ((str[L]!='\n') && (str[L]!='\0')) L++;
    }
    
    contPar=0;
    contC=0;
    for (i=0;i<L;i++)
    {
        if ( ((str[i]!=' ') && (str[i]!='.') && (str[i]!=',') && (str[i]!=';') && (str[i]!='!') && (str[i]!='?')) && ((str[i+1]==' ') || (str[i+1]=='.') || (str[i+1]==',') || (str[i+1]==';') || (str[i+1]=='!') || (str[i+1]=='?')) ) contPar++;
        if ( ((str[i]=='C') || (str[i]=='c')) && ((i==0) || (str[i-1]==' ') || (str[i-1]=='.') || (str[i-1]==',') || (str[i-1]==';') || (str[i-1]=='!') || (str[i-1]=='?')) ) contC++;        
    }
    
    printf("\nLa frase contiene %d parole, %d inizia/iniziano con la lettera C",contPar,contC);
    
    printf("\n\n");
    system("Pause");
}
