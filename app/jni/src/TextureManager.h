//
// Created by v on 16.12.2018.
//

#ifndef SDL2_E_TEXTUREMANAGER_H
#define SDL2_E_TEXTUREMANAGER_H

#include "SDL_image.h"
#include <map>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

class TextureManager
{
public:

    //Load textures to OpenGL Texture
    bool load_PNG(const char* imagePath, const char* imageID, int* w = nullptr, int* h = nullptr);

    void deleteFromTextureMap(const char* id);

    GLuint getTexture(const char* id) { return textureMap[id];};

    static TextureManager* instance()
    {
        static TextureManager inst;
        return &inst;
    }

private:
    TextureManager();
    ~TextureManager();

    std::map<const char*, GLuint> textureMap;

};


#endif //SDL2_E_TEXTUREMANAGER_H
