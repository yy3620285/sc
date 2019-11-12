#include "sc_udp.h"

int main(int argc,char** argv){
	char buf[]="hello world\n";
	char buf_rcv[1024];
	udp_init("192.168.18.122","8809");
	addr_target.sin_family = AF_INET;
	addr_target.sin_addr.s_addr = inet_addr("192.168.18.122");
	addr_target.sin_port = htons(atoi("8808"));
	while(1){

		int n=udp_send(sock,buf,13);
		printf("%d sent\n",n);
		sleep(1);
		n = udp_recv(sock,buf,1024);
		if( n>0){
			printf("%d\n",n);
		}

	}
}
