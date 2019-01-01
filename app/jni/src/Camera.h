#ifndef SDL2_E_CAMERA_H
#define SDL2_E_CAMERA_H

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "Game.h"

class Camera
{

public:

    glm::mat4 getCamera3D()
    {
        return getPerspective3D() * getView3D();
    }

    glm::mat4 getView3D()
    {
        updateCameraVectors();

        return glm::lookAt(cameraPos, cameraDirection , cameraUp);
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
    //                             x   y   z
    glm::mat4 swapAXIS = glm::mat4(0, -1,  0, 0,
                                   1,  0,  0, 0,
                                   0,  0,  1, 0,
                                   0,  0,  0, 1);

    glm::vec3 cameraPos = glm::vec3(0.0f, 2.0f, 5.0f);
    glm::vec3 cameraFrontPos = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 cameraUp;

    glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f);

    glm::vec3 cameraDirection;
    glm::vec3 cameraRight;


    void updateCameraVectors()
    {
        cameraDirection = glm::normalize(cameraFrontPos - cameraPos);
        cameraRight = glm::normalize(glm::cross(cameraDirection, worldUp));
        cameraUp = glm::normalize(glm::cross(cameraRight, cameraDirection));
    }
};

#endif //SDL2_E_CAMERA_H
