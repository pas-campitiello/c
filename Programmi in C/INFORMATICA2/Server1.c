/* ESE 1  Server1
Semplice programma di trasmissione di un carattere ed echo nel senso Client -> Server e Server -> Client. Una volta avviato il
Server si mette in ascolto di richieste di connessione. Il Client chiede la connessione al Server e, una volta stabilita, invia un
carattere predefinito al Server. Questi notifica la ricezione del carattere e lo rispedisce al Client, per poi chiudere la
connessione e terminare. Il Client notifica l'echo del carattere spedito, chiude la connessione e termina.
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define PORT 4000
#define SRV_IP "127.0.0.1"

int main()
{
    int sd,new_sd;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int client_len = sizeof(client_addr);
    char car;
    int n;
    
// Address initialization
   server_addr.sin_family = AF_INET;
   server_addr.sin_port = htons((u_short)PORT);
   server_addr.sin_addr.s_addr = inet_addr(SRV_IP);
   
   sd = socket(AF_INET, SOCK_STREAM, 0);                      // If (sd==-1)...
   
// Attesa di connessione e connessione
   printf("Mi pongo in attesa di connessione\n");
   printf("sul mio port: %d",ntohs(server_addr.sin_port));
   new_sd = accept(sd,(struct sockaddr *)&client_addr,client_len);     // If (new_sd<0)...
   printf("Ho accettato connessione dal client con port: %d\n\n",htons(client_addr.sin_port));
   
// Ricezione carattere
   n = recv (new_sd,&car,1,0);                                    // If (n<0)...
   printf("Ho ricevuto il car carattere %c dal client\n\n",car);
   
// Echo carattere
   n = send (new_sd,&car,1,0);                                    // If (n<0)...
   printf("Carattere rispedito al client\n\n");
   
   printf("Chiudo la connessione e termino...");
   
   close(sd);
   close(new_sd);
}
