//
// Created by v on 12.12.2018.
//

#ifndef SDL2_E_PLAYSTATE_H
#define SDL2_E_PLAYSTATE_H

#include "GameState.h"
#include "glm.hpp"
#include "GameObject.h"
#include "GameControlObject.h"
#include <vector>
#include "GLES2/gl2.h"
#include "GLES2/gl2ext.h"

class PlayState : public GameState
{
public:
    PlayState();
    virtual ~PlayState();

    virtual bool onEnter();

    virtual void update();
    virtual void render();
    virtual void playSound();

    virtual bool onExit();

    virtual const char* const getStateID() const { return playStateID;}

private:
    static const char* const playStateID;

    std::vector<GameControlObject*> gameControlObjects;
    std::vector<GameObject*> gameObjects;

    GLuint shaderProgram;
};

#endif //SDL2_E_PLAYSTATE_H
