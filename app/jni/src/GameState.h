//
// Created by v on 12.12.2018.
//

#ifndef SDL2_E_GAMESTATE_H
#define SDL2_E_GAMESTATE_H

//Base class for all states in game
class GameState
{
public:
    virtual ~GameState() {}

    virtual bool onEnter() = 0; // init state

    virtual void update() = 0;
    virtual void render() = 0;
    virtual void playSound() = 0;

    virtual bool onExit() = 0; //clear state

    virtual const char* const getStateID() const = 0;

};

#endif //SDL2_E_GAMESTATE_H
