#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <winsock.h>
#include <locale.h>

WSADATA data;
SOCKET winsock;
SOCKADDR_IN sock;


int main(){
	setlocale(LC_ALL,"");
	char messageClient[1024];
	char messageServer[1024];
	char nameClient[50];
	char nameServer[50];
	int bytes;
	

    printf("\nDigite seu nome: ");
    gets(nameServer);
    if(WSAStartup(MAKEWORD(1,1),&data) == SOCKET_ERROR){ 
         printf("\nErro ao inicializar o winsock");
         system("pause");
         return 0;
    }
    if((winsock = socket(AF_INET,SOCK_STREAM,0)) == SOCKET_ERROR){
         printf("\nErro ao criar socket");
         system("pause");
         return 0;
    }
    sock.sin_family = AF_INET;
    sock.sin_port = htons(1234);
    if(bind(winsock,(SOCKADDR*)&sock,sizeof(sock)) == SOCKET_ERROR){
         printf("\nErro ao utilizar a funcao BIND");
         system("pause");
         return 0;
    }
    listen(winsock,1);
    while((winsock = accept(winsock,0,0)) == SOCKET_ERROR){
         Sleep(1);
    }
    printf("\nCliente conectado \n\n");
    send(winsock,nameServer,strlen(nameServer),0);
    recv(winsock,nameClient,50,0);
    while(1){
         Sleep(1);
         memset(messageClient,0,1024);
         bytes = recv(winsock,messageClient,1024,0);
         if(bytes == -1){
              printf("\nconexao perdida");
              getch();
              system("pause");
              return 0;
         }
         printf("%s:", nameClient);
         printf(messageClient);
         printf("%s: ", nameServer);
         gets(messageServer);
         strcat(messageServer,"\r\n");
         send(winsock,messageServer,strlen(messageServer),0);
    }
    getch();
    closesocket(winsock);
    WSACleanup();
    system("pause");
    return 0;
}
