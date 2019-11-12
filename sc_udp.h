#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int udp_init(char* ip_local, char* port_local);
int udp_send(int sock,char* buf, int len);
int udp_recv(int sock,char* buf, int len);


int sock;
struct sockaddr_in addr_target;
struct sockaddr_in addr_local;
