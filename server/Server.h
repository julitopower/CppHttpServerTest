#ifndef SERVER_H
#define SERVER_H

#include <microhttpd.h>

namespace server
{

class Server
{
 public:
  Server( int port );
  ~Server(){}
  void start();

 private:
  int _port;
  
  static int _handle (void *cls, struct MHD_Connection *connection, 
                          const char *url, 
                          const char *method, const char *version, 
                          const char *upload_data, 
		          size_t *upload_data_size, void **con_cls);
};

}


#endif
