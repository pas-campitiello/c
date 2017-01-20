/* ESE 2  Server2
Semplice programma di trasmissione di un carattere ed echo nel senso Server -> Client e Client -> Server. 

Uguale all'ESE1 ma con senso di trasmissione invertito.

NON CORRETTO PER BENE
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define PORT 4000
//#define SRV_IP "127.0.0.1"

int main()
{
    int sd,new_sd;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int client_len = sizeof(client_addr);
    char carSRV='P';
    int n;
    
// Address initialization
   server_addr.sin_family = AF_INET;
   server_addr.sin_port = htons((u_short)PORT);
   server_addr.sin_addr.s_addr = INADDR_ANY;
//   server_addr.sin_addr.s_addr. = inet_addr(SRV_IP);
   
   sd = socket(AF_INET, SOCK_STREAM, 0);                      // If (sd==-1)...
   
// Attesa di connessione e connessione
   printf("Mi pongo in attesa di connessione\n");
   printf("sul mio port: %d",ntohs(server_addr.sin_port));
   new_sd = accept(sd,(struct sockaddr *)&client_addr,client_len);     // If (new_sd<0)...
   printf("Ho accettato connessione dal client con port: %d\n\n",htons(client_addr.sin_port));
   
// Invio carattere
   printf("Invio carattere...");
   n = send (new_sd,&carSRV,1,0);                                   // If (n<0)...
   
// Ricezione carattere
   n = recv (sd,&carSRV,1,0);                                   // If (n<0)...
   printf("Ricezione echo del carattere %c dal Client",car);
   
   printf("Chiudo la connessione e termino...");
   
   close(sd);
   close(new_sd);
}
