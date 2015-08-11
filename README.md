# trabalhoRedes
Trabalho de redes I socket em C

Bibliotecas:

#include <winsock.h>

Estruturas:

WSADATA: A estrutura de WSADATA é usada para informações de inicialização de soquetes do Windows.
SOCKADDR_IN sock: Estrutura responsavel pelos dados do host

Funções:
send(winsock,nameClient,strlen(nameClient),0): Envia os dados para o destinatário, tendo como parâmetro a estrutura do socket o conteúdo, tamanho e o numero do protocolo.
recv(winsock,nameServer,50,0): Recebe os dados do destinatário, tendo como parâmetro a estrutura do socket , variável que vai receber, tamanho e o numero do protocolo.
WSAStartup(MAKEWORD(1,1),&data): responsavel por fazer o windows iniciar a dll e ocx responsável por comunicação na internet

Cliente:
connect(winsock,(SOCKADDR*)&sock,sizeof(sock)): responsável pela conexão de seu socket cliente, com um servidor.
socket(AF_INET,SOCKET_STREAM,0)): inicializa o socket recebendo como parametro o nome do protocol e o numero.

Servidor:
bind(winsock,(SOCKADDR*)&sock,sizeof(sock)) : função serve para associar uma porta na máquina local para um determinado socket.

accept(winsock,0,0)) : unção responsável por aceitar uma conexão em um socket

http://www-usr.inf.ufsm.br/~giovani/sockets/sockets.txt
http://www.csd.uoc.gr/~hy556/material/tutorials/cs556-3rd-tutorial.pdf
