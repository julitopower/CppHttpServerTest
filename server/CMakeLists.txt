# Define headers and source files
SET (HEADERS Server.h 
             WireData.h
             url/UrlMapper.h
	         url/SimpleUrlMapper.h
	         handler/RequestHandler.hpp)
SET (SRC Server.cpp
         url/SimpleUrlMapper.cpp
         handler/DefaultRequestHandler.cpp)

# Make sure boost headers can be found. We are only using
# Smart pointer, so headers are enough, no need to link
# with any boost library afterwards
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

# Define the actual library, and its dependencies.
ADD_LIBRARY (libserver ${HEADERS} ${SRC})
TARGET_LINK_LIBRARIES (libserver ${MHD_LIBRARIES})
