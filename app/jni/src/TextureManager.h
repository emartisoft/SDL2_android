//
// Created by v on 16.12.2018.
//

#ifndef SDL2_E_TEXTUREMANAGER_H
#define SDL2_E_TEXTUREMANAGER_H


class TextureManager
{
public:
    static TextureManager* instance()
    {
        static TextureManager inst;
        return &inst;
    }

private:
    TextureManager();
    ~TextureManager();

};


#endif //SDL2_E_TEXTUREMANAGER_H
