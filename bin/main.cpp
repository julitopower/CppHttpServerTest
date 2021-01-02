#include "Server.h"
#include <iostream>

int main(int argc, char **argv) {
  const auto port = 8080;
  server::Server server(port);
  std::cout << "Starting server in port " << port << std::endl;  
  server.start();
}
