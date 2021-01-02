#include "Server.h"

#include <cstring>
#include <iostream>
#include <microhttpd.h>

namespace server {

Server::Server(int port) : port_(port) {}

void Server::start() {
  struct MHD_Daemon *server;
  // https://www.gnu.org/software/libmicrohttpd/manual/libmicrohttpd.html#microhttpd_002dinit
  server = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, port_, 0, this,
                            this->_handle, 0, MHD_OPTION_END);
  // TODO: Remove. This is here to block so that the server can run for a while
  std::string str;
  std::cin >> str;
  MHD_stop_daemon(server);
}

enum MHD_Result Server::_handle(void *cls, struct MHD_Connection *connection,
                    const char *url, const char *method, const char *version,
                    const char *upload_data, size_t *upload_data_size,
                    void **con_cls) {
  // At registration time we set cls to be the server class
  // Commented to serve as documentation
  // Server *server = static_cast<Server *>(cls);

  // For the moment we return a fixed webpage
  const char *page = "<html><body>Hi there!</body></html>";
  struct MHD_Response* response = MHD_create_response_from_buffer(strlen(page),
                                             (void*)page,
                                             MHD_RESPMEM_PERSISTENT);
  const int ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
  MHD_destroy_response(response);
  return static_cast<enum MHD_Result>(ret);
}

} // namespace server
