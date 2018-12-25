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
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    char vertexPath[200];
    strcpy(vertexPath, GLOBAL_VARS::PATH_TO_APP_SOURCE);
    strcat(vertexPath, "/cube.vert");

    char fragmentPath[200];
    strcpy(fragmentPath, GLOBAL_VARS::PATH_TO_APP_SOURCE);
    strcat(fragmentPath, "/cube.frag");

    shaderProgramCube = ForShaders::makeProgram(vertexPath, fragmentPath);
    SDL_Log("shaderProgram = %i", shaderProgramCube);

    matrModel = glm::mat4(1.0f);
    perspectiveView = Camera::instance()->getView3D();
    perspectiveProjection = Camera::instance()->getPerspective3D();


    SDL_Log("CubeExample::init()");
    return true;
}

void CubeExample::update()
{
    matrModel = glm::rotate(matrModel, glm::radians(1.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    perspectiveView = Camera::instance()->getView3D();
    perspectiveProjection = Camera::instance()->getPerspective3D();

    MVP = perspectiveProjection * perspectiveView * matrModel;
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