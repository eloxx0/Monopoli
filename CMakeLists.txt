cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-O2")
set(PACKAGE Monopoli)

##creo il progetto
project(${PACKAGE} VERSION 1.0)

##aggiungo il file eseguibile come source file
set(SOURCE_FILES src/main.cpp)

include_directories(include)

include_directories(src)

##INTERFACE crea una interfaccia. Non viene compilata e non viene incluso come
##un target nel buildsystem
add_library(Player INTERFACE include/Player.h include/HumanPlayer.h include/RobotPlayer.h)

add_library(Casella INTERFACE include/Casella.h)

add_library(Gametable INTERFACE include/GameTable.h)

##SHARED crea una libreria dinamica condivisa
add_library(Play SHARED src/Player.cpp src/HumanPlayer.cpp src/RobotPlayer.cpp src/GameTable.cpp src/Casella.cpp)

##imposto come directory di runtime la cartella bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

##imposto come directory in cui salvare le librerie la cartella lib(non funziona)
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PACKAGE}/lib)

##target per la creazione di un eseguibile
add_executable(main ${SOURCE_FILES})

##indica quali librerie utilizzare quando linka un determinato target (libreria o eseguibile)
##necessario per permettere all'eseguibile di essere linkato alle librerie dinamiche
target_link_libraries(main Play)

