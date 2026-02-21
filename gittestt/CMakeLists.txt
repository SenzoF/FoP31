cmake_minimum_required(VERSION 4.0)
project(gittestt)

set(CMAKE_CXX_STANDARD 20)

add_executable(gittestt main.cpp

        Essentials.h
        Textures.h
        Shapes.h
        DragFunc.h
        Motion.h
        LookMenu.h
        SoundMenu.h
        blockArrangement.h)


target_link_libraries(${PROJECT_NAME} -lconio)
target_link_libraries(${PROJECT_NAME} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)
