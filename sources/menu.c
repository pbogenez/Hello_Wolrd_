//
// Created by trist on 10/12/2018.
//

#include "../headers/menu.h"
#include "../headers/load_save.h"

void menu(SDL_Surface* screen, int *stop, int* checkpoint)
{
    if(*stop == 1)
    {
        SDL_Surface *background = NULL, *newGame = NULL, *exitGame = NULL, *loadGame = NULL, *help = NULL;
        SDL_Rect posBackground, posNew, posExit, posLoad, posHelp;
        TTF_Font *fontNew = NULL, *fontExit = NULL, *fontLoad = NULL, *fontHelp = NULL;
        SDL_Color green = {135, 255, 14}, white = {255, 255, 255};
        SDL_Color colorNew = white, colorExit = white, colorLoad = white, colorHelp = white;
        SDL_Event event;
        int colCur = 1, colPrev = 0;

        posBackground.x = 0;
        posBackground.y = 0;
        posNew.x = 1605;
        posNew.y = 205;
        posLoad.x = 1600;
        posLoad.y = 415;
        posHelp.x = 1630;
        posHelp.y = 622;
        posExit.x = 1660;
        posExit.y = 830;

        background = IMG_Load("../images/menu.png");

        fontNew = TTF_OpenFont("../fonts/alterebro-pixel-font.ttf", FONT_SIZE);
        fontExit = TTF_OpenFont("../fonts/alterebro-pixel-font.ttf", FONT_SIZE);
        fontLoad = TTF_OpenFont("../fonts/alterebro-pixel-font.ttf", FONT_SIZE);
        fontHelp = TTF_OpenFont("../fonts/alterebro-pixel-font.ttf", FONT_SIZE);

        while(*stop == 1)
        {
            if(colCur != colPrev)
            {
                newGame = TTF_RenderText_Solid(fontNew, "New Game", colorNew);
                exitGame = TTF_RenderText_Solid(fontExit, "Exit", colorExit);
                loadGame = TTF_RenderText_Solid(fontLoad, "Load Save", colorLoad);
                help = TTF_RenderText_Solid(fontHelp, "Credits", colorHelp);

                SDL_BlitSurface(background, NULL, screen, &posBackground);
                SDL_BlitSurface(newGame, NULL, screen, &posNew);
                SDL_BlitSurface(exitGame, NULL, screen, &posExit);
                SDL_BlitSurface(loadGame, NULL, screen, &posLoad);
                SDL_BlitSurface(help, NULL, screen, &posHelp);
            }
            SDL_Flip(screen);

            SDL_WaitEvent(&event);
            switch(event.type)
            {
                case SDL_QUIT:
                    *checkpoint = *stop;
                    *stop = -2;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        *checkpoint = *stop;
                        *stop = -1;
                    }
                    break;
                case SDL_MOUSEMOTION:
                    if(event.motion.x >= posNew.x && event.motion.x <= posNew.x + newGame->w && event.motion.y>= posNew.y && event.motion.y <= posNew.y + newGame->h)
                    {
                        colorNew = green;
                        colPrev = colCur;
                        colCur = 1;
                    }
                    else if(event.motion.x >= posExit.x && event.motion.x <= posExit.x + exitGame->w && event.motion.y>= posExit.y && event.motion.y <= posExit.y + exitGame->h)
                    {
                        colorExit = green;
                        colPrev = colCur;
                        colCur = 1;
                    }
                    else if(event.motion.x >= posLoad.x && event.motion.x <= posLoad.x + loadGame->w && event.motion.y>= posLoad.y && event.motion.y <= posLoad.y + loadGame->h)
                    {
                        colorLoad = green;
                        colPrev = colCur;
                        colCur = 1;
                    }
                    else if(event.motion.x >= posHelp.x && event.motion.x <= posHelp.x + help->w && event.motion.y>= posHelp.y && event.motion.y <= posHelp.y + help->h)
                    {
                        colorHelp = green;
                        colPrev = colCur;
                        colCur = 1;
                    }
                    else
                    {
                        colorNew = white;
                        colorExit = white;
                        colorHelp = white;
                        colorLoad = white;
                        colPrev = colCur;
                        colCur = 0;
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    if(event.button.button == SDL_BUTTON_LEFT)
                    {
                        if(event.button.x >= posNew.x && event.button.x <= posNew.x + newGame->w && event.button.y>= posNew.y && event.button.y <= posNew.y + newGame->h)
                        {
                            *stop = 2;
                        }
                        else if(event.button.x >= posExit.x && event.button.x <= posExit.x + exitGame->w && event.button.y>= posExit.y && event.button.y <= posExit.y + exitGame->h)
                        {
                            *stop = 0;
                        }
                        else if(event.motion.x >= posLoad.x && event.motion.x <= posLoad.x + loadGame->w && event.motion.y>= posLoad.y && event.motion.y <= posLoad.y + loadGame->h)
                        {
                            *stop = return_save(*stop);
                        }
                        else if(event.motion.x >= posHelp.x && event.motion.x <= posHelp.x + help->w && event.motion.y>= posHelp.y && event.motion.y <= posHelp.y + help->h)
                        {
                            *stop = 5;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        TTF_CloseFont(fontNew);
        TTF_CloseFont(fontExit);
        TTF_CloseFont(fontLoad);
        TTF_CloseFont(fontHelp);

        SDL_FreeSurface(background);
        SDL_FreeSurface(newGame);
        SDL_FreeSurface(exitGame);
        SDL_FreeSurface(loadGame);
        SDL_FreeSurface(help);
    }
}