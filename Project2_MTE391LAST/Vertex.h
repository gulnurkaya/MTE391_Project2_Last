#pragma once
#include <SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
class Vertex
{
public:
    glm::vec3 position;
    glm::vec3 color;

    // Özel bir yapýlandýrýcý ekleyin
    Vertex(glm::vec3 pos = glm::vec3(0.0f), glm::vec3 col = glm::vec3(0.0f))
        : position(pos), color(col) {}
};


