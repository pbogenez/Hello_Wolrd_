//
// Created by trist on 10/12/2018.
//

#include "../headers/mastermind.h"

void mastermind(SDL_Surface* screen, int *stop, int* checkpoint)
{
    if(*stop ==3)
    {

        SDL_Surface *frame = NULL, *number1 = NULL, *number0 = NULL, *thinking = NULL, *sright = NULL, *sright2 = NULL, *assembly = NULL, *textbox = NULL, *option = NULL, *scpt = NULL, *scpt2 = NULL;
        SDL_Rect posNumber, pos1, pos2, pos3, pos4, pos5, pos6, posThink, posRight, posRight2, posAssembly, posTextbox, posEnd, posOption, posEnd2;
        TTF_Font *font, *fontRight;
        SDL_Event event;
        SDL_Color black = {0, 0, 0};
        int cpt = 0, right = 0, cpt2 = 9;
        char age[] = "110110", answer[7] = {0}, cright[1] = {0}, cpts[1] = {0};

        posThink.x = 0;
        posThink.y = 0;
        posNumber.x = 115;
        posNumber.y = 400;
        posRight.x = 530;
        posRight.y = 800;
        posRight2.x = 745;
        posRight2.y = posRight.y;
        pos1.x = 264;
        pos1.y = 502;
        pos2.x = 396;
        pos2.y = pos1.y;
        pos3.x = 518;
        pos3.y = pos1.y;
        pos4.x = 655;
        pos4.y = pos1.y;
        pos5.x = 787;
        pos5.y = pos1.y;
        pos6.x = 909;
        pos6.y = pos1.y;
        posAssembly.x = 1200;
        posAssembly.y = 0;
        posTextbox.x = 229;
        posTextbox.y = 800;
        posEnd.x = 280;
        posEnd.y = 855;
        posOption.x = 1867;
        posOption.y = 0;
        posEnd2.x = 495;
        posEnd2.y = posEnd.y;

        thinking = IMG_Load("../images/background.png");
        frame = IMG_Load("../images/master.png");
        assembly = IMG_Load("../images/assembly.png");
        textbox = IMG_Load("../images/textboxAssembly.PNG");
        option = IMG_Load("../images/option.png");

        font = TTF_OpenFont("../fonts/georgia.ttf", FONT_SIZE);
        fontRight = TTF_OpenFont("../fonts/alterebro-pixel-font.ttf", FONT_SIZE);

        number0 = TTF_RenderText_Blended(font, "0", black);
        number1 = TTF_RenderText_Blended(font, "1", black);


        while(*stop == 3)
        {
            if(!strcmp(age, answer) || cpt2 == 0)
            {
                if(cpt2 != 0)
                {
                    sright = TTF_RenderText_Blended(fontRight, "You have found the right number!", black);
                }
                else
                {
                    sright = TTF_RenderText_Blended(fontRight, "Boooh! The right answer was 110110!", black);
                }
                sright2 = TTF_RenderText_Blended(fontRight, "It corresponds to 58!", black);

                SDL_BlitSurface(textbox, NULL, screen, &posTextbox);
                SDL_BlitSurface(sright, NULL, screen, &posRight);
                SDL_BlitSurface(sright2, NULL, screen, &posEnd);
                SDL_BlitSurface(option, NULL, screen, &posOption);

                SDL_Flip(screen);

                SDL_Delay(2500);
                *stop = 4;
            }
            else
            {
                sprintf(cright, "%d", right);
                sright = TTF_RenderText_Blended(fontRight, "You have    right digits", black);
                sright2 = TTF_RenderText_Blended(fontRight, cright, black);
                sprintf(cpts, "%d", cpt2);
                if(cpt2 > 1)
                {
                    scpt = TTF_RenderText_Blended(fontRight, "You have    tries left", black);
                }
                else
                {
                    scpt = TTF_RenderText_Blended(fontRight, "You have    try left", black);
                }
                scpt2 = TTF_RenderText_Blended(fontRight, cpts, black);

                cpt = 0;
                right = 0;

                SDL_BlitSurface(thinking, NULL, screen, &posThink);
                SDL_BlitSurface(assembly, NULL, screen, &posAssembly);
                SDL_BlitSurface(textbox, NULL, screen, &posTextbox);
                SDL_BlitSurface(sright2, NULL, screen, &posRight2);
                SDL_BlitSurface(sright, NULL, screen, &posRight);
                SDL_BlitSurface(scpt, NULL, screen, &posEnd);
                SDL_BlitSurface(scpt2, NULL, screen, &posEnd2);
                SDL_BlitSurface(frame, NULL, screen, &posNumber);
                SDL_BlitSurface(option, NULL, screen, &posOption);

                SDL_Flip(screen);
            }
            cpt2--;
            while(cpt < 6 && *stop == 3)
            {
                SDL_WaitEvent(&event);
                switch(event.type)
                {
                    case SDL_QUIT:
                        *checkpoint = *stop;
                        *stop = -2;
                        break;
                    case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                        {
                            case SDLK_ESCAPE:
                                *checkpoint = *stop;
                                *stop = -1;
                                break;
                            case SDLK_1:
                                switch(cpt)
                                {
                                    case 0:
                                        SDL_BlitSurface(number1, NULL, screen, &pos1);
                                        answer[cpt] = '1';
                                        break;
                                    case 1:
                                        SDL_BlitSurface(number1, NULL, screen, &pos2);
                                        answer[cpt] = '1';
                                        break;
                                    case 2:
                                        SDL_BlitSurface(number1, NULL, screen, &pos3);
                                        answer[cpt] = '1';
                                        break;
                                    case 3:
                                        SDL_BlitSurface(number1, NULL, screen, &pos4);
                                        answer[cpt] = '1';
                                        break;
                                    case 4:
                                        SDL_BlitSurface(number1, NULL, screen, &pos5);
                                        answer[cpt] = '1';
                                        break;
                                    case 5:
                                        SDL_BlitSurface(number1, NULL, screen, &pos6);
                                        answer[cpt] = '1';
                                        break;
                                    default:
                                        break;
                                }
                                if(answer[cpt] == age[cpt])
                                {
                                    right++;
                                }
                                cpt++;
                                break;
                            case SDLK_KP1:
                                switch(cpt)
                                {
                                    case 0:
                                        SDL_BlitSurface(number1, NULL, screen, &pos1);
                                        answer[cpt] = '1';
                                        break;
                                    case 1:
                                        SDL_BlitSurface(number1, NULL, screen, &pos2);
                                        answer[cpt] = '1';
                                        break;
                                    case 2:
                                        SDL_BlitSurface(number1, NULL, screen, &pos3);
                                        answer[cpt] = '1';
                                        break;
                                    case 3:
                                        SDL_BlitSurface(number1, NULL, screen, &pos4);
                                        answer[cpt] = '1';
                                        break;
                                    case 4:
                                        SDL_BlitSurface(number1, NULL, screen, &pos5);
                                        answer[cpt] = '1';
                                        break;
                                    case 5:
                                        SDL_BlitSurface(number1, NULL, screen, &pos6);
                                        answer[cpt] = '1';
                                        break;
                                    default:
                                        break;
                                }
                                if(answer[cpt] == age[cpt])
                                {
                                    right++;
                                }
                                cpt++;
                                break;
                            case SDLK_0:
                                switch(cpt)
                                {
                                    case 0:
                                        SDL_BlitSurface(number0, NULL, screen, &pos1);
                                        answer[cpt] = '0';
                                        break;
                                    case 1:
                                        SDL_BlitSurface(number0, NULL, screen, &pos2);
                                        answer[cpt] = '0';
                                        break;
                                    case 2:
                                        SDL_BlitSurface(number0, NULL, screen, &pos3);
                                        answer[cpt] = '0';
                                        break;
                                    case 3:
                                        SDL_BlitSurface(number0, NULL, screen, &pos4);
                                        answer[cpt] = '0';
                                        break;
                                    case 4:
                                        SDL_BlitSurface(number0, NULL, screen, &pos5);
                                        answer[cpt] = '0';
                                        break;
                                    case 5:
                                        SDL_BlitSurface(number0, NULL, screen, &pos6);
                                        answer[cpt] = '0';
                                        break;
                                    default:
                                        break;
                                }
                                if(answer[cpt] == age[cpt])
                                {
                                    right++;
                                }
                                cpt++;
                                break;
                            case SDLK_KP0:
                                switch(cpt)
                                {
                                    case 0:
                                        SDL_BlitSurface(number0, NULL, screen, &pos1);
                                        answer[cpt] = '0';
                                        break;
                                    case 1:
                                        SDL_BlitSurface(number0, NULL, screen, &pos2);
                                        answer[cpt] = '0';
                                        break;
                                    case 2:
                                        SDL_BlitSurface(number0, NULL, screen, &pos3);
                                        answer[cpt] = '0';
                                        break;
                                    case 3:
                                        SDL_BlitSurface(number0, NULL, screen, &pos4);
                                        answer[cpt] = '0';
                                        break;
                                    case 4:
                                        SDL_BlitSurface(number0, NULL, screen, &pos5);
                                        answer[cpt] = '0';
                                        break;
                                    case 5:
                                        SDL_BlitSurface(number0, NULL, screen, &pos6);
                                        answer[cpt] = '0';
                                        break;
                                    default:
                                        break;
                                }
                                if(answer[cpt] == age[cpt])
                                {
                                    right++;
                                }
                                cpt++;
                                break;
                            default:
                                break;
                        }
                        break;
                    case SDL_MOUSEBUTTONUP:
                        if (event.button.button == SDL_BUTTON_LEFT)
                        {
                            if (event.button.x >= posOption.x && event.button.x <= posOption.x + option->w &&
                                event.button.y >= posOption.y && event.button.y <= posOption.y + option->h) {
                                *checkpoint = *stop;
                                *stop = -1;
                            }
                        }
                        break;
                    default:
                        break;
                }
                SDL_Flip(screen);
            }
        }
        TTF_CloseFont(font);
        TTF_CloseFont(fontRight);

        SDL_FreeSurface(number0);
        SDL_FreeSurface(number1);
        SDL_FreeSurface(frame);
        SDL_FreeSurface(thinking);
        SDL_FreeSurface(sright);
        SDL_FreeSurface(sright2);
        SDL_FreeSurface(assembly);
        SDL_FreeSurface(textbox);
        SDL_FreeSurface(option);
        SDL_FreeSurface(scpt);
        SDL_FreeSurface(scpt2);
    }
}