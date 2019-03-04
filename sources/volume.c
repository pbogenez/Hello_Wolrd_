//
// Created by trist on 18/12/2018.
//

#include "../headers/volume.h"

void volumeChange(SDL_Surface* screen, int* volume, SDL_Event event, SDL_Surface* mute, SDL_Surface *sound, SDL_Rect posSound)
{
    if(*volume == MIX_MAX_VOLUME)
    {
        SDL_BlitSurface(sound, NULL, screen, &posSound);
    }
    else if(!*volume)
    {
        SDL_BlitSurface(mute, NULL, screen, &posSound);
    }
    if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        if(event.button.button == SDL_BUTTON_LEFT)
        {
            if(event.button.x >= posSound.x && event.button.x <= posSound.x + sound->w &&
               event.button.y >= posSound.y && event.button.y <= posSound.y + sound->h)
            {
                if(*volume == MIX_MAX_VOLUME)
                {
                    *volume = 0;
                }
                else if(*volume == 0)
                {
                    *volume = MIX_MAX_VOLUME;
                }
            }
        }
    }
    Mix_VolumeMusic(*volume);
}