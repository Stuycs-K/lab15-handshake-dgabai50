#include "pipe_networking.h"
#include <signal.h>

static void sighandler(int signo) {
    if (signo = SIGINT) {
        remove(WKP);
        printf("Server Closed\n");
        exit(0);
    }
}

int main() {
  signal(SIGPIPE, SIG_IGN);
  signal(SIGINT, sighandler);
  int to_client;
  int from_client;

  printf("Waiting for client...\n");
  from_client = server_handshake( &to_client );
  
  int rfile = open("/dev/urandom", O_RDONLY, 0);
  int out;
  while (1) {
    read(rfile, &out, 2);
    if (out < 0) out *= -1;
    
    if (write(to_client, &out, sizeof(out)) == -1) {
      close(to_client);
      close(from_client);
      printf("Waiting for client...\n");
      from_client = server_handshake( &to_client );
    }

    printf("SENT: %d\n", out);
    sleep(1);
  }
}
