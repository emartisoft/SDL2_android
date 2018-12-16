//
// Created by v on 06.12.2018.
//

#ifndef SDL2_E_GAME_H
#define SDL2_E_GAME_H

#include "SDL.h"
#include "GameStateMachine.h"

class Game
{
public:
    void init();
    void updateEventHandler();

    void update();
    void render();
    void playSound();

    void endGame();

    int getScreenWidth(){ return screenWidth;}
    int getScreenHeight(){ return screenHeight;}

    bool isRunning() {return running;}

    static Game* instance()
    {
        static Game inst;
        return &inst;
    }

private:
    Game();
    ~Game();

    bool running ;
    int screenWidth;
    int screenHeight;

    SDL_DisplayMode DM;
    SDL_Window *window;
    SDL_GLContext glContext;

    GameStateMachine* gameStateMachine;
};



#endif //SDL2_E_GAME_H
