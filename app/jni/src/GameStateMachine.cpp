//
// Created by v on 12.12.2018.
//

#include "GameStateMachine.h"

GameStateMachine::GameStateMachine()
{
    gameStates.reserve(10);
    gameStatesForDelete.reserve(10);
}
GameStateMachine::~GameStateMachine()
{
    //all objects will delete in update() after returning from state->update()
    //update() its continue call after Game->endGame()
}

void GameStateMachine::pushState(GameState* state)
{
    gameStates.push_back(state);
    gameStates.back()->onEnter();
}

void GameStateMachine::changeState(GameState* state) // == POP old state + PUSH new state !!
{
    if(!gameStates.empty())// if NOT EMPTY exit from previous state
    {
        // getStateID() return POINTER char* - can equals because pointer is static ( 1 for all object this class)
        if(gameStates.back()->getStateID() == state->getStateID())
        {
            return; // if new state == current state exit from method and not change state
        }
        if(gameStates.back()->onExit())
        {
            gameStatesForDelete.push_back(gameStates.back());
            gameStates.pop_back();

            gameStates.push_back(state);
            gameStates.back()->onEnter();
        }
    }
}

void GameStateMachine::popState()
{
    if(!gameStates.empty())
    {
        if(gameStates.back()->onExit())
        {
            gameStatesForDelete.push_back(gameStates.back());
            gameStates.pop_back();
        }
    }
}


void GameStateMachine::update()
{
    //  ----------------- VERY IMPORTANT !!!!! ---------------------
    // any fn. after completion ALWAYS must return to the place from which it was called so that the program could work further
    if(!gameStates.empty())
    {
        gameStates.back()->update();
    }
    // HERE will return ALL update () fnl. from any state

    // delete the state ONLY AFTER the program returned from ALL FUNCTIONS of this state !!!!!
    if(!gameStatesForDelete.empty())
    {
        for(long i = gameStatesForDelete.size(); i > 0; i--)
        {
            delete gameStatesForDelete.back();
            gameStatesForDelete.pop_back(); // reduce .size() on 1
        }
    }
}

void GameStateMachine::draw()
{
    if(!gameStates.empty())
    {
        gameStates.back()->draw();
    }
}

void GameStateMachine::playSound()
{
    if(!gameStates.empty())
    {
        gameStates.back()->playSound();
    }
}
