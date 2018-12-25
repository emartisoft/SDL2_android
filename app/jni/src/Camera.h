#ifndef SDL2_E_CAMERA_H
#define SDL2_E_CAMERA_H

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "Game.h"

class Camera
{

public:
    glm::mat4 getView3D()
    {
        return glm::lookAt(cameraPos, cameraFront, cameraUp);
    }

    glm::mat4 getPerspective3D()
    {
        return glm::perspective(glm::radians(45.0f),
                                (float)Game::instance()->getScreenWidth() / (float)Game::instance()->getScreenHeight(),
                                1.0f, 200.0f);
    }

    void setCameraPosition(glm::vec3 pos)
    {
        cameraPos = pos;
    }

    static Camera* instance()
    {
        static Camera inst;
        return &inst;
    }

private:
    Camera(){}
    ~Camera() {}

    glm::vec3 cameraPos = glm::vec3(0.0f, 2.0f, 5.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f); // Y = -X  for landscape phone orientation

};

#endif //SDL2_E_CAMERA_H
