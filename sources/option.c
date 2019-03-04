//
// Created by trist on 10/12/2018.
//

#include "../headers/option.h"
#include "../headers/volume.h"
#include "../headers/load_save.h"

void options(SDL_Surface* screen, int *stop, int checkpoint, int* volume)
{
    if(*stop == -1)
    {
        SDL_Surface *optionMenu = NULL, *save = NULL, *vMusic = NULL, *menu = NULL, *quitGame = NULL, *cross = NULL, *mute = NULL, *sound = NULL;
        TTF_Font *fontSave = NULL, *fontvMusic = NULL, *fontMenu = NULL, *fontQuit = NULL;
        SDL_Rect posOptionMenu, posSave, posVMusic, posMenu, posQuitGame, posCross, posSound;
        SDL_Event event;
        SDL_Color blue = {116, 197, 255}, white = {255, 255, 255};
        SDL_Color colorSave = white, colorMenu = white, colorQuit = white;
        int stylePrev = 0, styleCur = 1;

        posSound.x = 700;
        posSound.y = 565;
        posOptionMenu.x = 360;
        posOptionMenu.y = 215;
        posSave.x = 850;
        posSave.y = 415;
        posVMusic.x = 850;
        posVMusic.y = 565;
        posMenu.x = 850;
        posMenu.y = 265;
        posQuitGame.x = 850;
        posQuitGame.y = 715;
        posCross.x = 1520;
        posCross.y = 215;

        optionMenu = IMG_Load("../images/menu_echap3.png");
        cross = IMG_Load("../images/croix.png");
        mute = IMG_Load("../images/mute.png");
        sound = IMG_Load("../images/sound.png");

        fontSave = TTF_OpenFont("../fonts/HARLOWSI.ttf", FONT_SIZE);
        fontvMusic = TTF_OpenFont("../fonts/HARLOWSI.ttf", FONT_SIZE);
        fontMenu = TTF_OpenFont("../fonts/HARLOWSI.ttf", FONT_SIZE);
        fontQuit = TTF_OpenFont("../fonts/HARLOWSI.ttf", FONT_SIZE);

        while(*stop == -1)
        {
            if(styleCur != stylePrev)
            {
                quitGame = TTF_RenderText_Blended(fontQuit, "Quit Game", colorQuit);
                save = TTF_RenderText_Blended(fontSave, "Save Game", colorSave);
                vMusic = TTF_RenderText_Blended(fontvMusic, "Music Volume", white);
                menu = TTF_RenderText_Blended(fontMenu, "Menu", colorMenu);
            }
            SDL_BlitSurface(optionMenu, NULL, screen, &posOptionMenu);
            SDL_BlitSurface(cross, NULL, screen, &posCross);
            SDL_BlitSurface(quitGame, NULL, screen, &posQuitGame);
            if(checkpoint != 1)
            {
                SDL_BlitSurface(save, NULL, screen, &posSave);
                SDL_BlitSurface(menu, NULL, screen, &posMenu);
            }
            SDL_BlitSurface(vMusic, NULL, screen, &posVMusic);

            volumeChange(screen, volume, event, mute, sound, posSound);

            SDL_Flip(screen);

            SDL_WaitEvent(&event);
            switch(event.type)
            {
                case SDL_QUIT:
                    *stop = -2;
                    break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        *stop = checkpoint;
                    }
                    break;
                case SDL_MOUSEMOTION:
                    if(event.motion.x >= posQuitGame.x && event.motion.x <= posQuitGame.x + quitGame->w &&
                       event.motion.y >= posQuitGame.y && event.motion.y <= posQuitGame.y + quitGame->h)
                    {
                        colorQuit = blue;
                        stylePrev = styleCur;
                        styleCur = 1;
                    }
                    else if(event.motion.x >= posMenu.x && event.motion.x <= posMenu.x + menu->w &&
                            event.motion.y >= posMenu.y && event.motion.y <= posMenu.y + menu->h)
                    {
                        colorMenu = blue;
                        stylePrev = styleCur;
                        styleCur = 1;
                    }
                    else if(event.motion.x >= posSave.x && event.motion.x <= posSave.x + save->w &&
                            event.motion.y >= posSave.y && event.motion.y <= posSave.y + save->h)
                    {
                        colorSave = blue;
                        stylePrev = styleCur;
                        styleCur = 1;
                    }
                    else
                    {
                        colorMenu = white;
                        colorSave = white;
                        colorQuit = white;
                        stylePrev = styleCur;
                        styleCur = 0;
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    if(event.button.button == SDL_BUTTON_LEFT)
                    {
                        if((event.button.x >= posCross.x && event.button.x <= posCross.x + cross->w &&
                            event.button.y >= posCross.y && event.button.y <= posCross.y + cross->h) ||
                           (event.button.x < posOptionMenu.x || event.button.x > posOptionMenu.x + optionMenu->w ||
                            event.button.y < posOptionMenu.y || event.button.y > posOptionMenu.y + optionMenu->h))
                        {
                            *stop = checkpoint;
                        }
                        else if(event.button.x >= posQuitGame.x && event.button.x <= posQuitGame.x + quitGame->w &&
                                event.button.y >= posQuitGame.y && event.button.y <= posQuitGame.y + quitGame->h)
                        {
                            *stop = -2;
                            colorQuit = white;
                            quitGame = TTF_RenderText_Blended(fontQuit, "Quit Game", colorQuit);
                            SDL_BlitSurface(quitGame, NULL, screen, &posQuitGame);
                            SDL_Flip(screen);
                        }
                        else if(event.button.x >= posMenu.x && event.button.x <= posMenu.x + menu->w &&
                                event.button.y >= posMenu.y && event.button.y <= posMenu.y + menu->h)
                        {
                            *stop = 1;
                        }
                        else if(event.button.x >= posSave.x && event.button.x <= posSave.x + save->w &&
                                event.button.y >= posSave.y && event.button.y <= posSave.y + save->h)
                        {
                            FILE* fp;
                            fp = fopen("../texts/save.txt","w+");
                            save_game(fp, checkpoint);
                            fclose(fp);
                        }
                    }
                default:
                    break;
            }
        }
        TTF_CloseFont(fontSave);
        TTF_CloseFont(fontvMusic);
        TTF_CloseFont(fontQuit);
        TTF_CloseFont(fontMenu);

        SDL_FreeSurface(optionMenu);
        SDL_FreeSurface(cross);
        SDL_FreeSurface(quitGame);
        SDL_FreeSurface(save);
        SDL_FreeSurface(menu);
        SDL_FreeSurface(vMusic);
    }
}