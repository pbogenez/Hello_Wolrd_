//
// Created by trist on 10/12/2018.
//

#include "../headers/newgame.h"
#include "../headers/read_intro.h"

void new_game(SDL_Surface* screen, int *stop, int* checkpoint)
{
    if(*stop == 2)
    {

        SDL_Surface *class = NULL, *option = NULL, *assembly = NULL, *textboxProf = NULL, *tuto = NULL, *textboxMC = NULL, *tutoChoice = NULL;
        SDL_Rect posClass, posOption, posAssembly, posTextbox, posTuto, posTutoChoice;
        SDL_Event event;
        SDL_EnableKeyRepeat(500, 10);
        FILE* file = NULL;
        SDL_KeyboardEvent space;
        TTF_Font *font = NULL, *fontChoice1 = NULL, *fontChoice2 = NULL;
        SDL_Color black = {0, 0, 0};
        char text[1000] = "", *newLine = NULL, *comment = NULL, *bar = NULL, *diese = NULL;
        int tmp = 0;

        posClass.x = 0;
        posClass.y = 0;
        posAssembly.x = 1230;
        posAssembly.y = 0;
        posOption.x = 1867;
        posOption.y = 0;
        posTextbox.x = 229;
        posTextbox.y = 800;
        posTuto.x = 530;
        posTuto.y = 800;
        posTutoChoice.x = 530;
        posTutoChoice.y = 950;

        class = IMG_Load("../images/class.png");
        assembly = IMG_Load("../images/assembly.png");
        option = IMG_Load("../images/option.png");
        textboxProf = IMG_Load("../images/textboxAssembly.PNG");
        textboxMC = IMG_Load("../images/textbox.png");

        font = TTF_OpenFont("../fonts/alterebro-pixel-font.ttf", FONT_SIZE);
        fontChoice1 = TTF_OpenFont("../fonts/alterebro-pixel-font.ttf", FONT_SIZE);
        fontChoice2 = TTF_OpenFont("../fonts/alterebro-pixel-font.ttf", FONT_SIZE);

        file = fopen("../texts/tuto.txt", "r");

        SDL_BlitSurface(class, NULL, screen, &posClass);
        SDL_BlitSurface(assembly, NULL, screen, &posAssembly);
        SDL_BlitSurface(option, NULL, screen, &posOption);

        while(*stop == 2)
        {

            SDL_Flip(screen);

            SDL_WaitEvent(&event);
            switch(event.type)
            {
                case SDL_QUIT:
                    *checkpoint = *stop;
                    *stop = -2;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            *checkpoint = *stop;
                            *stop = -1;
                            break;
                        case SDLK_SPACE:
                            space.type = event.type;
                            space.state = SDL_PRESSED;
                            space.keysym = event.key.keysym;
                            if(!strcmp(fgets(text, 1000, file), "//EOF"))
                            {
                                fclose(file);
                                *stop = 3;
                            }
                            else {
                                if (!strcmp(text, "//choice\n"))
                                {
                                    while (tmp == 0)
                                    {
                                        tuto = TTF_RenderText_Blended(fontChoice1, "Excuse me?", black);
                                        tutoChoice = TTF_RenderText_Blended(fontChoice2, "Beep boop to you too", black);

                                        SDL_BlitSurface(textboxMC, NULL, screen, &posTextbox);
                                        SDL_BlitSurface(tuto, NULL, screen, &posTuto);
                                        SDL_BlitSurface(tutoChoice, NULL, screen, &posTutoChoice);
                                        SDL_Flip(screen);

                                        SDL_WaitEvent(&event);
                                        switch (event.type)
                                        {
                                            case SDL_MOUSEMOTION:
                                                if ((event.button.x >= posTuto.x && event.button.x <= posTuto.x + tuto->w &&
                                                     event.button.y >= posTuto.y && event.button.y <= posTuto.y + tuto->h))
                                                {
                                                    TTF_SetFontStyle(fontChoice1, TTF_STYLE_ITALIC);
                                                }
                                                if ((event.button.x >= posTutoChoice.x && event.button.x <= posTutoChoice.x + tutoChoice->w &&
                                                     event.button.y >= posTutoChoice.y && event.button.y <= posTutoChoice.y + tutoChoice->h))
                                                {
                                                    TTF_SetFontStyle(fontChoice2, TTF_STYLE_ITALIC);
                                                }
                                                else {
                                                    TTF_SetFontStyle(fontChoice1, TTF_HINTING_NORMAL);
                                                    TTF_SetFontStyle(fontChoice2, TTF_HINTING_NORMAL);
                                                }
                                                break;
                                            case SDL_MOUSEBUTTONUP:
                                                if (event.button.button == SDL_BUTTON_LEFT)
                                                {
                                                    if ((event.button.x >= posTuto.x && event.button.x <= posTuto.x + tuto->w &&
                                                         event.button.y >= posTuto.y && event.button.y <= posTuto.y + tuto->h))
                                                    {
                                                        tmp++;
                                                    }
                                                    if ((event.button.x >= posTutoChoice.x && event.button.x <= posTutoChoice.x + tutoChoice->w &&
                                                         event.button.y >= posTutoChoice.y && event.button.y <= posTutoChoice.y + tutoChoice->h))
                                                    {
                                                        tmp++;
                                                    }
                                                }
                                                break;
                                            default:
                                                break;
                                        }
                                    }
                                    SDL_PushEvent(&space);
                                }
                                newLine = strchr(text, '\n');
                                if (newLine)
                                {
                                    *newLine = ' ';
                                }
                                bar = strchr(text, '|');
                                if (bar)
                                {
                                    *bar = '\0';
                                }
                                diese = strchr(text, '#');
                                if (diese)
                                {
                                    *diese = '\0';
                                }
                                else {
                                    SDL_PushEvent(&space);
                                }
                                if (!strcmp(text, "//MC "))
                                {
                                    SDL_BlitSurface(textboxMC, NULL, screen, &posTextbox);
                                }
                                else if (!strcmp(text, "//Prof "))
                                {
                                    SDL_BlitSurface(textboxProf, NULL, screen, &posTextbox);
                                }
                                comment = strchr(text, '/');
                                if (comment)
                                {
                                    *comment = '\0';
                                }
                                tuto = TTF_RenderText_Blended(font, text, black);
                                SDL_BlitSurface(tuto, NULL, screen, &posTuto);
                                SDL_Flip(screen);
                                if (diese || comment)
                                {
                                    posTuto.x = 530;
                                    posTuto.y = 800;
                                }
                                if (newLine)
                                {
                                    posTuto.x += 22;
                                }
                                if (bar)
                                {
                                    posTuto.x = 280;
                                    posTuto.y += 55;
                                }
                                SDL_Delay(20);
                            }
                            break;
                        default:
                            break;
                    }
                    break;
                case SDL_MOUSEMOTION:
                    break;
                case SDL_MOUSEBUTTONUP:
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        if (event.button.x >= posOption.x && event.button.x <= posOption.x + option->w &&
                            event.button.y >= posOption.y && event.button.y <= posOption.y + option->h)
                        {
                            *checkpoint = *stop;
                            *stop = -1;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        SDL_FreeSurface(class);
        SDL_FreeSurface(option);
        SDL_FreeSurface(assembly);
    }
}