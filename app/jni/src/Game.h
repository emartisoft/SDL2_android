//
// Created by v on 06.12.2018.
//

#ifndef SDL2_E_GAME_H
#define SDL2_E_GAME_H

#include "SDL.h"

class Game
{
public:
    void init();
    void updateInputHandler();

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
};



#endif //SDL2_E_GAME_H
