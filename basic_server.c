#include "pipe_networking.h"

int main() {
  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );

  printf("Waiting for client...\n");
  
  int rec;
  read(from_client, & rec, sizeof(rec));
  printf("Recieved: %d\n", rec);

  int out = 10;
  write(to_client, &out, sizeof(out));
  printf("Sent: %d\n", out);  
}
