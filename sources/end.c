//
// Created by trist on 14/12/2018.
//

#include "../headers/end.h"

void end(SDL_Surface* screen, int* stop)
{
    if(*stop == 10)
    {
        SDL_Surface *class = NULL, *c = NULL, *cpp = NULL, *python = NULL, *assembly = NULL, *textbox = NULL;
        SDL_Rect posClass, posC, posCpp, posPython, posAssembly, posTextbox;
        SDL_Event event;

        posClass.x = 0;
        posClass.y = 0;
        posTextbox.x = 229;
        posTextbox.y = 800;
        posC.x = 0;
        posC.y = 0;
        posCpp.x = 650;
        posCpp.y = 0;
        posAssembly.x = 1300;
        posAssembly.y = 0;
        posPython.x = 1950;
        posPython.y = 0;
    }
}