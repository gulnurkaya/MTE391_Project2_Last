// BufferManager.cpp
#include "BufferManager.h"
#include <iostream>
#include "Vertex.h"

BufferManager::BufferManager(Vertex data[], GLuint dataSize)
{
    GLuint vertexSize = sizeof(Vertex);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Load vertex data
    glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(dataSize) * static_cast<GLsizeiptr>(vertexSize), data, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, (void*)offsetof(Vertex, position));
    glEnableVertexAttribArray(0);

    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, vertexSize, (void*)offsetof(Vertex, color));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void BufferManager::BindVAO()
{
    glBindVertexArray(VAO);
}

void BufferManager::Draw(GLenum primitiveType, GLint first, GLsizei count)
{
    glBindVertexArray(VAO);
    glDrawArrays(primitiveType, first, count);
    glBindVertexArray(0);
}

BufferManager::~BufferManager()
{
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
}
