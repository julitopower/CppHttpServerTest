#ifndef SIMPLE_URL_MAPPER_H
#define SIMPLE_URL_MAPPER_H

#include "UrlMapper.h"

#include <boost/shared_ptr.hpp>
#include <string>
#include <map>



namespace server {
  namespace url {

typedef boost::shared_ptr<server::handler::RequestHandler> RequestHandlerPtr;
typedef std::map<std::string, RequestHandlerPtr > Mappings;
typedef Mappings::const_iterator MappingsIterator;

/**
 * Mappings holder backed by a map. No regex/patter implemented. Every URL
 * maps directly to a handler.
 */
class SimpleUrlMapper : public UrlMapper
{
public:
  /**
   * Default constructor
   */
  SimpleUrlMapper();

  /**
   * Destructor
   */
  virtual ~SimpleUrlMapper();

  /**
   * Adds a mapping to the mappings table.
   * 
   * @param url The url for which a RequestHandler is going to be defined.
   * @param handler A pointer to the RequestHandler that is going to be
   *   associated with the Url.
   * @return true if the insertion succedes, false otherwise.
   */
  virtual bool addMapping(const std::string& url,
			  server::handler::RequestHandler * handler);

  /**
   * Retrieves the RequestHandler for a given Url.
   *
   * @param url The Url for which a RequestHandler is requested.
   * @return a pointer to a RequestHandler, or null of none is found.
   */
  virtual server::handler::RequestHandler * 
          getHandler(const std::string & url) const;
private:
  Mappings _mappings;
};

  }
}

#endif // SIMPLE_URL_MAPPER_H
