#ifndef SDL2_E_GAMECONTROLOBJECT_H
#define SDL2_E_GAMECONTROLOBJECT_H

// Base class for Button, CheckBox, Background, Text ....
// e.g. all items on screen ( not on scene)
class GameControlObject
{
public:
    virtual ~GameControlObject() {}

    //allocate and prepare resource for this object
    virtual bool init(float x, float y, float z, float width, float height,
                      const char* textureName1, const char* textureName2 = nullptr) = 0;

    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void playSound() = 0;

    //free allocated resources in DESTRUCTOR

};


#endif //SDL2_E_GAMECONTROLOBJECT_H
