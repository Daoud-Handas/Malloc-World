cmake_minimum_required(VERSION 3.20)
project(Malloc_World C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Malloc_World
        actionPlayer.h
        fight.h
        header.h
        inventory.h
        main.c
        main.h
        map.h
        monsterHandler.h
        other.h)
