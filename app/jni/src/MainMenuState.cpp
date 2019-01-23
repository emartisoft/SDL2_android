#include "MainMenuState.h"
#include "Button.h"
#include "Game.h"
#include "PlayState.h"
#include "Background.h"

MainMenuState::MainMenuState()
{

    mutexObject.lock();
    int a = 2 + 2;
    mutexObject.unlock();

}

MainMenuState::~MainMenuState()
{
    for(int i = 0; i < gameObjects.size(); i++)
    {
        if(gameObjects[i] != nullptr) delete gameObjects[i];
    }
}

const char* const MainMenuState::playStateID = "MAIN_MENU_STATE";

void MainMenuState::onEnter()
{

    int screenW = Game::instance()->getScreenWidth();
    int screenH = Game::instance()->getScreenHeight();

    SDL_Log("screenW = %i   screenH = %i", screenW, screenH);

    Button* buttonPlay = new Button;
    buttonPlay->init(1050, 70, 0.9, 400, 200, "play1.png", "play2.png");
    buttonPlay->setCallback(MainMenuState::mainMenuToPlay);
    gameObjects.push_back(buttonPlay);

}

void MainMenuState::onExit()
{

}

void MainMenuState::update()
{
    if(1)
    {
        for(int i = 0; i < gameObjects.size(); i++)
        {
            gameObjects[i]->update();
        }
    } else
    {

    }
}

void MainMenuState::draw()
{
    if(1)
    {
        for(int i = 0; i < gameObjects.size(); i++)
        {
            gameObjects[i]->draw();
        }
    } else
    {

    }
}

void MainMenuState::playSound()
{
    if(1)
    {
        for(int i = 0; i < gameObjects.size(); i++)
        {
            gameObjects[i]->playSound();
        }
    } else
    {

    }
}



void MainMenuState::mainMenuToPlay()
{
    Game::instance()->getStateMachine()->changeState(new PlayState);
}