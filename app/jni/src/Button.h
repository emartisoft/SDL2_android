#ifndef SDL2_E_BUTTON_H
#define SDL2_E_BUTTON_H

#include "GameControlObject.h"
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include "glm.hpp"
#include "SDL_mixer.h"

class Button : public GameControlObject
{

public:
    Button();
    virtual ~Button();

    //allocate and prepare resource for this object
    virtual bool init(float x, float y, float z, float width, float height,
                      const char* textureName1, const char* textureName2 = nullptr);

    virtual void update();
    virtual void draw();
    virtual void playSound();

    void setCallback(void(*callback)()) {callback_fn = callback;}

    //free allocated resources in DESTRUCTOR

private:
    void(*callback_fn)();

    GLuint vertexBuffer;
    GLuint shaderProgramButton;

    glm::mat4 P; // only Projection matrix for 2D

    // music
    Mix_Chunk* soundClick = nullptr;
    bool readyForPlay = false;

    const char* textureID1;
    const char* textureID2;

    float m_x, m_y, m_width, m_height;

    bool buttonClicked;
};


#endif //SDL2_E_BUTTON_H
