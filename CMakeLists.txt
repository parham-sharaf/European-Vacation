cmake_minimum_required(VERSION 3.16)
project(European-Vacation)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(European-Vacation
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        DB/Database/Database.h DB/Database/Database.cpp
        ManageCity/ManageCities.h ManageCity/ManageCities.cpp
        ManageCity/City/City.h ManageCity/City/City.cpp
        Admin/Admin.h Admin/Admin.cpp
        UI/login/login.h UI/login/login.cpp UI/login/login.ui
        UI/Map/Map.h UI/Map/Map.cpp
        UI/ModdedLineEdit/moddedlineedit.h UI/ModdedLineEdit/moddedlineedit.cpp
        UI/TreeWidget/Interface.h UI/TreeWidget/Interface.cpp
        )

target_link_libraries(${PROJECT_NAME} sqlite3)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
