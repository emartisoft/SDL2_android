#include "Background.h"
#include "TextureManager.h"
#include <string>
#include "Camera.h"
#include "ForShaders.h"
#include "gtc/type_ptr.hpp"

Background::Background()
{

}

Background::~Background()
{

}

bool Background::init(kind_of_background kind,
                      float x, float y, float z,
                      float width, float height,
                      const char* textureName)
{
    SDL_Log("BACKGROUN INIT START");
    m_kind = kind;

    float vertices[30]
            {   //position                  //texture coords
                    x, y, z,                    0.0f, 0.0f,
                    x + width, y, z,            1.0f, 0.0f,
                    x, y + height, z,           0.0f, 1.0f,

                    x + width, y, z,            1.0f, 0.0f,
                    x, y + height, z,           0.0f, 1.0f,
                    x + width, y + height, z,   1.0f, 1.0f
            };


    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 30, vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    if(m_kind == SIMPLE_TEXTURE_BACKGROUND)
    {
        shaderProgramBackground = ForShaders::makeProgram("/simpleTextureBackground.vert", "/simpleTextureBackground.frag");
    }
    else if(m_kind == NOISE_TEXTURE_BACKGROUND)
    {

    }

    textureID = textureName;
    TextureManager::instance()->load_PNG(textureID);

    P = Camera::instance()->getCamera2D();

    SDL_Log("BACKGROUN INIT END");
    return true;
}

void Background::update()
{



    P = Camera::instance()->getCamera2D();
}

void Background::draw()
{
    glUseProgram(shaderProgramBackground);


    glBindTexture(GL_TEXTURE_2D, TextureManager::instance()->getTexture(textureID));


    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, 0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(sizeof(float) * 3));

    glUniformMatrix4fv(glGetUniformLocation(shaderProgramBackground, "P_matrix"), 1, GL_FALSE, glm::value_ptr(P));
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glUseProgram(0);
}

void Background::playSound()
{

}
