//
// Created by trist on 10/12/2018.
//

#include "../headers/quit.h"

void quit(SDL_Surface *screen, int *stop, int checkpoint)
{
     if(*stop -2)
     {

         SDL_Surface *quitMenu = NULL, *question = NULL, *yes = NULL, *no = NULL;
         SDL_Rect posQuitMenu, posQuestion, posYes, posNo;
         TTF_Font *fontQuestion = NULL, *fontYes = NULL, *fontNo = NULL;
         SDL_Color blue = {116, 197, 255}, white = {255, 255, 255};
         SDL_Color colorYes = white, colorNo = white;
         SDL_Event event;
         int stylePrev = 0, styleCur = 1;

         posQuitMenu.x = 285;
         posQuitMenu.y = 403;
         posQuestion.x = 331;
         posQuestion.y = 430;
         posYes.x = 834;
         posYes.y = 549;
         posNo.x = 1127;
         posNo.y = 549;

         quitMenu = IMG_Load("../images/echap1350x275.png");

         fontQuestion = TTF_OpenFont("../fonts/HARLOWSI.TTF", FONT_SIZE);
         fontYes = TTF_OpenFont("../fonts/HARLOWSI.TTF", FONT_SIZE);
         fontNo = TTF_OpenFont("../fonts/HARLOWSI.TTF", FONT_SIZE);

         question = TTF_RenderText_Blended(fontQuestion, "Are you sure you want to exit the game?", white);

         while(*stop == -2)
        {
             if(styleCur != stylePrev)
             {
                 no = TTF_RenderText_Blended(fontNo, "No", colorNo);
                 yes = TTF_RenderText_Blended(fontYes, "Yes", colorYes);
             }
             fprintf(stderr, "%d %d\n%d %d\n%d %d", question->w, question->h, yes->w, yes->h, no->w, no->h);

             SDL_BlitSurface(quitMenu, NULL, screen, &posQuitMenu);
             SDL_BlitSurface(question, NULL, screen, &posQuestion);
             SDL_BlitSurface(yes, NULL, screen, &posYes);
             SDL_BlitSurface(no, NULL, screen, &posNo);

             SDL_Flip(screen);

             SDL_WaitEvent(&event);
             switch(event.type)
             {
                 case SDLK_ESCAPE:
                     *stop = checkpoint;
                     break;
                 case SDL_MOUSEMOTION:
                     if(event.motion.x >= posYes.x && event.motion.x <= posYes.x + yes->w && event.motion.y >= posYes.y && event.motion.y <= posYes.y + yes->h)
                     {
                         stylePrev = styleCur;
                         styleCur = 1;
                         colorYes = blue;
                     }
                     else if(event.motion.x >= posNo.x && event.motion.x <= posNo.x + no->w && event.motion.y >= posNo.y && event.motion.y <= posNo.y + no->h)
                     {
                         colorNo = blue;
                         stylePrev = styleCur;
                         styleCur = 1;
                     }
                     else
                     {
                         colorNo = white;
                         colorYes = white;
                         stylePrev = styleCur;
                         styleCur = 0;
                     }
                     break;
                 case SDL_MOUSEBUTTONUP:
                     if(event.button.button == SDL_BUTTON_LEFT)
                     {
                         if (event.button.x >= posYes.x && event.button.x <= posYes.x + yes->w &&
                         event.button.y >= posYes.y && event.button.y <= posYes.y + yes->h)
                         {
                             *stop = 0;
                         }
                         else if (event.button.x >= posNo.x && event.button.x <= posNo.x + no->w &&
                         event.button.y >= posNo.y && event.button.y <= posNo.y + no->h)
                         {
                             *stop = checkpoint;
                         }
                     }
                     break;
                 default:
                     break;
             }
        }
         TTF_CloseFont(fontNo);
         TTF_CloseFont(fontQuestion);
         TTF_CloseFont(fontYes);

         SDL_FreeSurface(quitMenu);
         SDL_FreeSurface(question);
         SDL_FreeSurface(yes);
         SDL_FreeSurface(no);
     }
}