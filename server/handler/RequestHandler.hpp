#ifndef REQUEST_HANDLER_H
#define REQUEST_HANDER_H

namespace server {
  namespace handler {

class RequestHandler
{
  virtual void handle() = 0;
};


  }
}
#endif // REQUEST_HANDLER_H
