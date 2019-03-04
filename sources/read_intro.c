//
// Created by trist on 10/12/2018.
//

#include "../headers/read_intro.h"

void read_intro(SDL_Surface* screen, FILE* file, int *stop, SDL_KeyboardEvent space)
{
    SDL_Surface *textboxProf = NULL, *tuto = NULL, *textboxMC = NULL, *tutoChoice = NULL;
    TTF_Font *font = NULL, *fontChoice1 = NULL, *fontChoice2 = NULL;
    SDL_Rect posTextbox, posTuto, posTutoChoice;
    SDL_Event event;
    SDL_Color black = {0, 0, 0};
    char text[1000] = "", *newLine = NULL, *comment = NULL, *bar = NULL, *diese = NULL;
    int tmp = 0;

    posTextbox.x = 229;
    posTextbox.y = 800;
    posTuto.x = 530;
    posTuto.y = 800;
    posTutoChoice.x = 530;
    posTutoChoice.y = 950;

    textboxProf = IMG_Load("../images/textboxAssembly.PNG");
    textboxMC = IMG_Load("../images/textbox.png");

    font = TTF_OpenFont("../fonts/alterebro-pixel-font.ttf", FONT_SIZE);
    fontChoice1 = TTF_OpenFont("../fonts/alterebro-pixel-font.ttf", FONT_SIZE);
    fontChoice2 = TTF_OpenFont("../fonts/alterebro-pixel-font.ttf", FONT_SIZE);

  /*  if(event.type == SDL_KEYDOWN)
    {
        if(event.key.keysym.sym == SDLK_SPACE)
        {
            */


           // }
      //  }

        TTF_CloseFont(font);
        TTF_CloseFont(fontChoice1);
        TTF_CloseFont(fontChoice2);

        SDL_FreeSurface(textboxProf);
        SDL_FreeSurface(tuto);
        SDL_FreeSurface(textboxMC);
    //}
}