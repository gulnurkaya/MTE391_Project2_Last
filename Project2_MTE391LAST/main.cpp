#include <SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "ShaderManager.h"
#include "BufferManager.h"
#include "Vertex.h"
#include "Renderer.h"
#include "Transform.h"
#include <glm/gtc/type_ptr.hpp>

// Vertex Shader source code
const GLchar* vertexSource = R"ANYTHING(
   #version 330 core
   layout (location = 0) in vec3 position;
   layout (location = 1) in vec3 color;
   
   uniform vec3 offset; // Uniform variable for position offset
   uniform mat4 model;
   out vec3 Color;

   void main() {
       Color = color;
       gl_Position = model * vec4(position + offset, 1.0); // Apply the offset to the position
   }
)ANYTHING";

// Fragment Shader source code
const GLchar* fragmentSource = R"glsl(
    #version 330 core
    in vec3 Color;
    out vec4 outColor;

    void main() {
        outColor = vec4(Color, 1.0);
    }
)glsl";

int main(int argc, char* argv[]) {

    Vertex triangleVertices[] = {
    Vertex(glm::vec3(-0.25f, -0.25f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)),
    Vertex(glm::vec3(0.25f, -0.25f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
    Vertex(glm::vec3(0.0f, 0.25f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)),
    };

    const int numCircleVertices = 36;
    Vertex circleVertices[numCircleVertices];
    float radius = 0.2f; // radius of the circle

    for (int i = 0; i < numCircleVertices; ++i) {
        float theta = static_cast<float>(i) / static_cast<float>(numCircleVertices) * 2.0f * glm::pi<float>();
        float x = radius * cos(theta);
        float y = radius * sin(theta);
        circleVertices[i] = Vertex(glm::vec3(x, y, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));  // Daire mavi renkte olsun.
    }

    Transform* triangleTransform = new Transform(glm::vec3(0.5f, 0.0f, 0.0f));
    Transform* circleTransform = new Transform(glm::vec3(-0.5f, 0.0f, 0.0f));

    Renderer* renderer = new Renderer();

    // Create a new shader manager from the heap
    ShaderManager* myShader = new ShaderManager(vertexSource, fragmentSource);

    myShader->run();

    BufferManager* triangleBuffer = new BufferManager(triangleVertices, 3);
    BufferManager* circleBuffer = new BufferManager(circleVertices, numCircleVertices);

    // Main loop
    glm::vec3 triangleOffset = glm::vec3(0.5f, 0.0f, 0.0f);  // Üçgenin baþlangýç konumu
    glm::vec3 circleOffset = glm::vec3(-0.5f, 0.0f, 0.0f);    // Dairenin baþlangýç konumu
    float speed = 0.01f; // Hareket hýzý

    bool running = true;
    while (running) {

        renderer->handleEvents(&running, triangleTransform, circleTransform);

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Üçgen hareketi
        GLint modelLoc = glGetUniformLocation(myShader->getProgramId(), "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(triangleTransform->GetModelMatrix()));
        triangleBuffer->BindVAO();
        triangleBuffer->Draw(GL_TRIANGLES, 0, 3);

        // Daire hareketi

        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(circleTransform->GetModelMatrix()));
        circleBuffer->BindVAO();
        circleBuffer->Draw(GL_TRIANGLE_FAN, 0, numCircleVertices);

        renderer->swap();
    }

    // Clean up
    delete myShader;
    delete triangleBuffer;
    delete circleBuffer;
    delete renderer;

    return 0;
}

