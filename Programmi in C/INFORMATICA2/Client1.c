/* ESE 1 Client1
Semplice programma di trasmissione di un carattere ed echo nel senso Client -> Server e Server -> Client. Una volta avviato il
Server si mette in ascolto di richieste di connessione. Il Client chiede la connessione al Server e, una volta stabilita, invia un
carattere predefinito al Server. Questi notifica la ricezione del carattere e lo rispedisce al Client, per poi chiudere la
connessione e terminare. Il Client notifica l'echo del carattere spedito, chiude la connessione e termina.
*/


#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define SRV_PORT 4000
#define SRV_IP "127.0.0.1"

int main()
{
    int sd;
    struct sockaddr_in server_addr;
    int srvlen = sizeof(server_addr);
    struct sockaddr_in client_addr;
    int client_len = sizeof(client_addr);
    char carcli = 'P';
    int n;
    
// Address initialization
   server_addr.sin_family = AF_INET;
   server_addr.sin_port = htons((u_short)SVR_PORT);
   server_addr.sin_addr.s_addr = inet_addr(SRV_IP);
   
   sd = socket(AF_INET, SOCK_STREAM, 0);                      // If (sd==1)...
   
// Connessione al server
   printf("Tento connessione al server...");
   connect(sd,(struct sockaddr *)&server_addr,srvlen);
   getsockname(sd,&client_addr,&client_len);
   printf("Il mio port e': %d\n\n",htons(client_addr.sin_port));
   
// Invio carattere
   printf("Invio carattere...\n\n");
   n = send (sd,&carcli,1,0);                                   // If (n<0)...
   
// Ricezione carattere
   n = recv (sd,&carcli,1,0);                                   // If (n<0)...
   printf("Ricezione echo carattere %c dal server\n\n",carcli);
   
   printf("Chiudo la connessione e termino...");
   
   close (sd);
}
