#ifndef DEFAULTREQUESTHANDLER_H
#define DEFAULTREQUESTHANDLER_H

#include "RequestHandler.hpp"

namespace server {
namespace handler {


class DefaultRequestHandler : RequestHandler
{
public:
    DefaultRequestHandler();

    virtual void handle();
};


}
}

#endif // DEFAULTREQUESTHANDLER_H
