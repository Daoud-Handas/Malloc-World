cmake_minimum_required(VERSION 3.19)
project(Malloc_World C)

set(CMAKE_C_STANDARD 99)

add_executable(Malloc_World main.c Functions/header.h Functions/inventory.h Functions/actionPlayer.h Functions/map.h Functions/other.h Functions/fight.h Functions/monsterHandler.h)