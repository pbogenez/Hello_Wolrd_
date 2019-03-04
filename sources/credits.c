//
// Created by trist on 18/12/2018.
//

#include "../headers/credits.h"

void credits(SDL_Surface *screen, int *stop)
{
    if(*stop == 5)
    {
        Mix_VolumeMusic(0);
        SDL_Surface* credit = NULL, *credit2 = NULL;
        SDL_Rect posCredits, posCredits2;
        int cpt = 1;

        posCredits.x = 0;
        posCredits.y = 1080;
        posCredits2.x = 0;
        posCredits2.y = 1080;

        credit = IMG_Load("../images/credits1.png");
        credit2 = IMG_Load("../images/credits2.png");

        while(*stop == 5)
        {
            if(cpt == 1)
            {
                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
                SDL_BlitSurface(credit, NULL, screen, &posCredits);
                posCredits.y--;
            }
            else
            {
                SDL_BlitSurface(credit2, NULL, screen, &posCredits2);
                posCredits2.y--;
            }

            SDL_Flip(screen);

            if(posCredits.y == 0)
            {
                cpt = 2;
            }
            if(posCredits2.y == 0)
            {
                *stop = 1;
            }
        }
    }

}