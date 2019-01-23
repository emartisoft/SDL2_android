#include "PauseState.h"
#include "Game.h"
#include "Button.h"

PauseState::PauseState()
{

}

PauseState::~PauseState()
{
    for(int i = 0; i < gameObjects.size(); i++)
    {
        if(gameObjects[i] != nullptr) delete gameObjects[i];
    }
}

const char* const PauseState::playStateID = "PAUSE_STATE";

void PauseState::onEnter()
{
    int screenW = Game::instance()->getScreenWidth();
    int screenH = Game::instance()->getScreenHeight();

    SDL_Log("screenW = %i   screenH = %i", screenW, screenH);

    Button* buttonPlay = new Button;
    buttonPlay->init(380, 550, 0.9, 400, 200, "resume1.png", "resume2.png");
    buttonPlay->setCallback(pauseToPlay);
    gameObjects.push_back(buttonPlay);

}

void PauseState::onExit()
{



}

void PauseState::update()
{
    for(int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
}

void PauseState::draw()
{
    for(int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }
}

void PauseState::playSound()
{
    for(int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->playSound();
    }
}

void PauseState::pauseToPlay()
{
    Game::instance()->getStateMachine()->popState();
}