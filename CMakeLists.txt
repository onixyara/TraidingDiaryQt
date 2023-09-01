cmake_minimum_required(VERSION 3.25)
project(TraidingDiaryQt)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(TraidingDiaryQt main.cpp src/Parser.cpp src/Parser.h src/Trade.h src/utility.h)
target_link_libraries(TraidingDiaryQt
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

