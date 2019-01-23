#ifndef SDL2_E_MAINMENUSTATE_H
#define SDL2_E_MAINMENUSTATE_H

#include "GameState.h"
#include "GameObject.h"
#include <vector>
#include <mutex>

class MainMenuState : public GameState
{
public:
    MainMenuState();
    virtual ~MainMenuState();

    virtual void onEnter();

    virtual void update();
    virtual void draw();
    virtual void playSound();

    virtual void onExit();

    virtual const char* const getStateID() const { return playStateID;}

    std::vector<GameObject*> gameObjects;

    static void mainMenuToPlay();

private:
    static const char* const playStateID;

    std::mutex mutexObject;
};


#endif //SDL2_E_MAINMENUSTATE_H
