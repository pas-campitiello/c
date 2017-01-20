/* DA PROVARE SOTTO LINUX

(I NOMI DELLE VARIABILI INDICATI NELLA TRACCIA SONO INDICATIVI. NEL CODICE NE VENGONO UTILIZZATI ALTRI.)

Programma eseguito da un processo server SRV e da due processi server SRV_X (1 e 2). Ciascun processo SRV_X gestisce un canale
CNL_X tra se stesso e un client di verifica CLI_X.
1) SRV è un server studente e deve servire in parallelo due richieste di servizio da parte di due client di verifica diversi CLI_X.
2) SRV si pone in attesa di collegamento da parte dei processi CLI_X sulla porta PORT1.
3) Per una generica richiesta di connessione X, SRV_X apre il canale di rete CNL_X con CLI_X per eseguire i seguenti passi:
   1) SRV_X entra in ciclo e svolge le seguenti operazioni:
      1) Riceve da CLI_X, sul canale CNL_X, un carattere "terminatore" CH_TERM.
      2) Riceve da CLI_X, sul canale CNL_X, una sequenza di caratteri CH_SEQ (di lunghezza massima 64) il cui ultimo carattere è
         il "terminatore" CH_TERM, precedentemente ricevuto.
      3) Conta il numero di caratteri della sequenza CH_SEQ compreso il terminatore CH_TERM.
      4) Invia a CLI_X, sullo stesso canale CNL_X, il numero di caratteri ricevuti (compreso il CH_TERM). Vedi utilizzo SPRINTF. 
   2) Il ciclo termina quando SRV_X riceve da CLI_X un carattere terminatore CH_TERM uguale a 'q'. Il carattere 'q' NON è seguito
      da una sequenza di caratteri da elaborare.
   3) Il processo SRV_X chiude il canale di rete CNL_X e termina.
   4) Il processo SRV deve attende il termine di entrambi i servizi SRV_X, dopodichè deve connettersi su una seconda porta PORT2
      con un server di verifica S_END che risponde all'indirizzo 131.175.75.9. Sul canale aperto CNL_END, SRV deve spedire il
      carattere 'q'.
   5) Il processo SRV attende un carattere di risposta CH_RISP che verrà trasmesso sullo stesso canale CNL_END da S_END.
   6) Il processo SRV chiude i canali utilizzati e termina.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT1 35583
#define PORT2 35587
#define SRV_IP "131.175.75.9"
#define MAXCONN 2

int main(int argc, char * argv[])
{
   int sd, new_sd, client_len, n_figli, i, pid, CNL_END, status;
   char num[4], CH_TERM, CH_SEQ[64], CH_RISP;
   struct sockaddr_in server, S_END, client, CLI_END;
   pid_t figlio_terminato;
      
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
      // Attesa di connessione
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
         
         if (!pid)            
         {//---------------------------------------------------- FIGLIO
            printf("\nFIGLIO -> n_figli %d\n\n",n_figli);
              
            while(1)
            {  
               // Riceve il terminatore CH_TERM
               recv(new_sd, &CH_TERM[i], 1, 0);            
               
               // Controlla se uscire
               if (term=='q')
               {
                  close(new_sd);
                  // Termina figlio
                  exit(1);
               }
               
               // Riceve la stringa CH_SEQ
               i=0;
               do
               {
                  recv(new_sd, &CH_SEQ[i], 1, 0);
                  i++;
               }
               while(stringa[i-1]!=CH_TERM);
               
               stringa[i-1]=CH_TERM;
               
               sprintf(num, "%d\n", i);
               
               // Invio al client il numero di caratteri ricevuti
               send(new_sd, num, strlen(num), 0);
               
            } // end WHILE(1)  
         }    // end IF (figlio)
         else
         {//---------------------------------------------------- PADRE
            printf("\nPADRE -> n_figli %d\n\n",n_figli);
            
            figlio_terminato = waitpid(pid, &status, 1);
            printf("E’ terminato il processo figlio %d con esito %d\n\n",figlio_terminato, status);
            
            // Address initialization
            S_END.sin_family = AF_INET;
            S_END.sin_port = htons((u_short)SVR_PORT);
            S_END.sin_addr.s_addr = inet_addr(SRV_IP);     // oppure ...inet_addr("131.175.75.9");
   
            CNL_END = socket(AF_INET, SOCK_STREAM, 0);     // If (CNL_END==1)...
   
           // Connessione al server
           printf("Tento connessione al server_END...\n");
           connect(CNL_END,(struct sockaddr *)&S_END, sizeof(S_END));
           getsockname(CNL_END, &CLI_END, sizeof(CLI_END));
           printf("Il mio port e': %d\n\n",htons(CLI_END.sin_port));
   
           // Invio carattere
           printf("Invio carattere...\n\n");
           n = send (CNL_END,"q",1,0);                        // If (n<0)...
    
           // Ricezione carattere
           n = recv (CNL_END,&CH_RISP,1,0);                        // If (n<0)...
           printf("Ricevuto il carattere di risposta %c dal server_END\n\n",CH_RISP);
   
           printf("Chiudo la connessione e termino...");
   
           close (CNL_END);
           close (sd);
           exit(0);
         }     //end ELSE (padre)
      }        // end ELSE (nessun errore di connessione)
   }           // end WHILE(1) (attesa di connessione)
}              // end MAIN
