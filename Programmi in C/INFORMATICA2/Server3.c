/* ESE 3 Server
Programma Client che invia ad un programma Server una stringa (sia carattere per carattere che tutta in una volta). Il Server
riceve la stringa, la visualizza e trasmette al Client la lunghezza della stessa.

NON CORRETTO PER BENE
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define PORT 4000
#define SRV_IP "127.0.0.1"
#define MaxCar 20

int main()
{
    int sd,new_sd;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int client_len = sizeof(client_addr);
    char stringaRIC[MaxCar+1],stringaRIC2[MaxCar+1];
    int n,i;
    int lungSTR;
    char res[3];
    
// Address initialization
   server_addr.sin_family = AF_INET;
   server_addr.sin_port = htons((u_short)PORT);
   server_addr.sin_addr.s_addr = inet_addr(SRV_IP);
   
   sd = socket(AF_INET, SOCK_STREAM, 0);                      // If (sd==-1)...
   
// Attesa di connessione e connessione
   printf("Mi pongo in attesa di connessione\n");
   printf("sul mio port: %d\n\n",ntohs(server_addr.sin_port));
   new_sd = accept(sd,(struct sockaddr *)&client_addr,client_len);     // If (new_sd<0)...
   printf("Ho accettato una connessione dal client con port: %d\n\n",htons(client_addr.sin_port));
   
// Ricezione della stringa carattere per carattere
   printf("Ricezione della stringa carattere per carattere...\n\n");
   recv(sd,&TERM,1,0);
   i=0;
   do
   {
       n = recv(sd,&stringaRIC[i],1,0);                                   // If (n<0)...
       i++;
   }
   while(str[i-1]!=TERM);
   str[i-1]!='\0';
   printf("Stringa ricevuta carattere per carattere: %s\n\n",stringaRIC);

// Ricezione della stringa tutta in una volta
   printf("Ricezione della stringa tutta in una volta...\n\n");
   i=0;
   do
   {
       n = recv(sd,&stringaRIC2[i],MaxCar-i,0);
       i = i + n;
   }while ((stringaRIC2[i-1]!=TERM)&&(i<MaxCar));
   str[i-1]!='\0';
   printf("Stringa ricevuta tutta in una volta: %s\n\n",stringaRIC2);
   
//Invio della lunghezza della stringa
   lungSTR = strlen(strignaRIC);
   sprintf(res,"%d",lungSTR);
   n = send (sd,&res,strlen(res),0);                                   // If (n<0)...
   printf("Invio lunghezza stringa ricevuta carattere per carattere -> %d...\n\n",lungSTR);

   lungSTR = strlen(strignaRIC2);
   res[0]=''; res[1]=''; res[2]='';
   sprintf(res,"%d",lungSTR);
   n = send (sd,&res,strlen(res),0);                                   // If (n<0)...
   printf("Invio lunghezza stringa inviata tutta in una volta -> %d...\n\n",lungSTR);

   printf("Chiudo la connessione e termino...\n\n");
   
   close(sd);
   close(new_sd);
}
