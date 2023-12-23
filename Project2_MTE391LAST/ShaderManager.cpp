#include "ShaderManager.h"


ShaderManager::ShaderManager(const GLchar* source1, const GLchar* source2)
    :vertexSource(source1),
    fragmentSource(source2),
    vertexShader(0),
    fragmentShader(0),
    shaderProgram(0)
{
    // Compile and activate shaders
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);


    glUseProgram(shaderProgram);

}

GLuint ShaderManager::getProgramId() { return shaderProgram; }

ShaderManager::~ShaderManager() {

    glDeleteProgram(shaderProgram);

}
void ShaderManager::run() {

    glUseProgram(shaderProgram);


}
