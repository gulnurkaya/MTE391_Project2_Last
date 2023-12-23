// BufferManager.h
#pragma once
#include <SDL.h>
#include <GL/glew.h>
#include "Vertex.h"

class BufferManager
{
private:
    GLuint VAO;
    GLuint VBO;

public:
    BufferManager(Vertex data[], GLuint dataSize);
    ~BufferManager();
    void BindVAO();
    void Draw(GLenum primitiveType, GLint first, GLsizei count);
};
