#ifndef SDL2_E_TERRITORYEXAMPLE_H
#define SDL2_E_TERRITORYEXAMPLE_H

#include "GameObject.h"
#include "glm.hpp"
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

class TerritoryExample : public GameObject
{
public:
    TerritoryExample();
    virtual ~TerritoryExample();

    virtual bool init();

    virtual void update();
    virtual void draw();
    virtual void playSound();

private:
    static GLuint shaderProgramTerritory;

    GLuint vertexBuffer;
    GLuint vertexBuffer2;

    glm::mat4 MVP;
};


#endif //SDL2_E_TERRITORYEXAMPLE_H
