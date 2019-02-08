#include "TextureManager.h"

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{
    for(std::map<const char*, GLuint>::iterator it = textureMap.begin(); it != textureMap.end(); it++)
    {
        glDeleteTextures(1, &it->second);
    }
    textureMap.clear();
}

bool TextureManager::load_PNG(const char* imageID, int* w, int* h)
{
    if (textureMap.find(imageID) != textureMap.end()) return true; // exist

    std::string imagePath = std::string("images/") + std::string(imageID);
    SDL_Surface* surface = IMG_Load(imagePath.c_str());
    if( surface == NULL )
    {
        SDL_Log( "SDL PNG load Error: %s", IMG_GetError());
        return false;
    }

    if (w != nullptr) *w = surface->w;
    if (h != nullptr) *h = surface->h;

    GLuint glTextureID;
    glGenTextures(1, &glTextureID);
    glBindTexture(GL_TEXTURE_2D, glTextureID);

    int pixelFormat = GL_RGB;
    if(surface->format->BytesPerPixel == 4) { pixelFormat = GL_RGBA; }

    glTexImage2D(GL_TEXTURE_2D, 0, pixelFormat, surface->w, surface->h, 0, pixelFormat, GL_UNSIGNED_BYTE, surface->pixels);
    glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);

    textureMap[imageID] = glTextureID; // add in map
    SDL_FreeSurface(surface);

    return true;
}

void TextureManager::deleteFromTextureMap(const char* id)
{
    if((textureMap.find(id) != textureMap.end()))
    {
        glDeleteTextures(1, &textureMap[id]);

        textureMap.erase(id);
    }
}