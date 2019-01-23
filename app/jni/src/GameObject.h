//
// Created by v on 16.12.2018.
//

#ifndef SDL2_E_GAMEOBJECT_H
#define SDL2_E_GAMEOBJECT_H


//Base class for Territory, Barriers, Bushes Trees, Player, Enemies ....
//e.g. all object which interact with each other on scene
class GameObject
{
public:
    virtual ~GameObject() {}

    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void playSound() = 0;

    //free allocated resources in DESTRUCTOR

};


#endif //SDL2_E_GAMEOBJECT_H
