#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SRV_PORT 4000
#define SRV_IP "127.0.0.1"

int main()
{
   struct sockaddr_in SRV, CLI;
   int srv_len=sizeof(SRV), cli_len=sizeof(CLI),;
   char NSTR[8], CMD[32], quit[5]="quit\n", des_sock[20];
   int SD, i, numCMD, j, k, status;
   pid_t pid;
   
   // Address initialization  
   SRV.sin_family= AF_INET;
   SRV.sin_port = htons((u_short) SRV_PORT);
   SRV.sin_addr.s_addr=inet_addr(SRV_IP);
   
   SD = socket(AF_INET, SOCK_STREAM, 0);
   
   // Connessione al server
   printf("Tento connessione al server...");
   connect(SD,(struct sockaddr *)&SRV,srv_len);
   getsockname(SD,&CLI,&cli_len);
   printf(" -> Connessione attiva.\n Il mio port e': %d\n\n",htons(CLI.sin_port));
   
   // Ricezione della stringa NSTR
   i=0;
   do
   {
       recv(SD,&NSTR[i],1,0);                                   // If (n<0)...
       i++;
   }
   while(NSTR[i-1]!='\n');
   numCMD=atoi(NSTR);
   
   for(j=1; j<=numCMD; j++)
   {
       // Ricezione della stringa CMD
       k=0;
       do
       {
           recv(SD,&CMD[k],1,0);                                   // If (n<0)...
           k++;
       }
       while(CMD[k-1]!='\n');
       
       // Creazione del figlio
       pid=fork();
       if (pid==0)
       {            // FIGLIO
           itoa(sd,des_sock,10); // Converto in stringa il descrittore di socket
           printf("\nEseguo il comando del server...\n");
           printf("_%s_\n",CMD);
           execlp(CMD,CMD,des_sock,(char *)0);
           printf(" -> Comando eseguito.\n\n");
           exit(1);
       }
       else
       {            // PADRE
           waitpid(pid,&status,0)
           //printf("Figlio terminato. Eseguito il comando n° %d",j);
       }
   } // end FOR
   
   // Invio stringa di uscita e terminazione
   send(SD,&quit,strlen(quit),0);
   printf("\n\nInvio della stringa QUIT.\n\n Terminazione padre.");
   
   close(SD);
}
