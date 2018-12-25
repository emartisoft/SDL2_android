#ifndef SDL2_E_CUBEEXAMPLE_H
#define SDL2_E_CUBEEXAMPLE_H

#include "GameObject.h"
#include "GLES2/gl2.h"
#include "GLES2/gl2ext.h"
#include "SDL.h"
#include "glm.hpp"
#include "Camera.h"

class CubeExample : public GameObject // TRIANGLE EXAMPLE
{
public:
    CubeExample();
    virtual ~CubeExample();

    virtual bool init();

    virtual void update();
    virtual void draw();
    virtual void playSound();

private:
    static GLuint shaderProgramCube;

    GLuint vertexBuffer;

    glm::mat4 MVP;
    glm::mat4 matrModel;
    glm::mat4 perspectiveView;
    glm::mat4 perspectiveProjection;

};


#endif //SDL2_E_CUBEEXAMPLE_H
