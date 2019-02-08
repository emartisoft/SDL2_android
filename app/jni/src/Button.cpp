#include "Button.h"
#include "TextureManager.h"
#include "EventHandler.h"
#include "ForShaders.h"
#include "gtc/type_ptr.hpp"
#include "Camera.h"
#include <cstring>

Button::Button()
{
    readyForPlay = false;
    buttonClicked = false;
}

Button::~Button()
{
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteProgram(shaderProgramButton);

    Mix_FreeChunk(soundClick);

    TextureManager::instance()->deleteFromTextureMap(textureID1);
    TextureManager::instance()->deleteFromTextureMap(textureID2);
}

bool Button::init(float x, float y, float z, float width, float height,
                  const char* textureName1, const char* textureName2)
{
    m_x = x;
    m_y = y;
    m_width = width;
    m_height = height;

    float vertices[30]
            {   //position                  //texture coords
                x, y, z,                    0.0f, 0.0f,
                x + width, y, z,            1.0f, 0.0f,
                x, y + height, z,           0.0f, 1.0f,

                x + width, y, z,            1.0f, 0.0f,
                x, y + height, z,           0.0f, 1.0f,
                x + width, y + height, z,   1.0f, 1.0f
            };

    SDL_Log("x = %f   y = %f  x + width = %f   y + height = %f", x, y, x + width, y + height);

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 30, vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    shaderProgramButton = ForShaders::makeProgram("/button.vert", "/button.frag");

    textureID1 = textureName1;
    if(textureName2 != nullptr) textureID2 = textureName2;
    else textureID2 = textureName1;

    TextureManager::instance()->load_PNG(textureID1);
    TextureManager::instance()->load_PNG(textureID2);

    soundClick = Mix_LoadWAV("sounds/menu1.wav");

    P = Camera::instance()->getCamera2D();

    return true;
}

void Button::update()
{
    if(EventHandler::instance()->checkFingerEvent(FINGER_DOWN))
    {
        glm::vec2 fingerPos =  EventHandler::instance()->getFingerDownPos();

        if(fingerPos.x > m_x && fingerPos.x < m_x + m_width &&
           fingerPos.y > m_y && fingerPos.y < m_y + m_height)
        {
            buttonClicked = true;
            readyForPlay = true;
        }
    }

    if(EventHandler::instance()->checkFingerEvent(FINGER_UP))
    {
        glm::vec2 fingerPos =  EventHandler::instance()->getFingerUpPos();

        if(fingerPos.x > m_x && fingerPos.x < m_x + m_width &&
           fingerPos.y > m_y && fingerPos.y < m_y + m_height &&
           buttonClicked)
        {
            buttonClicked = false;
            callback_fn();
        }
        buttonClicked = false;
    }

    P = Camera::instance()->getCamera2D();
}

void Button::draw()
{

    glUseProgram(shaderProgramButton);

    if(buttonClicked)
    {
        glBindTexture(GL_TEXTURE_2D, TextureManager::instance()->getTexture(textureID2));
    }
    else
    {
        glBindTexture(GL_TEXTURE_2D, TextureManager::instance()->getTexture(textureID1));
    }

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, 0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(sizeof(float) * 3));

    glUniformMatrix4fv(glGetUniformLocation(shaderProgramButton, "P_matrix"), 1, GL_FALSE, glm::value_ptr(P));
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glUseProgram(0);


}

void Button::playSound()
{
    if(readyForPlay)
    {
        Mix_PlayChannel(-1, soundClick, 0);
        readyForPlay = false;
    }
}