cmake_minimum_required(VERSION 3.26)
project(hmac_sha1 C)

set(CMAKE_C_STANDARD 11)



set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")




add_executable(hmac_sha1 main.c)
