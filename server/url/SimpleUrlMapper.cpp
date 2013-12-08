#include "SimpleUrlMapper.h"

namespace server {
  namespace url {

    SimpleUrlMapper::SimpleUrlMapper() : _mappings()
    {

    }

    SimpleUrlMapper::~SimpleUrlMapper(){}

    bool SimpleUrlMapper::addMapping(const std::string& url,
		    server::handler::RequestHandler * handler)
    {
      _mappings[url] = RequestHandlerPtr(handler);
    }

   server::handler::RequestHandler * 
   SimpleUrlMapper::getHandler(const std::string & url) const
   {
     MappingsIterator it = _mappings.find(url);     
     if(it != _mappings.end())
       return it->second.get();
     return 0;
   }

  }
}
