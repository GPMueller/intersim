######### CMake Version #####################
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
#############################################
set( CMAKE_DISABLE_SOURCE_CHANGES  ON )
set( CMAKE_DISABLE_IN_SOURCE_BUILD ON )
### Let CMake run moc on QT ui files automatically
set( CMAKE_AUTOMOC ON )
### Let CMake collect QT Resources automatically
set( CMAKE_AUTORCC ON )
### Let CMake handle .ui files automatically
# set(CMAKE_AUTOUIC ON) # unfortunately, for this, .ui files ned to be next to corresponding .cpp files
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
target_link_libraries( ${EXECUTABLE_NAME} intersimcore Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Charts Qt5::OpenGL )
### OSX and Unix need libdl
if( APPLE )
    target_link_libraries( ${EXECUTABLE_NAME} dl )
elseif( UNIX )
    target_link_libraries( ${EXECUTABLE_NAME} dl )
elseif( WIN32 )
endif()
#############################################