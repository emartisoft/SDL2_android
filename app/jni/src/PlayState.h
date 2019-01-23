#ifndef SDL2_E_PLAYSTATE_H
#define SDL2_E_PLAYSTATE_H

#include "GameState.h"
#include "GameObject.h"
#include <vector>

class PlayState : public GameState
{
public:
    PlayState();
    virtual ~PlayState();

    virtual void onEnter();

    virtual void update();
    virtual void draw();
    virtual void playSound();

    virtual void onExit();

    virtual const char* const getStateID() const { return playStateID;}

private:
    static const char* const playStateID;

    std::vector<GameObject*> gameObjects;

};

#endif //SDL2_E_PLAYSTATE_H
