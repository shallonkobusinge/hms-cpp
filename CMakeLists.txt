cmake_minimum_required(VERSION 3.22)
project(hms)

set(CMAKE_CXX_STANDARD 14)

add_executable(hms main.cpp utils/headers.h utils/models.cpp services/UserService.h services/RoomService.h controllers/app.h)
