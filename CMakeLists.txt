######### CMake Version #####################
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
#############################################
set( CMAKE_DISABLE_SOURCE_CHANGES  ON )
set( CMAKE_DISABLE_IN_SOURCE_BUILD ON )
#############################################

######### Options ###########################
option( BUILD_UI_QT      "Build the QT User Interface."                                 ON  )
option( BUILD_UI_CONSOLE "Build the QT User Interface."                                 ON  )
option( CORE_USE_CUDA    "Use CUDA to speed up certain parts of the code."              OFF )
option( CORE_BUILD_TEST  "Build small test project using the library."                  OFF )
### Set the scalar type used in the core library
set( CORE_SCALAR_TYPE float )
#############################################


######### CUDA decisions ####################
# if (VF_USE_CUDA)
#     MESSAGE( STATUS ">> --------------  USING CUDA --------------" )
#     ### Set cuda toolkit path 
#     if( (NOT CUDA_TOOLKIT_ROOT_DIR) )
#         set( CUDA_TOOLKIT_ROOT_DIR /opt/cuda )
#     endif()
#     if (APPLE OR UNIX)
#         set(CMAKE_C_COMPILER   ${CUDA_TOOLKIT_ROOT_DIR}/bin/gcc)
#         set(CMAKE_CXX_COMPILER ${CUDA_TOOLKIT_ROOT_DIR}/bin/g++)
#     elseif (WIN32)
#         MESSAGE( STATUS ">> We are on Windows... CUDA Path needs to be set..." )
#     endif()
# endif()
#############################################


######### Info ##############################
MESSAGE( STATUS ">> CMAKE_C_COMPILER:        " ${CMAKE_C_COMPILER} )
MESSAGE( STATUS ">> CMAKE_CXX_COMPILER:      " ${CMAKE_CXX_COMPILER} )
#############################################


######### Project Name ######################
project( intersim )
#############################################


### Build the intersim library
add_subdirectory( core )
### Build the console UI
if ( BUILD_UI_CONSOLE )
    add_subdirectory( ui-console )
endif()
### Build the QT UI
if ( BUILD_UI_QT )
    add_subdirectory( ui-qt )
endif()