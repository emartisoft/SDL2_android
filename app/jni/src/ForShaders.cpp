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

const char* ForShaders::readShader(const char* filename)
{
    FILE* infile = fopen(filename, "rb");

    if (!infile)
    {
        SDL_Log("ForShaders::readShader unable to open file :%s", filename);
        return NULL;
    }

    fseek(infile, 0, SEEK_END);
    long len = ftell(infile);
    fseek(infile, 0, SEEK_SET);

    char* source = new char[len + 1];

    fread(source, 1, len, infile);
    fclose(infile);

    source[len] = 0;

    return const_cast<const GLchar*>(source);
}

GLuint ForShaders::makeProgram(const char* vertex, const char* fragment)
{
    const char* vertexShaderCode = readShader(vertex);
    SDL_Log("vertexShaderCode = %s", vertexShaderCode);
    const char* fragmentShaderCode = readShader(fragment);
    SDL_Log("fragmentShaderCode = %s", fragmentShaderCode);

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
#ifdef DEBUG
    GLint compiled;
	glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &compiled); // проверка того что скомпилировалось
	if (compiled == GL_FALSE) {
		GLsizei len;
		glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &len); // с - GL_INFO_LOG_LENGTH - вернет размер ошибки

		GLchar* log = new GLchar[len + 1]; // для журнала к котором будет ошибка
		glGetShaderInfoLog(vertexShaderID, len, &len, log); // заполнит журнал сообщением об ошибке
		std::cout << "Vertex Shader compilation failed: " << log << std::endl;
		delete[] log;
	}
	//else { std::cout << "Vertex Shader compiled " << std::endl; }
#endif // DEBUG

    glCompileShader(fragmentShaderID);
#ifdef DEBUG
    glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &compiled); // проверка того что скомпилировалось
	if (compiled == GL_FALSE) {
		GLsizei len;
		glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &len); // с - GL_INFO_LOG_LENGTH - вернет размер ошибки

		GLchar* log = new GLchar[len + 1]; // для журнала к котором будет ошибка
		glGetShaderInfoLog(fragmentShaderID, len, &len, log); // заполнит журнал сообщением об ошибке
		std::cout << "Fragment Shader compilation failed: " << log << std::endl;
		delete[] log;
	}
	//else { std::cout << "Fragment Shader compiled " << std::endl; }
#endif // DEBUG

    GLuint programID = glCreateProgram();
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);

    glLinkProgram(programID);
#ifdef DEBUG
    GLint linked;
	glGetProgramiv(programID, GL_LINK_STATUS, &linked);
	if (linked == GL_FALSE)
	{
		GLsizei len;
		glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &len);

		GLchar* log = new GLchar[len + 1];
		glGetProgramInfoLog(programID, len, &len, log);
		std::cerr << "glLinkProgram(programID) failed: " << log << std::endl;
		delete[] log;
	}
#endif // DEBUG
    glDetachShader(programID, vertexShaderID);
    glDetachShader(programID, fragmentShaderID);

    return programID;

}