#ifndef SDL2_E_BACKGROUND_H
#define SDL2_E_BACKGROUND_H

#include "GameObject.h"
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include "glm.hpp"

enum kind_of_background
{
    SIMPLE_TEXTURE_BACKGROUND,
    NOISE_TEXTURE_BACKGROUND,
};

class Background : public GameObject
{
public:
    Background();
    virtual ~Background();

    bool init(kind_of_background kind,
              float x, float y, float z,
              float width, float height,
              const char* textureName = nullptr);

    virtual void update();
    virtual void draw();
    virtual void playSound();


private:
    GLuint vertexBuffer;
    GLuint shaderProgramBackground;

    glm::mat4 P; // only Projection matrix for 2D

    const char* textureID;

    kind_of_background m_kind;
};


#endif //SDL2_E_BACKGROUND_H
