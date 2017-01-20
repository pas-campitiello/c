#include<stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define PORT 4000
#define SRV_IP "127.0.0.1"
#define MAXCONN 3

int main()
{
    int sd,new_sd;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int client_len = sizeof(client_addr);
    char numeroCMD[2]="3\n", comando[2], uscita[5];
    int n,i;
    
    // Address initialization
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons((u_short)PORT);
    server_addr.sin_addr.s_addr = inet_addr(SRV_IP);
   
    sd = socket(AF_INET, SOCK_STREAM, 0);
    bind(sd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(sd, MAXCONN);
   
    // Attesa di connessione e connessione
    printf("Mi pongo in attesa di connessione\n");
    printf("sul mio port: %d\n\n",ntohs(server_addr.sin_port));
    new_sd = accept(sd,(struct sockaddr *)&client_addr,&client_len);
    printf("Ho accettato una connessione dal client con port: %d\n\n",htons(client_addr.sin_port));

    // Invio della lunghezza della stringa
    send(sd,&numeroCMD,strlen(numeroCMD),0);
    
    // Invio dei comandi
    for(i=0; i<3; i++)
    {
        sprintf(comando,"%d\n",i+3);
        send(new_sd,comando,strlen(comando),0);
    }
    
    // Ricezione stringa di uscita
    n=0;
    do
    {
        recv(new_sd,&uscita[n],1,0);                                   // If (n<0)...
        n++;
    }
    while(uscita[n-1]!='\n');
    
    printf("Chiudo la connessione e termino...\n\n");
   
    close(sd);
    close(new_sd);
}
