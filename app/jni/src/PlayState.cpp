//
// Created by v on 12.12.2018.
//

#include "PlayState.h"
#include "TextureManager.h"
#include "ForShaders.h"
#include "GlobalVariables.h"
#include <cstring>

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

const char* const PlayState::playStateID = "PLAY_STATE";

bool PlayState::onEnter()
{
    int w,h =0;
    TextureManager::instance()->load_PNG("images/portrait.png", "portrait", &w, &h);
    SDL_Log("images/portrait.png W = %i, H = %i", w, h);

    char vert[100];
    strcpy(vert, GLOBAL_VARS::PATH_TO_APP_SOURCE);
    strcat(vert, "/qwe.v");

    char fragm[100];
    strcpy(fragm, GLOBAL_VARS::PATH_TO_APP_SOURCE);
    strcat(fragm, "/qwe2.f");
    shaderProgram = ForShaders::makeProgram(vert, fragm);

    SDL_Log("shaderProgram = %i", shaderProgram);
    return true;
}

bool PlayState::onExit()
{
    TextureManager::instance()->deleteFromTextureMap("portrait");

    glDeleteProgram(shaderProgram);

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

