cmake_minimum_required(VERSION 3.20)
project(European_Vacation)

set(CMAKE_CXX_STANDARD 14)

add_executable(European_Vacation
        main.cpp
        ManageCities.cpp
        ManageCities.h
        City.h
        City.cpp)


include_directories(/usr/include)
link_directories(/usr/lib)
target_link_libraries(European_Vacation sqlite3)

#find_package (SQLite3)
#if (SQLITE3_FOUND)
#    include_directories(${SQLITE3_INCLUDE_DIRS})
#    target_link_libraries (European_Vacation ${SQLITE3_LIBRARIES})
#endif (SQLITE3_FOUND)