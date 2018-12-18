//
// Created by v on 17.12.2018.
//

#ifndef SDL2_E_FORSHADERS_H
#define SDL2_E_FORSHADERS_H

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <iostream>

class ForShaders
{
public:
    ForShaders();
    ~ForShaders();

    static const GLchar* readShader(const char* filename);

    static GLuint makeProgram(const char* vertex, const char* fragment);
};


#endif //SDL2_E_FORSHADERS_H
