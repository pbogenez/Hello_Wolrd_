//
// Created by trist on 10/12/2018.
//

#include "../headers/scratch.h"

void scratch(SDL_Surface* screen, int* stop, int* checkpoint)
{
    if(*stop == 4)
    {
        SDL_Surface *textbox = NULL, *c = NULL, *funct[8] = {NULL}, *background = NULL, *scratch = NULL, *scratchBackground = NULL;
        SDL_Rect posTextbox, posC, pos[8], posBackground, posScratch, posScratchBackground;
        int leftClickOngoing[8] = {0}, solution[8] = {0}, end;
        SDL_Event event;

        posScratch.x = 229;
        posScratch.y = 0;
        posScratchBackground.x = 229;
        posScratchBackground.y = 0;
        posBackground.x = 0;
        posBackground.y = 0;
        posC.x = 1400;
        posC.y = 0;
        posTextbox.x = 229;
        posTextbox.y = 800;
        pos[0].x = 1250;
        pos[0].y = 20;
        for(int i = 1; i < 8; i++)
        {
            pos[i].x = pos[0].x;
            pos[i].y = pos[i-1].y + 100;
        }

        funct[0] = IMG_Load("../images/DRINK.png");
        funct[1] = IMG_Load("../images/WATER.png");
        funct[2] = IMG_Load("../images/GRAB.png");
        funct[3] = IMG_Load("../images/EAT.png");
        funct[4] = IMG_Load("../images/FOOD.png");
        funct[5] = IMG_Load("../images/PLATE.png");
        funct[6] = IMG_Load("../images/GRAB.png");
        funct[7] = IMG_Load("../images/GET_UP.png");
        textbox = IMG_Load("../images/textbox.png");
        c = IMG_Load("../images/c.png");
        background = IMG_Load("../images/fond_scratch.jpg");
        scratch = IMG_Load("../images/texte_sur_transparence_scratch.png");
        scratchBackground = IMG_Load("../images/fond_blanc_scratch.png");

        while(*stop == 4)
        {
            SDL_BlitSurface(background, NULL, screen, &posBackground);
            SDL_BlitSurface(c, NULL, screen, &posC);
            SDL_BlitSurface(textbox, NULL, screen, &posTextbox);
            SDL_BlitSurface(scratchBackground, NULL, screen, &posScratchBackground);
            for(int i = 0; i < 8; i++)
            {
                SDL_BlitSurface(funct[i], NULL, screen, &pos[i]);
            }
            SDL_BlitSurface(scratch, NULL, screen, &posScratch);

            end = 1;

            SDL_Flip(screen);

            SDL_WaitEvent(&event);
            switch(event.type)
            {
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            *checkpoint = *stop;
                            *stop = -1;
                            break;
                        default:
                            break;
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(event.button.button == SDL_BUTTON_LEFT)
                    {
                        for(int i = 0; i < 8; i++)
                        {
                            if(event.button.x >= pos[i].x && event.button.x <= pos[i].x + funct[i]->w && event.button.y >= pos[i].y && event.button.y <= pos[i].y + funct[i]->h)
                            {
                                SDL_ShowCursor(SDL_DISABLE);
                                leftClickOngoing[i] = 1;
                            }
                        }
                    }
                    break;
                case SDL_MOUSEMOTION:
                    for(int i = 0; i < 8; i++)
                    {
                        if (leftClickOngoing[i] == 1)
                        {
                            pos[i].x = event.motion.x - funct[i]->w / 2;
                            pos[i].y = event.motion.y - funct[i]->h / 2;
                        }
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    for(int i = 0; i < 8; i++)
                    {
                        leftClickOngoing[i] = 0;

                    }
                    SDL_ShowCursor(SDL_ENABLE);
                    for(int i = 0; i < 8; i++)
                    {                                 //readjustment of the functions in the answer holes
                        if (pos[i].x > 60 && pos[i].x < 120 && pos[i].y > 65 && pos[i].y < 125)
                        {
                            pos[i].x = 219;
                            pos[i].y = 95;
                        }
                        else if (pos[i].x > 459)
                        {
                            if(pos[i].x < 559)
                            {
                                if(pos[i].y > 45)
                                {
                                    if(pos[i].y < 145)
                                    {
                                        pos[i].x = 509;
                                        pos[i].y = 95;
                                    }
                                }
                            }
                        }
                        else if (pos[i].x > 249)
                        {
                            if(pos[i].x < 349)
                            {
                                if(pos[i].y > 195)
                                {
                                    if(pos[i].y < 295)
                                    {
                                        pos[i].x = 299;
                                        pos[i].y = 245;
                                    }
                                }
                            }
                        }
                        else if (pos[i].x > 249)
                        {
                            if(pos[i].x < 349)
                            {
                                if(pos[i].y > 350)
                                {
                                    if(pos[i].y < 450)
                                    {
                                        pos[i].x = 299;
                                        pos[i].y = 400;
                                    }
                                }
                            }
                        }
                        else if (pos[i].x > 459)
                        {
                            if(pos[i].x < 559)
                            {
                                if(pos[i].y > 350)
                                {
                                    if(pos[i].y < 450)
                                    {
                                        pos[i].x = 509;
                                        pos[i].y = 400;
                                    }
                                }
                            }
                        }
                        else if (pos[i].x > 459)
                        {
                            if(pos[i].x < 559)
                            {
                                if(pos[i].y > 540)
                                {
                                    if(pos[i].y < 640)
                                    {
                                        pos[i].x = 509;
                                        pos[i].y = 590;
                                    }
                                }
                            }
                        }
                        else if (pos[i].x > 249)
                        {
                            if(pos[i].x < 349)
                            {
                                if(pos[i].y > 100)
                                {
                                    if(pos[i].y < 240)
                                    {
                                        pos[i].x = 299;
                                        pos[i].y = 590;
                                    }
                                }
                            }
                        }
                        else if (pos[i].x > 249)
                        {
                            if(pos[i].x < 349)
                            {
                                if(pos[i].y >595)
                                {
                                    if(pos[i].y < 715)
                                    {
                                        pos[i].x = 299;
                                        pos[i].y = 645;
                                    }
                                }
                            }
                        }
                    }
                    if(pos[0].x == 1 && pos[0].y == 1)
                    {
                        solution[0] = 1;
                    }
                    else
                    {
                        solution[0] = 0;
                    }
                    if(pos[1].x == 1 && pos[1].y == 1)
                    {
                        solution[1] = 1;
                    }
                    else
                    {
                        solution[1] = 0;
                    }
                    if(pos[2].x == 1 && pos[2].y == 1)
                    {
                        solution[2] = 1;
                    }
                    else
                    {
                        solution[2] = 0;
                    }
                    if(pos[3].x == 1 && pos[3].y == 1)
                    {
                        solution[3] = 1;
                    }
                    else
                    {
                        solution[3] = 0;
                    }
                    if(pos[4].x == 1 && pos[4].y == 1)
                    {
                        solution[4] = 1;
                    }
                    else
                    {
                        solution[4] = 0;
                    }
                    if(pos[5].x == 1 && pos[5].y == 1)
                    {
                        solution[5] = 1;
                    }
                    else
                    {
                        solution[5] = 0;
                    }
                    if(pos[6].x == 1 && pos[6].y == 1)
                    {
                        solution[6] = 1;
                    }
                    else
                    {
                        solution[6] = 0;
                    }
                    if(pos[7].x == 1 && pos[7].y == 1)
                    {
                        solution[7] = 1;
                    }
                    else
                    {
                        solution[7] = 0;
                    }
                default:
                    break;
            }
            for(int i = 0; i < 8; i++)
            {
                if(solution[i] == 0)
                {
                    end = 0;
                }
            }
            if(end == 1)
            {
                *stop = 1;
            }
        }
    }
}