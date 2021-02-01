CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

SET(CMAKE_CXX_COMPILER "g++")
SET(CMAKE_C_COMPILER "gcc")

SET(CMAKE_BUILD_TYPE Release)
SET(CMAKE_EXE_LINKER_FLAGS -O3)
SET(CMAKE_EXE_LINKER_FLAGS -fopenmp)

if(APPLE)
    SET(CMAKE_EXE_LINKER_FLAGS -Xpreprocessor)
    SET(CMAKE_EXE_LINKER_FLAGS -lomp)
endif()

PROJECT(julia)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED True)

SET(SRCS
    main.cpp 
    complex.cpp 
    fractal.cpp 
    fractalmodel.cpp 
    julia.cpp
    EasyBMP/EasyBMP.cpp
    )
    
SET(HEADERS
    complex.hpp 
    fractal.hpp 
    fractalmodel.hpp 
    julia.hpp
    EasyBMP/EasyBMP.h
    )

ADD_EXECUTABLE(julia ${SRCS} ${HEADERS})

# cmake -G "MinGW Makefiles" .
# default = nmake
