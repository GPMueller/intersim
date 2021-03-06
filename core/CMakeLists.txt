######### CMake Version #####################
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
#############################################
set( CMAKE_DISABLE_SOURCE_CHANGES  OFF )
set( CMAKE_DISABLE_IN_SOURCE_BUILD ON  )
#############################################

######### Options ###########################
option( CORE_USE_CUDA    "Use CUDA to speed up certain parts of the code."              OFF )
option( CORE_BUILD_TEST  "Build unit tests for the core library."                       OFF )
option( CORE_BUILD_PYLIB "Build shared library for Python."                             ON  )
#############################################

######### Meta information about the project
set(META_PROJECT_NAME         "InterSim")
set(META_PROJECT_DESCRIPTION  "particle interactions")
set(META_AUTHOR_ORGANIZATION  "")
set(META_AUTHOR_DOMAIN        "https://github.com/GPMueller/intersim")
set(META_AUTHOR_MAINTAINER    "gideon.mueller.91@outlook.com")
set(META_VERSION_MAJOR        "0")
set(META_VERSION_MINOR        "0")
set(META_VERSION_PATCH        "0")
set(META_VERSION_REVISION     "${GIT_REV}")
set(META_VERSION              "${META_VERSION_MAJOR}.${META_VERSION_MINOR}.${META_VERSION_PATCH}")
set(META_NAME_VERSION         "${META_PROJECT_NAME} v${META_VERSION} (${META_VERSION_REVISION})")
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

######### Project Name ######################
project( ${META_PROJECT_NAME} VERSION ${META_VERSION} )
#############################################


######### CUDA decisions ####################
# if (VF_USE_CUDA)
#     find_package(CUDA REQUIRED)
#     add_definitions(-DUSE_CUDA)
#     set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} --std=c++11 -arch=sm_30 --expt-relaxed-constexpr" )
# endif()
#############################################


######### Generate Core_Defines.h ################
set( VERSION_STRING "${META_VERSION}" )
set( VERSION_REVISION_STRING "${META_VERSION_REVISION}" )
string( TOUPPER ${CORE_SCALAR_TYPE} CORE_SCALAR_TYPE_UPPERCASE )
if ( CORE_USE_CUDA )
	set ( CORE_DEFINE_CUDA "#define CORE_USE_CUDA" )
endif( )
if ( CORE_USE_THREADS )
	set ( CORE_DEFINE_THREADS "#define CORE_USE_THREADS" )
endif( )
configure_file( ${PROJECT_SOURCE_DIR}/CMake/Core_Defines.h.in ${PROJECT_SOURCE_DIR}/include/Core_Defines.h )
#############################################


######### Files #############################
set(HEADER_FILES
    include/InterSim/State.h
    include/InterSim/Simulation.h
    include/Data/State.hpp
    include/Data/Data.hpp
    include/Simulation/Simulation.hpp
    include/Simulation/Simulation_type.hpp
	include/Simulation/Simulation_Type_Wave.hpp
    include/Solver/Solver.hpp
    include/Solver/Solver_Matrix.hpp
)
source_group( "include" FILES ${HEADER_FILES} )

set(SOURCE_FILES
    src/InterSim/State.cpp
    src/InterSim/Simulation.cpp
    src/Data/Data.cpp
	src/Simulation/Simulation_Type_Wave.cpp
    src/Solver/Solver.cpp
    src/Solver/Solver_Matrix.cpp
)
source_group( "src" FILES ${SOURCE_FILES} )
#############################################



######### libInterSim ####################
### Build and Link Library
if( NOT CORE_USE_CUDA )
	######### Tell CMake to create the object files
	add_library( ${PROJECT_NAME} OBJECT ${HEADER_FILES} ${SOURCE_FILES} )
	######### Tell CMake to create the static core library for the C++ UIs
    add_library( ${PROJECT_NAME}Static STATIC $<TARGET_OBJECTS:${PROJECT_NAME}> )
	######### Tell CMake to create the shared core library for the Python UI
    if( CORE_BUILD_PYLIB )
        add_library( Py${PROJECT_NAME} SHARED $<TARGET_OBJECTS:${PROJECT_NAME}> )
    endif( )
else( )
    include_directories( ${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/thirdparty )
    cuda_add_library( ${PROJECT_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES} )
    if( CORE_BUILD_PYLIB )
        cuda_add_library( Py${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} )
    endif( )
    target_link_libraries( ${PROJECT_NAME} ${CUDA_LIBRARIES} )
endif( )
### Include Directories
target_include_directories( ${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories( ${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/thirdparty)
target_include_directories( ${PROJECT_NAME}Static PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories( ${PROJECT_NAME}Static PUBLIC ${PROJECT_SOURCE_DIR}/thirdparty)
### Properties
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS OFF)
### Set library output paths for Python shared lib
if( CORE_BUILD_PYLIB )
    ### We want it to be placed under core/pyintersim/ s.t. it is directly part of the python core module/package
	set( PYLIB_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/core/pyintersim )
    set_target_properties( Py${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PYLIB_OUTPUT_DIR} )
    if ( MSVC )
		foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
			string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
        	set_target_properties( Py${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${PYLIB_OUTPUT_DIR} )
		endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )
    endif ( MSVC )
endif( )
### Install
# install(TARGETS ${PROJECT_NAME}Static DESTINATION lib)
# install(DIRECTORY include DESTINATION include/InterSim)
#############################################


######### Test executable ###################
set( TEST_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR} )
### Test creation macro
macro( add_framework_test testName testSrc )
    # Executable
    add_executable( ${testName} test/main.cpp ${testSrc} )
    # Link Library
    target_link_libraries( ${testName} ${PROJECT_NAME} )
    # Properties
    set_property(TARGET ${testName} PROPERTY RUNTIME_OUTPUT_DIRECTORY ${TEST_RUNTIME_OUTPUT_DIRECTORY})
    set_property(TARGET ${testName} PROPERTY CXX_STANDARD 11)
    set_property(TARGET ${testName} PROPERTY CXX_STANDARD_REQUIRED ON)
    set_property(TARGET ${testName} PROPERTY CXX_EXTENSIONS OFF)
    # Include Directories
    target_include_directories( ${testName} PRIVATE ${PROJECT_SOURCE_DIR}/test)
    # Add the test
    add_test( NAME        ${testName}
        WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
        COMMAND           ${testName} --use-colour=yes )
endmacro( add_framework_test testName testSrc )
### Create tests if needed
if ( CORE_BUILD_TEST )
    ### Enable CTest testing
    enable_testing()

    ###### Test 1
    add_framework_test( test test/test.cpp )
endif()
#############################################