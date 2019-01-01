#include "CubeExample.h"
#include "GlobalVariables.h"
#include "TextureManager.h"
#include "ForShaders.h"
#include "SDL.h"
#include "gtc/type_ptr.hpp"
#include "matrix.hpp"
#include "gtc/matrix_transform.hpp"
#include <cstring>

CubeExample::CubeExample()
{

}

CubeExample::~CubeExample()
{
    glDeleteProgram(shaderProgramCube);
    glDeleteBuffers(1, &vertexBuffer);
}

GLuint CubeExample::shaderProgramCube = 0;

bool CubeExample::init()
{

    float vertices[36] =
            {       //position                  colors
                    0.0f, 0.0f, 0.0f,     1.0f, 0.0f, 0.0f,
                    1.0f, 0.0f, 0.0f,     1.0f, 0.0f, 0.0f,
                    0.0f, 2.0f, 0.0f,     0.0f, 0.0f, 1.0f,

                    1.0f, 0.0f, 0.0f,     1.0f, 0.0f, 0.0f,
                    0.0f, 2.0f, 0.0f,     0.0f, 0.0f, 1.0f,
                    1.0f, 1.0f, 0.0f,     1.0f, 1.0f, 1.0f,
            };

    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 36, vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    shaderProgramCube = ForShaders::makeProgram("/cube.vert", "/cube.frag");
    SDL_Log("shaderProgram = %i", shaderProgramCube);

    rotationMatrix = glm::mat4(1.0f);
    translationMatrix = glm::mat4(1.0f);
    scaleMatrix = glm::mat4(1.0f);
    modelMatrix = scaleMatrix * rotationMatrix * translationMatrix;

    MVP = Camera::instance()->getCamera3D() * modelMatrix;


    SDL_Log("CubeExample::init()");
    return true;
}

void CubeExample::update()
{
    rotationMatrix = glm::rotate(rotationMatrix, glm::radians(1.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 2.0f, 0.0));
    modelMatrix = rotationMatrix * translationMatrix;

    MVP = Camera::instance()->getCamera3D() * modelMatrix;
}

void CubeExample::draw()
{
    glUseProgram(shaderProgramCube);

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(sizeof(float) * 3));

    glUniformMatrix4fv(glGetUniformLocation(shaderProgramCube, "MVP_matrix"), 1, GL_FALSE, glm::value_ptr(MVP));
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glUseProgram(0);
}

void CubeExample::playSound()
{

}