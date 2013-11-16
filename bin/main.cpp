#include <iostream>
#include "../server/Server.h"

int main(int argc, char** argv)
{
  server::Server server( 8080 );
  server.start();
  std::cout << "This is just a test" << std::endl;
}
