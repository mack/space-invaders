cmake_minimum_required(VERSION 3.14)
project(space_invadors)

set(CMAKE_CXX_STANDARD 14)

include_directories(Config)
include_directories(Model)
include_directories(View)

add_executable(space_invadors
        Config/Constants.hpp
        Controller/main.cpp
        Model/Alien.cpp
        Model/Alien.hpp
        Model/Entity.cpp
        Model/Entity.hpp
        Model/Player.cpp
        Model/Player.hpp
        Model/Projectile.cpp
        Model/Projectile.hpp
        View/board.cpp
        View/board.hpp)
