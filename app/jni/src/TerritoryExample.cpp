#include "TerritoryExample.h"
#include "SDL.h"
#include "ForShaders.h"
#include "Camera.h"
#include "gtc/type_ptr.hpp"
#include "GlobalVariables.h"
#include <cstring>

TerritoryExample::TerritoryExample()
{

}

TerritoryExample::~TerritoryExample()
{
    glDeleteProgram(shaderProgramTerritory);
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteBuffers(1, &vertexBuffer2);
}

GLuint TerritoryExample::shaderProgramTerritory = 0;

bool TerritoryExample::init()
{

    float* vertices = new float[1800];
    float X = -5.0f;
    float Z = 3.0f;

    int count = 0;

    for(int i = 0; i < 10; i++)
    {
        for(int g = 0; g < 10; g++)
        {
            vertices[count++] = X;
            vertices[count++] = 0;
            vertices[count++] = Z;

            vertices[count++] = X;
            vertices[count++] = 0;
            vertices[count++] = Z -1;

            vertices[count++] = X + 1;
            vertices[count++] = 0;
            vertices[count++] = Z;

            vertices[count++] = X;
            vertices[count++] = 0;
            vertices[count++] = Z -1;

            vertices[count++] = X + 1;
            vertices[count++] = 0;
            vertices[count++] = Z;

            vertices[count++] = X + 1;
            vertices[count++] = 0;
            vertices[count++] = Z - 1;

          X += 1.0f;
        }

        X = -5.0f;
        Z = Z -1.0f;
    }
    SDL_Log("count = %i", count);

    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 1800, vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    delete[] vertices;


    float* vertices2 = new float[90];
    count = 0;
    float X1 = -5.0f;
    float Z1 = 3.0f;
    float X2 = 10.0f;
    float Z2 = 3.0f;
    for(int i = 0; i < 15; i++)
    {
        vertices2[count++] = X1;
        vertices2[count++] = 0;
        vertices2[count++] = Z1;

        vertices2[count++] = X2;
        vertices2[count++] = 0;
        vertices2[count++] = Z2;

        Z1 = Z1 - 1;
        Z2 = Z2 - 1;
    }

    glGenBuffers(1, &vertexBuffer2);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 90, vertices2, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    delete[] vertices2;

    shaderProgramTerritory = ForShaders::makeProgram("/territory.vert", "/territory.frag");
    SDL_Log("shaderProgram = %i", shaderProgramTerritory);


    MVP = Camera::instance()->getCamera3D();

    SDL_Log("TerritoryExample::init()");
    return true;
}

void TerritoryExample::update()
{


    MVP = Camera::instance()->getCamera3D();
}

void TerritoryExample::draw()
{
    glLineWidth(5);

    glUseProgram(shaderProgramTerritory);

    // 1 draw
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glUniformMatrix4fv(glGetUniformLocation(shaderProgramTerritory, "MVP_matrix"), 1, GL_FALSE, glm::value_ptr(MVP));
    glDrawArrays(GL_LINES, 0, 600);

    // 2 draw
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer2);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glUniformMatrix4fv(glGetUniformLocation(shaderProgramTerritory, "MVP_matrix"), 1, GL_FALSE, glm::value_ptr(MVP));
    glDrawArrays(GL_LINES, 0, 30);

    glUseProgram(0);
}

void TerritoryExample::playSound()
{

}
