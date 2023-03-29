cmake_minimum_required(VERSION 3.24)
project(Proyecto_Zoologuico)

include_directories(lib)
include_directories(src)
include_directories(test)

add_subdirectory(lib/googleTest)
add_subdirectory(src)
#add_subdirectory(test)


set(CMAKE_CXX_STANDARD 17)

add_executable(Proyecto_Zoologuico main.cpp src/main.cpp Zoologico.cpp Zoologico.h Habitad.cpp Habitad.h Animal.cpp Animal.h Terrestre.cpp Terrestre.h Acuatico.cpp Acuatico.h Volador.cpp Volador.h SemiAcuatico.cpp SemiAcuatico.h main.h)
