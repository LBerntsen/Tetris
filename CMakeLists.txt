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
        src/core/game.cpp
        src/core/game.h
        src/core/gameScene.cpp
        src/core/gameScene.h
        src/gui/mainwindow.cpp
        src/gui/mainwindow.h
        src/gui/mainwindow.ui
        src/core/tile.cpp
        src/core/tile.h
        src/core/blockshape.cpp
        src/core/blockshape.h
        src/core/Blocks/square.cpp
        src/core/Blocks/square.h
        src/core/Blocks/block.cpp
        src/core/Blocks/block.h
        src/core/Blocks/tblock.cpp
        src/core/Blocks/tblock.h
        src/core/Blocks/jblock.cpp
        src/core/Blocks/jblock.h
        src/core/Blocks/lblock.cpp
        src/core/Blocks/lblock.h
        src/core/Blocks/straightblock.cpp
        src/core/Blocks/straightblock.h
        src/core/Blocks/zblock.cpp
        src/core/Blocks/zblock.h
        src/core/Blocks/reversezblock.cpp
        src/core/Blocks/reversezblock.h)

target_link_libraries(tetris
        Qt::Core
        Qt::Gui
        Qt::Widgets)
