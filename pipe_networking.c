#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client

  Performs the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {
	mkfifo("wkp",0666);
	printf("made wkp");
	int fd = open("wkp", O_RDONLY);
	printf("opened wkp\n");
	char * client;
	read(fd,client,30);
	printf("read %s\n", client);
	return 0;
}


/*=========================
  client_handshake
  args: int * to_server

  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
	mkfifo("private",0666);
	int fd = open("wkp", O_WRONLY);
	char * s = "private";
	write(fd, s, strlen(s));
	return 0;
}
