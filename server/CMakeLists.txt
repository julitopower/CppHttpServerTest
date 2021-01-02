set(HEADERS Server.h)

set(SRC Server.cpp)

add_library(libserver ${HEADERS} ${SRC})
target_link_libraries(libserver ${MHD_LIBRARIES})
