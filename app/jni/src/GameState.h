#ifndef SDL2_E_GAMESTATE_H
#define SDL2_E_GAMESTATE_H

//Base class for all states in game
class GameState
{
public:
    virtual ~GameState() {}

    virtual void onEnter() = 0; // init state

    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void playSound() = 0;

    virtual void onExit() = 0; //clear state

    virtual const char* const getStateID() const = 0;

};

#endif //SDL2_E_GAMESTATE_H
