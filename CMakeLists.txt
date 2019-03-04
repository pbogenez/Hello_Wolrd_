cmake_minimum_required(VERSION 3.12)
project(Hello_World_ C)

set(CMAKE_C_STANDARD 99)

include_directories(SDL_image-devel-1.2.12-VC/SDL_image-1.2.12/include)
include_directories(SDL_ttf-devel-2.0.11-VC/SDL_ttf-2.0.11/include)
include_directories(SDL_mixer-1.2.12/include)
include_directories(SDL-1.2.15/include)
link_directories(SDL_image-devel-1.2.12-VC/SDL_image-1.2.12/lib/x86)
link_directories(SDL_ttf-devel-2.0.11-VC/SDL_ttf-2.0.11/lib/x86)
link_directories(SDL_mixer-1.2.12/lib/x86)
link_directories(SDL-1.2.15/lib)
link_libraries(SDL_image)
link_libraries(SDL_ttf)
link_libraries(SDL_mixer)
link_libraries(mingw32 SDLmain SDL)

add_executable(Hello_World_ sources/main.c headers/include.h sources/newgame.c headers/newgame.h sources/menu.c headers/menu.h sources/mastermind.c headers/mastermind.h sources/option.c headers/option.h sources/quit.c headers/quit.h sources/read_intro.c headers/read_intro.h sources/scratch.c headers/scratch.h sources/end.c headers/end.h sources/volume.c headers/volume.h sources/load_save.c headers/load_save.h sources/credits.c headers/credits.h)