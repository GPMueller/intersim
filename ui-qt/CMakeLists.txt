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

######### QT Path ########################
if( USER_PATH_QT )
    set( CMAKE_PREFIX_PATH ${USER_PATH_QT} )
else()
    ### IFF and developers' default paths
    if ( WIN32 )
        set( CMAKE_PREFIX_PATH "C:/QT/5.7/msvc2015/" )
    elseif ( APPLE)
        set( CMAKE_PREFIX_PATH "/usr/local/qt5/" )
    elseif ( UNIX)
        set( CMAKE_PREFIX_PATH "/usr/local/qt5/" )
    endif()
endif()
MESSAGE( STATUS ">> Please check the CMAKE_PREFIX_PATH to make sure QT5 is found")
MESSAGE( STATUS ">> CMAKE_PREFIX_PATH:             " ${CMAKE_PREFIX_PATH} )
##########################################

######### Find the Qt libraries ##########
#find_package(Qt5 REQUIRED)
find_package( Qt5Core REQUIRED )
#MESSAGE( STATUS ">> Found QTCore at:        " ${Qt5Core_DIR} )
find_package( Qt5Gui REQUIRED )
#MESSAGE( STATUS ">> Found QTGui at:         " ${Qt5Gui_DIR} )
find_package( Qt5Widgets REQUIRED )
#MESSAGE( STATUS ">> Found QTWidgets at:     " ${Qt5Widgets_DIR} )
find_package( Qt5Charts REQUIRED )
#MESSAGE( STATUS ">> Found QTCharts at:      " ${Qt5Charts_DIR} )
find_package( Qt5OpenGL REQUIRED )
#MESSAGE( STATUS ">> Found QTOpenGL at:      " ${Qt5OpenGL_DIR} )
###########################################


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