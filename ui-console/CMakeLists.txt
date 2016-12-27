######### CMake Version #####################
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
#############################################
set( CMAKE_DISABLE_SOURCE_CHANGES  ON )
set( CMAKE_DISABLE_IN_SOURCE_BUILD ON )
#############################################

######### Project Name ######################
project( UserInterface )
#############################################

######### Where to search for library headers
include_directories( ${PROJECT_SOURCE_DIR}/include
                     ${CMAKE_SOURCE_DIR}/core/include )

######### Files #############################
set(HEADER_FILES
    # include/MainWindow.hpp
)
source_group( "include" FILES ${HEADER_FILES} )

set(SOURCE_FILES
    src/main.cpp
    # src/MainWindow.cpp
)
source_group( "src" FILES ${SOURCE_FILES} )
#############################################



add_executable( UserInterface
                ${HEADER_FILES}
                ${SOURCE_FILES} )



######### Link the libraries into the executable
target_link_libraries( UserInterface intersimcore )
### OSX and Unix need libdl
if( APPLE )
    target_link_libraries( UserInterface dl )
elseif( UNIX )
    target_link_libraries( UserInterface dl )
elseif( WIN32 )
endif()
#############################################