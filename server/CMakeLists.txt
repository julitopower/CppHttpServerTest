SET (HEADERS Server.h)

SET (SRC Server.cpp)

ADD_LIBRARY (libserver ${HEADERS} ${SRC})
TARGET_LINK_LIBRARIES (libserver ${MHD_LIBRARIES})