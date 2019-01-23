#include "PlayState.h"
#include "CubeExample.h"
#include "TerritoryExample.h"

PlayState::PlayState()
{

}

PlayState::~PlayState()
{

    for(int i = 0; i < gameObjects.size(); i++)
    {
        if(gameObjects[i] != nullptr) delete gameObjects[i];
    }
}

const char* const PlayState::playStateID = "PLAY_STATE";

void PlayState::onEnter()
{
    CubeExample* cubeExample = new CubeExample;
    cubeExample->init();
    gameObjects.push_back(cubeExample);

    TerritoryExample* territoryExample = new TerritoryExample;
    territoryExample->init();
    gameObjects.push_back(territoryExample);

}

void PlayState::onExit()
{


}

void PlayState::update()
{
    float radius = 10.0f;
    float camX = glm::sin(glm::radians((double)SDL_GetTicks() / 200)) * radius;
    float camZ = glm::cos(glm::radians((double)SDL_GetTicks() / 200)) * radius;

    //SDL_Log("SDL_GetTicks() / 1000 = %i",(SDL_GetTicks() / 1000));

    Camera::instance()->setCameraPosition(glm::vec3(camX, 3.0f, camZ));

    for(int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
}

void PlayState::draw()
{
    for(int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }
}

void PlayState::playSound()
{
    for(int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->playSound();
    }
}

