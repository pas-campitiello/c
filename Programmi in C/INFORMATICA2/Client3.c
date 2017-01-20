/* ESE 3 Client
Programma Client che invia ad un programma Server una stringa (sia carattere per carattere che tutta in una volta). Il Server
riceve la stringa, la visualizza e trasmette al Client la lunghezza della stessa.

NON CORRETTO PER BENE
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

#define SRV_PORT 4000
#define SRV_IP "127.0.0.1"
#define MaxCar 20
#define TERM "\t"

int main()
{
    int sd;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int srvlen = sizeof(server_addr);
    int client_len = sizeof(client_addr);
    char str[MaxCar+1],strLUNG[3];
    int i,n;
    
// Address initialization
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons((u_short)SVR_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SRV_IP);
    
    sd = socket(AF_INET, SOCK_STREAM, 0);                      // If (sd==1)...
   
// Connessione al server
    printf("Tento connessione al server...\n\n");
    connect(sd,(struct sockaddr *)&server_addr,srvlen);
    getsockname(sd,&client_addr,&client_len);
    printf("Il mio port e': %d\n\n",htons(client_addr.sin_port));
    
    printf("Inserire la stringa da inviare: ");
    gets(str);
    
// Invio della stringa carattere per carattere
    printf("\n\nInvio della stringa carattere per carattere...\n\n");
    send(sd,&TERM,1,0);
    i=0;
    do
    {
        n = send(sd,&str[i],1,0);                                   // If (n<0)...
        i++;
    }
    while(str[i-1]!='\0');
    send(sd,&TERM,1,0);
    
// Invio della stringa tutta in una volta
    printf("\n\nInvio della stringa tutta in una volta...\n\n");
    n = send(sd,&str[i],strlen(str),0);                                   // If (n<0)...
   
// Ricezione lunghezza stringa
    n = recv (sd,&strLUNG[0],3,0);
    printf("Ricezione lunghezza stringa inviata carattere per carattere -> %s\n\n",strLUNG);          // If (n<0)...
    strLUNG[0]=''; strLUNG[1]=''; strLUNG[2]='';
    n = recv (sd,&strLUNG[0],3,0);
    printf("Ricezione lunghezza stringa inviata tutta in una volta -> %s\n\n",strLUNG);          // If (n<0)...

    printf("Chiudo la connessione e termino...\n\n");
    
    close (sd);
}
