#include "sc_udp.h"
#include <arpa/inet.h>
int main(int argc,char** argv){
	char buf[1024];
	char* addr;
	udp_init("192.168.18.122","8808");

	while(1){
		sleep(1);
		int n;
		if (0< (n =udp_recv(sock,buf,1024))){
			//printf("%s\n",inet_ntoa(*(struct in_addr *) & addr_target.sin_addr.s_addr));
			if(addr_target.sin_addr.s_addr >0 ){
				//printf("%s\n",inet_ntoa(*(struct in_addr *) & addr_target.sin_addr.s_addr));



			}
			printf("%d received\n",n);
			udp_send(sock,buf,13);
		}
	}

	return 0;
}
