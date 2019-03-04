#include "../headers/include.h"
#include "../headers/newgame.h"
#include "../headers/menu.h"
#include "../headers/mastermind.h"
#include "../headers/option.h"
#include "../headers/quit.h"
#include "../headers/scratch.h"
#include "../headers/credits.h"

int main(int argc, char *argv[])
{
    SDL_Surface *screen = NULL;
    int stop = 4, checkpoint = 0, volume = MIX_MAX_VOLUME;
    Mix_Music *music;

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    screen = SDL_SetVideoMode(WIDTH_SDL, HEIGHT_SDL, NB_COLOR, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
    SDL_WM_SetCaption("Hello World;", NULL);

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    music = Mix_LoadMUS("../music/idle.mp3");
    Mix_PlayMusic(music, -1);
    Mix_VolumeMusic(volume);

    while(stop != 0)
    {
        menu(screen, &stop, &checkpoint);
        new_game(screen, &stop, &checkpoint);
        options(screen, &stop, checkpoint, &volume);
        mastermind(screen, &stop, &checkpoint);
        quit(screen , &stop, checkpoint);
        scratch(screen, &stop, &checkpoint);
        credits(screen, &stop);
    }
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    TTF_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}