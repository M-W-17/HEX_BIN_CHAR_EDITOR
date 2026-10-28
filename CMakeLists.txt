cmake_minimum_required(VERSION 4.0)

project(HEX_BIN_CHAR_EDITOR)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(HEX_BIN_CHAR_EDITOR
        main.cpp
        FileManager.h
        FileManager.cpp
        DataConverter.h
        DataConverter.cpp
        UserInterface.h
        UserInterface.cpp
        Controller.h
        Controller.cpp
)
