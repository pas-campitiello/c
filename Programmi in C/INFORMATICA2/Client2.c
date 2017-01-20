/* ESE 2  Client2 (che riceve l'IP del server da tastiera come parametro al momento del lancio del programma)
Semplice programma di trasmissione di un carattere ed echo nel senso Server -> Client e Client -> Server. 

Uguale all'ESE1 ma con senso di trasmissione invertito.

NON CORRETTO PER BENE
*/


#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define SRV_PORT 4000

int main(int argc, char *argv[])
{
    int sd;
    struct sockaddr_in server_addr;
    int srvlen = sizeof(server_addr);
    struct sockaddr_in client_addr;
    int client_len = sizeof(client_addr);
    char car;
    int n;
    
// Address initialization
   server_addr.sin_family = AF_INET;
   server_addr.sin_port = htons((u_short)SVR_PORT);
   server_addr.sin_addr.s_addr = inet_addr(argv[1]);
   
   sd = socket(AF_INET, SOCK_STREAM, 0);                      // If (sd==1)...
   
// Connessione al server
   printf("Tento connessione al server...");
   connect(sd,(struct sockaddr *)&server_addr,srvlen);
   getsockname(sd,&client_addr,&client_len);
   printf("Connessione attivata. Il mio port e': %d\n\n",htons(client_addr.sin_port));
   
// Ricezione carattere
   n = recv (sd,&car,1,0);                                    // If (n<0)...
   printf("Ho ricevuto il car carattere %c dal Server\n\n",car);
   
// Echo carattere
   n = send (sd,&car,1,0);                                    // If (n<0)...
   printf("Carattere rispedito al Server\n\n");
   
   printf("Chiudo la connessione e termino...");
   
   close (sd);
}
