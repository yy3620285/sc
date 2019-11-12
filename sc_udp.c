#include "sc_udp.h"

int udp_init(char* ip_local, char* port_local){
	if((sock = socket(AF_INET, SOCK_DGRAM,IPPROTO_UDP)) < 0){
		return -1;
	}
	addr_local.sin_family = AF_INET;
	addr_local.sin_addr.s_addr = inet_addr(ip_local);
	addr_local.sin_port = htons(atoi(port_local));

	if(-1 == (bind(sock, (struct sockaddr*)&addr_local, sizeof(addr_local)))){
		return -1;
	}
	if (fcntl(sock, F_SETFL, O_NONBLOCK | O_ASYNC) < 0){
		return -1;
	}


	return 0;
}

int udp_send(int sock,char* buf, int len){
	int n;
	n = sendto(sock, buf, len, 0 , (struct sockaddr*)&addr_target, sizeof(addr_target));
	if(n>0){
		return n;
	}else{
		return 0;
	}
}
int udp_recv(int sock,char* buf, int len){
	int n;
	int tar_len;
	//struct sockaddr_in addr;
	n = recvfrom(sock, buf, len,0,(struct sockaddr*)&addr_target, &tar_len );
	if(n>0){
		return n;
	}else{
		return 0;
	}
}
