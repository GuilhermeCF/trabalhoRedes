#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
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
    gets(nameClient);
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
    sock.sin_addr.s_addr = inet_addr("127.0.0.1");
    if(connect(winsock,(SOCKADDR*)&sock,sizeof(sock)) == SOCKET_ERROR){
         printf("\nErro ao se conectar");
         system("pause");
		 return 0;
	}
	printf("\nConectado");
	send(winsock,nameClient,strlen(nameClient),0);
	recv(winsock,nameServer,50,0);
	while(1){
	     Sleep(1);
	     printf("%s:",nameClient);
	     gets(messageClient);
	     strcat(messageClient,"\r\n");
	     send(winsock,messageClient,strlen(messageClient),0);
	     memset(messageServer,0,1024);
	     bytes = recv(winsock,messageServer,1024,0);
	     if(bytes == -1){
	          printf("\nconexao perdida");
	          getch();
	          system("pause");
	          return 0;
		 }
		 printf("%s: ",nameServer);
		 printf(messageServer);
	}
	getch();
	closesocket(winsock);
	WSACleanup();
	system("pause");
	return 0;
}
	
	
	
