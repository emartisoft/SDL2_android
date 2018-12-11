//
// Created by v on 09.12.2018.
//

#ifndef SDL2_E_INPUTHANDLER_H
#define SDL2_E_INPUTHANDLER_H

#include "SDL.h"
#include "glm.hpp"
#include <vector>

enum kind_finger_events
{
    FINGER_DOWN = 0,
    FINGER_UP = 1,
    FINGER_MOTION = 2,
    FINGER_DOWN_FAST_UP = 3 //if was touched and released faster than 0.3 sec

};

class InputHandler
{

public:

    glm::vec2 getFingerDownPos() { return fingerDownPos;}
    glm::vec2 getFingerUpPos() { return fingerUpPos;}
    glm::vec2 getFingerMotionPos() { return fingerMotionPos;}
    glm::vec2 getFingerDownFastUpPos() { return fingerUpPos;}

    static InputHandler* instance()
    {
        static InputHandler inst;
        return &inst;
    }

    void updateEvent();
    void resetFingerEvents();

    bool checkFingerEventKind(kind_finger_events kind)
    {
        return fingerEventKind[kind];
    }

private:
    InputHandler();
    ~InputHandler();

    glm::ivec2 fingerDownPos;
    glm::ivec2 fingerUpPos;
    glm::ivec2 fingerMotionPos;

    std::vector<bool> fingerEventKind;

    unsigned int timeFingerDown;

};

#endif //SDL2_E_INPUTHANDLER_H
