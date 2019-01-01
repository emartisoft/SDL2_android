#ifndef SDL2_E_PAUSESTATE_H
#define SDL2_E_PAUSESTATE_H

#include "GameState.h"
#include "GameObject.h"
#include "GameControlObject.h"
#include <vector>

class PauseState : public GameState
{
public:
    PauseState();
    virtual ~PauseState();

    virtual bool onEnter();

    virtual void update();
    virtual void draw();
    virtual void playSound();

    virtual bool onExit();

    virtual const char* const getStateID() const { return playStateID;}

private:
    static const char* const playStateID;

    std::vector<GameControlObject*> gameControlObjects;
    std::vector<GameObject*> gameObjects;

    static void pauseToPlay();
};


#endif //SDL2_E_PAUSESTATE_H
