#include "Game.h"
#include "GlobalVariables.h"
#include "ForShaders.h"

const int FPS = 60;
const int TIME_FOR_1_LOOP = 1000 / FPS; //16,6 milisec ( 1000 milisec == 1 sec )

char* GLOBAL_VARS::PATH_TO_APP_SOURCE;

int main(int argc, char* argv[])
{
    GLOBAL_VARS::PATH_TO_APP_SOURCE = argv[1];
    SDL_Log("GLOBAL_VARS::PATH_TO_APP_SOURCE = %s", GLOBAL_VARS::PATH_TO_APP_SOURCE);


    int frameStart = 0;
    int frameTime = 0;

    Game::instance()->init();

    while(Game::instance()->isRunning())
    {

        Game::instance()->update();
        Game::instance()->render();
        Game::instance()->playSound();

        frameTime = SDL_GetTicks() - frameStart;

        //SDL_Log("frameTime = %i ", frameTime);

        if(frameTime < TIME_FOR_1_LOOP)
        {
            SDL_Delay((int)(TIME_FOR_1_LOOP - frameTime));
        }// loop end here !!! after sleep timeout

        //time loop calculating start HERE !!!!
        frameStart = SDL_GetTicks();

        // need do before next iteration
        Game::instance()->updateEventHandler(); // CAN close game in any state !!

    }

    SDL_Delay(500);

    Game::instance()->endGame();

    return 0;
}

/*
int main(int argc, char* argv[])
{

    //SCREEN
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        SDL_Log( "SDL inited !!!!" );

        SDL_DisplayMode dm;
        SDL_GetDesktopDisplayMode(0, &dm); // if resolution change in SDL, this function will return the previous native display mode !!!
        SDL_Log( "screen WIDTH = %d, screen HEIGHT = %d" , dm.w, dm.h );
    }
    else
    {
        SDL_Log( "SDL init error" );
    }

    //GRAPHICS
    //OpenGL_ES_2

    //PHYSICS
    glm::vec4 v1 = glm::vec4(3.7f, 2.4f, 4.5f, 1.0f);
    SDL_Log( "v1 = %f", v1[2]);

    //IMAGES
    SDL_Surface* loadedSurface = IMG_Load( "images/portrait.png" );
    if( loadedSurface == NULL )
    {
        SDL_Log( "SDL_image Error: %s", IMG_GetError() );
    }
    else
    {
        SDL_Log( "IMAGE LOADED !!!!" );
    }

    //SOUND EFFECTS
    // MIX_DEFAULT_FREQUENCY = sample rate = frequensy = speed playing
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4069) == -1)
    {
        SDL_Log( "SDL mixer init error" );
    } else
    {
        SDL_Log( "SDL mixer inited" );

    }
    Mix_Chunk* sound_gr = Mix_LoadWAV("sounds/grenlf1a.wav");
    if (sound_gr == NULL)
    {
        SDL_Log("Error load wave file");
    } else {
        Mix_PlayChannel(-1, sound_gr, 2);
    }

    //SCREEN TEXT
    FT_Library ft_lib;
    if (FT_Init_FreeType(&ft_lib))
    {
        SDL_Log( "freetype init error" );
    } else
    {
        SDL_Log( "freetype inited" );
    }

    SDL_Log( "argv[0] = %s", argv[0] );
    SDL_Log( "argv[1] = %s", argv[1] );

    FT_Face ft_face;
    FT_Error ft_error = FT_New_Face(ft_lib, argv[1], 0, &ft_face);

    if (ft_error != 0)
    {
        SDL_Log( "font load error" );
    } else
    {
        SDL_Log( "font loaded" );
        FT_Set_Pixel_Sizes(ft_face, 0, 24);
    }

    SDL_Log("HELLO !!!");

    SDL_Delay(5000);
    Mix_FreeChunk(sound_gr);
    Mix_CloseAudio();
    return 0;
}

 */