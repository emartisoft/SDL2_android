#include "MainMenuState.h"
#include "Button.h"
#include "Game.h"
#include "PlayState.h"


MainMenuState::MainMenuState()
{

}

MainMenuState::~MainMenuState()
{
    for(int i = 0; i < gameControlObjects.size(); i++)
    {
        if(gameControlObjects[i] != nullptr) delete gameControlObjects[i];
    }

    for(int i = 0; i < gameObjects.size(); i++)
    {
        if(gameObjects[i] != nullptr) delete gameObjects[i];
    }
}

const char* const MainMenuState::playStateID = "MAIN_MENU_STATE";

bool MainMenuState::onEnter()
{
    int screenW = Game::instance()->getScreenWidth();
    int screenH = Game::instance()->getScreenHeight();

    SDL_Log("screenW = %i   screenH = %i", screenW, screenH);

    Button* buttonPlay = new Button;
    buttonPlay->init(1050, 70, 0.9, 400, 200, "play1.png", "play2.png");
    buttonPlay->setCallback(mainMenuToPlay);
    gameControlObjects.push_back(buttonPlay);

    return true;
}

bool MainMenuState::onExit()
{


    return true;
}

void MainMenuState::update()
{
    for(int i = 0; i < gameControlObjects.size(); i++)
    {
        gameControlObjects[i]->update();
    }
    for(int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
}

void MainMenuState::draw()
{
    for(int i = 0; i < gameControlObjects.size(); i++)
    {
        gameControlObjects[i]->draw();
    }
    for(int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }
}

void MainMenuState::playSound()
{
    for(int i = 0; i < gameControlObjects.size(); i++)
    {
        gameControlObjects[i]->playSound();
    }
    for(int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->playSound();
    }
}


void MainMenuState::mainMenuToPlay()
{
    Game::instance()->getStateMachine()->changeState(new PlayState);
}