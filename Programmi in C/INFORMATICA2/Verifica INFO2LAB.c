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
       
       do
       {
          printf("Mi pongo in attesa di connessione sul mio port: %d\n\n",ntohs(STUD.sin_port));
          CNL_RX = accept(sd,(struct sockaddr *)&VRF_addr,&VRF_len);
          
          CNL = CNL_RX;
          
          if (CNL_RX<0)
          {
              contErr++;
              close(CNL_RX);
          }
       }while(CNL<0);
       
       printf("==> Connessione attiva\n");
       
       // Invio del numero degli errori
       printf("Invio a VRF il numero degli errori... ");
       sprintf(error,"%d\n",contErr);
       send(CNL,error,strlen(error),0);
       printf("Inviato.\n");
       
       // Ricezione del terminatore
       recv(CNL,&CH_TERM,1,0);
       
       // Ricezione delle sequenza di caratteri
       i=0;
       do
       {
           ricevuti=recv(CNL,&SEQ[i],1,0);
           i++;
       }
       while(SEQ[i-1]!=CH_TERM);
       SEQ[i]='\0';
       
       // Controllo se la sequenza è "quit"
       if ( (SEQ[0]=='q') && (SEQ[1]=='u') && (SEQ[2]=='i') && (SEQ[3]=='t') ) ESC=1;
    }
   
    close(CNL);
    close(sd);
}
