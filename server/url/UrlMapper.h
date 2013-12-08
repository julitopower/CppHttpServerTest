#ifndef URL_MAPPER_H
#define URL_MAPPER_H

#include <string>

#include "../handler/RequestHandler.hpp"

namespace server {
  namespace url {

class UrlMapper
{
 public:
  virtual bool addMapping(const std::string & url,
			  server::handler::RequestHandler * handler) = 0;

  virtual server::handler::RequestHandler * 
          getHandler(const std::string & url) const = 0;

};

  } // server 
}   // url
#endif //URL_MAPPER_H
