/* DA PROVARE SOTTO LINUX

(I NOMI DELLE VARIABILI INDICATI NELLA TRACCIA SONO INDICATIVI. NEL CODICE NE VENGONO UTILIZZATI ALTRI.)

Programma eseguito da un processo padre server SRV e da due processi server SRV_X (1 e 2). Ciascun processo SRV_X gestisce un 
canale CNL_X tra se stesso e un client di verifica CLI_X. Allegato il file "term.txt".
1) SRV è un server studente e deve servire in parallelo due richieste di servizio da parte di due client di verifica diversi CLI_X.
2) SRV si pone in attesa di collegamento da parte dei processi CLI_X sulla porta PORT.
3) Per una generica richiesta di connessione X, SRV_X utilizza il canale CNL_X aperto con CLI_X per eseguire:
   1) SRV_X entra in ciclo e svolge le seguenti operazioni:
      1) Riceve da CLI_X, sul canale CNL_X, una sequenza di caratteri terminata da '\n' e di lunghezza massima 5. Tale sequenza
         convertita in numero (con ATOI) rappresenta un indice IDX.
      2) Apre il file "term.txt", legge il carattere alla posizione IDX e lo memorizza, quindi chiude il file. Il carattere letto
         indicato come CH_TERM è il terminatore dei messaggi successivi.
      3) Riceve da CLI_X, sul canale CNL_X, una sequenza di caratteri CH_SEQ (di lunghezza massima 64) il cui ultimo carattere è
         il terminatore CH_TERM.
      4) Conta il numero di caratteri della sequenza CH_SEQ compreso il terminatore CH_TERM.
      5) Invia a CLI_X, sullo stesso canale CNL_X, il numero di caratteri ricevuti (compreso il CH_TERM). Vedi utilizzo SPRINTF.
   2) Il ciclo termina quando SRV_X legge dal file un carattere terminatore CH_TERM uguale a 'q'.
   3) Il processo SRV_X chiude il canale di rete CNL_X e termina.
   4) Il processo SRV non attende il termine dei servizi ma chiude il canale usato e termina.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 4000
#define MAXCONN 2

int main(int argc, char * argv[])
{
   int sd, new_sd, client_len, n_figli, i, tot, pid;
   char stringa[5], term, stringa1[64], num[4];
   FILE *fp;

   struct sockaddr_in server, client;
      
   n_figli=0;
   
   server.sin_family= AF_INET;
   server.sin_port = htons((u_short) PORT);
   server.sin_addr.s_addr=INADDR_ANY;
   
   client_len=sizeof(client);

   sd = socket(AF_INET, SOCK_STREAM, 0);
   bind(sd, (struct sockaddr *)&server, sizeof(server));
   listen(sd, MAXCONN);

   while(1)
   {
      printf("Mi pongo in attesa di richieste di connessione\n");
      printf("sul mio port: %d\n", ntohs(server.sin_port));
 
      new_sd = accept(sd, (struct sockaddr *)&client, &client_len);

      printf("\n\nHo accettato una connessione\n");
      printf("dal client con port: %d\n\n",ntohs(client.sin_port));

      if (new_sd==-1) printf("ERRORE DI CONNESSIONE");
      else
      {
         pid = fork();
         n_figli++;
         
         if (!pid)            //FIGLIO
         {
            printf("\nFIGLIO -> n_figli %d\n\n",n_figli);
              
            while(1)
            {
               i=0;
               do
               {
                  recv(new_sd, &stringa[i], 1, 0);
                  i++;
               }
               while(stringa[i-1]!='\n');
               
               stringa[i-1]='\n';
               
               tot = atoi(stringa);
               printf("La stringa corvertita e': %d\n",tot);
               
               fp = fopen("term.txt","r");
               
               if (fp == NULL) printf("ERRORE APERTURA FILE");
               
               for(i=0; i<=tot; i++) fscanf(fp, "%c", &term);
               
               fclose(fp);
               
               if (term=='q')
               {
                  close(new_sd);
                  exit(1);             // Termina figlio
               }
               
               i=0;
               do
               {
                  recv(new_sd, &stringa1[i], 1, 0);
                  i++;
               }
               while(stringa1[i-1]!=term);
               
               stringa1[i-1]=term;

               sprintf(num, "%d\n", i);

               send(new_sd, num, strlen(num), 0);
            } // end WHILE(1)  
         }    // end IF
         else              // PADRE
         {
            printf("\nPADRE -> n_figli %d\n\n",n_figli);
            
            if (n_figli==2)
            { 
               close(sd);
               exit(0);
            }
         }     //end ELSE
      }        // end ELSE
   }           // end WHILE(1)
}              // end MAIN
