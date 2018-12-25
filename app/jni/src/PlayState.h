//
// Created by v on 12.12.2018.
//

#ifndef SDL2_E_PLAYSTATE_H
#define SDL2_E_PLAYSTATE_H

#include "GameState.h"
#include "GameObject.h"
#include "GameControlObject.h"
#include <vector>

class PlayState : public GameState
{
public:
    PlayState();
    virtual ~PlayState();

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

};

#endif //SDL2_E_PLAYSTATE_H
