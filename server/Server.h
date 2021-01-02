#ifndef SERVER_H
#define SERVER_H

#include <microhttpd.h>

namespace server {

class Server {
public:
  Server(int port);
  ~Server() {}
  void start();

private:
  int port_;

  // This is the required signature for microhttpd handlers.
  // See: https://www.gnu.org/software/libmicrohttpd/
  static enum MHD_Result _handle(void *cls, struct MHD_Connection *connection,
                     const char *url, const char *method, const char *version,
                     const char *upload_data, size_t *upload_data_size,
                     void **con_cls);
};

} // namespace server

#endif
