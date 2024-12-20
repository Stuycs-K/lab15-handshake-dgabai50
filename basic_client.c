#include "pipe_networking.h"

int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

  sleep(3);

  int out = 15;
  write(from_server, &out, sizeof(out));
  printf("Sent: %d\n", out);

  int rec;
  read(from_server, &rec, sizeof(rec));
  printf("Recieved: %d\n", rec);
}
