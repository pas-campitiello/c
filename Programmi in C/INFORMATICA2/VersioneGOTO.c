// Se ce errore di conteggio mettere il contErr=0 fuori dal WHILE. Se c'è errore col socket, includere le tre righe sd=...; 
// bind(...; listen(...; nel ciclo WHILE e ad ogni chiusura del canale CNL_RX (nel ciclo) chiudere anche sd.

#include<stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define PORT 35192
#define MAXCONN 3

int main()
{
    int sd, CNL, CNL_RX, contErr, i, ESC=0, ricevuti;
    struct sockaddr_in STUD, VRF;
    int STUD_len = sizeof(STUD), VRF_len = sizeof(VRF);
    char error[3], CH_TERM, SEQ[256];
    
    // Address initialization
    STUD.sin_family = AF_INET;
    STUD.sin_port = htons((u_short)PORT);
    STUD.sin_addr.s_addr = INADDR_ANY;
   
    sd = socket(AF_INET, SOCK_STREAM, 0);
    bind(sd, (struct sockaddr *)&STUD_addr, STUD_len);
    listen(sd, MAXCONN);
   
    while(ESC!=1)
    {
       contErr=0;
       
Punto1:
       printf("Mi pongo in attesa di connessione sul mio port: %d\n\n",ntohs(STUD.sin_port));
       CNL_RX = accept(sd,(struct sockaddr *)&VRF_addr,&VRF_len);
       printf("==> Connessione attiva\n");
       
       // Invio del numero degli errori
       printf("Invio a VRF il numero degli errori... ");
       sprintf(error,"%d\n",contErr);
       send(CNL_RX,error,strlen(error),0);
       printf("Inviato.\n");
       
       // Ricezione del terminatore
       ricevuti = recv(CNL_RX,&CH_TERM,1,0);
       
       if (ricevuti<0)
       {
           contErr++;
           close(CNL_RX);
           
           goto Punto1;
       }
       
       // Ricezione delle sequenza di caratteri
       i=0;
       do
       {
           ricevuti = recv(CNL_RX,&SEQ[i],1,0);
           
           if (ricevuti<0)
           {
              contErr++;
              close(CNL_RX);
           
              goto Punto1;
           }
           
           i++;
       }
       while(SEQ[i-1]!=CH_TERM);
       SEQ[i]='\0';
       
       // Controllo se la sequenza è "quit"
       //if ( (SEQ[0]=='q') && (SEQ[1]=='u') && (SEQ[2]=='i') && (SEQ[3]=='t') ) ESC=1;
       if ( strcmp(SEQ,"quit")==0 ) ESC=1;
       
       close(CNL_RX);
    }
   
    close(sd);
}
