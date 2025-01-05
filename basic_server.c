#include "pipe_networking.h"

int main() {
  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );

  printf("Waiting for client...\n");
  
  int rfile = open("/dev/urandom", O_RDONLY, 0);
  int out;
  while (1) {
    read(rfile, &out, 2);
    if (out < 0) out *= -1;
    write(to_client, &out, sizeof(out));
    printf("SENT: %d\n", out);
    sleep(1);
  }
}
