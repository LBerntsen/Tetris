cmake_minimum_required(VERSION 3.27)
project(tetris)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

include_directories(src)

add_executable(tetris
        src/core/main.cpp
        src/core/app.cpp
        src/core/app.h
        src/core/block.cpp
        src/core/block.h
        src/core/game.cpp
        src/core/game.h
        src/core/gameScene.cpp
        src/core/gameScene.h
        src/gui/mainwindow.cpp
        src/gui/mainwindow.h
        src/gui/mainwindow.ui)

target_link_libraries(tetris
        Qt::Core
        Qt::Gui
        Qt::Widgets)
