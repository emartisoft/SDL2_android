#ifndef SDL2_E_GAMESTATEMACHINE_H
#define SDL2_E_GAMESTATEMACHINE_H

#include "GameState.h"
#include <vector>

class GameStateMachine
{
public:
    GameStateMachine();
    ~GameStateMachine();

    void pushState(GameState* state);
    void changeState(GameState* state);
    void popState();


    void update();
    void draw();
    void playSound();

    int getStatesCount(){return gameStates.size();}

    const char* getStateID()
    {
        if(!gameStates.empty()) return gameStates.back()->getStateID();
         else return "";
    }

private:
    std::vector<GameState*> gameStates;
    std::vector<GameState*> gameStatesForDelete;

};

#endif //SDL2_E_GAMESTATEMACHINE_H
