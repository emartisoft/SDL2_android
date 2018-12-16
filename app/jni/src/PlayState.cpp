//
// Created by v on 12.12.2018.
//

#include "PlayState.h"

PlayState::PlayState()
{

}

PlayState::~PlayState()
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

bool PlayState::onEnter()
{

    return true;
}

bool PlayState::onExit()
{
    return true;
}

void PlayState::update()
{
    for(int i = 0; i < gameControlObjects.size(); i++)
    {
        //gameControlObjects[i]->update();
    }
    for(int i = 0; i < gameObjects.size(); i++)
    {
        //gameObjects[i]->update();
    }
}

void PlayState::render()
{
    for(int i = 0; i < gameControlObjects.size(); i++)
    {
        //gameControlObjects[i]->draw();
    }
    for(int i = 0; i < gameObjects.size(); i++)
    {
        //gameObjects[i]->draw();
    }
}

void PlayState::playSound()
{
    for(int i = 0; i < gameControlObjects.size(); i++)
    {
        //gameControlObjects[i]->playSound();
    }
    for(int i = 0; i < gameObjects.size(); i++)
    {
        //gameObjects[i]->playSound();
    }
}

