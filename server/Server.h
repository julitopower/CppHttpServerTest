#ifndef SERVER_H
#define SERVER_H

#include <microhttpd.h>
#include <boost/scoped_ptr.hpp>

#include "url/UrlMapper.h"

namespace server
{

/**
 * Encapsulates a HTTP server
 */
class Server
{
 public:

  /**
   * Creates a Server that will listen for request in the specified port number.
   *
   * @param port The port number the Server will lister in.
   */
  Server( int port );

  /**
   * Destructor
   */
  ~Server(){}

  /**
   * Start the server. After this call the server is ready to receive requests
   */
  void start();

 private:
  int _port;
  
  /*
   * This method is the callback used whenever a new request is received
   */
  static int _handle (void *cls, struct MHD_Connection *connection, 
                          const char *url, 
                          const char *method, const char *version, 
                          const char *upload_data, 
		          size_t *upload_data_size, void **con_cls);
};

}

#endif
