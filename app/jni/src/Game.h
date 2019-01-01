#ifndef SDL2_E_GAME_H
#define SDL2_E_GAME_H

#include "SDL.h"
#include "GameStateMachine.h"
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

class Game
{
public:
    void init();
    void updateEventHandler();

    void update();
    void draw();
    void playSound();

    void endGame();

    int getScreenWidth(){ return screenWidth;}
    int getScreenHeight(){ return screenHeight;}
    GameStateMachine* getStateMachine() {return gameStateMachine;}

    bool isRunning() {return running;}

    void reCreateWindow()
    {
        SDL_GetCurrentDisplayMode(0, &DM);
        screenWidth = DM.w;
        screenHeight = DM.h;
        SDL_Log("screenWidth = %i, screenHeight = %i",screenWidth , screenHeight);

        SDL_DestroyWindow(window);

        window = SDL_CreateWindow( "Game", 0, 0, screenWidth, screenHeight,
                                   SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL |SDL_WINDOW_RESIZABLE );

        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

        SDL_GL_MakeCurrent(window, glContext); // set old context for new window

        glViewport(0, 0, screenWidth, screenHeight); // for current resolution

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    static Game* instance()
    {
        static Game inst;
        return &inst;
    }

private:
    Game();
    ~Game();

    bool running;
    int screenWidth;
    int screenHeight;

    SDL_DisplayMode DM;
    SDL_Window *window;
    SDL_GLContext glContext;

    GameStateMachine* gameStateMachine;
};



#endif //SDL2_E_GAME_H
