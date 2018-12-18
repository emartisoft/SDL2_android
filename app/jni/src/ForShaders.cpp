//
// Created by v on 17.12.2018.
//

#include "ForShaders.h"
#include "SDL.h"

ForShaders::ForShaders()
{

}

ForShaders::~ForShaders()
{

}

const GLchar* ForShaders::readShader(const char* filename)
{
    SDL_Log("filename = %s", filename);

    FILE* infile = fopen(filename, "rb");

    if (!infile)
    {
        SDL_Log("ForShaders::readShader unable to open file");
        return NULL;
    } else{
        SDL_Log("ForShaders::readShader file was opened");
    }

    fseek(infile, 0, SEEK_END);
    int len = ftell(infile);
    fseek(infile, 0, SEEK_SET);

    GLchar* source = new GLchar[len + 1];

    fread(source, 1, len, infile);
    fclose(infile);

    source[len] = 0;
    SDL_Log("source = %s", source);
    return const_cast<const GLchar*>(source);
}

GLuint ForShaders::makeProgram(const char* vertex, const char* fragment)
{
    const char* vertexShaderCode = readShader(vertex);
    const char* fragmentShaderCode = readShader(fragment);
    //std::cout << vertexShaderCode << std::endl;
    //std::cout << fragmentShaderCode << std::endl;

    SDL_Log("STRING QWE + %i", strlen(fragmentShaderCode));

    GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    //const char* adapter[1];
    //adapter[0] = vertexShaderCode;
    glShaderSource(vertexShaderID, 1, &vertexShaderCode, 0);
    delete[] vertexShaderCode;
    //adapter[0] = fragmentShaderCode;
    glShaderSource(fragmentShaderID, 1, &fragmentShaderCode, 0);
    delete[] fragmentShaderCode;

    glCompileShader(vertexShaderID);

    glCompileShader(fragmentShaderID);

    GLuint programID = glCreateProgram();
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);

    glLinkProgram(programID);

    glDetachShader(programID, vertexShaderID);
    glDetachShader(programID, fragmentShaderID);

    return programID;

}