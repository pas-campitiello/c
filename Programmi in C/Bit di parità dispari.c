#include <stdio.h>
#define N 35

int main()
{
    char str[N+2];  //"+2" perchè str oltre al carattere terminatore potrà contenere anche il bit di parità dispari
    int L,i,err,contUNO;
    
    printf("Inserire la stringa costituita da '0' e '1' (max %d caratteri):\n",N);
    gets(str);        
    
// Conta lunghezza stringa
    L=0;
    while ((str[L]!='\n') && (str[L]!='\0')) L++;
    
// Controlla se la stringa contiene solo "0" e "1"
    i=0;
    err=0;
    while ((i<L) && (err!=1))
    {
        if ((str[i]!='1') && (str[i]!='0')) err=1;
        i++;
    }

// Ripetizione dell'inserimento
    while ((L>N) || (err==1))
    {
        printf("ATTENZIONE!\nMax %d caratteri! La stringa deve essere costituita solo da '0' e '1' !\n\nInserire la stringa: ",N);
        gets(str);
        
        // Conta lunghezza stringa
            L=0;
            while ((str[L]!='\n') && (str[L]!='\0')) L++;
    
        // Controlla se la stringa contiene solo "0" e "1"
           i=0;
           err=0;
           while ((i<L) && (err!=1))
           {
            if ((str[i]!='1') && (str[i]!='0')) err=1;
            i++;
           }
    }
    
// Conteggio degli '1' nella stringa
    contUNO=0;
    for (i=0; i<L; i++) if (str[i]=='1') contUNO++;

// Aggiunta e stampa del bit di parità dispari
    if (contUNO%2==0) str[L]=str[L]+'1';
    printf("\nLa stringa risultante dopo l'aggiunta del bit di parita' dispari e':\n");
    for (i=0; i<L+1; i++) printf("%c",str[i]);
    
    printf("\n\n");
    system("Pause");
}
