#include "Server.h"
#include "WireData.h"

#include <iostream>
#include <microhttpd.h>
#include <cstring>

namespace server
{


  Server::Server( int port ) : _port( port ) {}

  void Server::start()
  {
    struct MHD_Daemon * server;
    server = MHD_start_daemon( MHD_USE_SELECT_INTERNALLY,
			       _port, 0, this, this->_handle, 0,
			       MHD_OPTION_END);

    // The server only runs while we are inside this method. For
    // that reason we here try to read something from the cmd line.
    int whatever;
    std::cin >> whatever;
    MHD_stop_daemon( server );
  }

  int Server::_handle ( void *cls, struct MHD_Connection *connection, 
                          const char *url, 
                          const char *method, const char *version, 
                          const char *upload_data, 
		          size_t *upload_data_size, void **con_cls )
  {
    // See how cleaverly we are passing here the instance of the
    // Server. This is goint to allow us to actually use objects, and
    // not just static methods.
    Server * server = static_cast<Server *>( cls );
    std::cout << "Got request" << std::endl;

    WireData data(connection, url, method, version, upload_data,
                  upload_data_size);

    std::cout << data;

    struct MHD_Response * response;
    int ret;

    const char * page = "<html><body>Hi there!</body></html>";
    response = MHD_create_response_from_buffer (strlen( page  ),
					       (void *) page
					       , MHD_RESPMEM_PERSISTENT );
    
    ret = MHD_queue_response ( connection, MHD_HTTP_OK, response );
    MHD_destroy_response ( response );
    return ret;
  }

}
