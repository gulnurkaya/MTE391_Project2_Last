#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <SDL.h>
#include <iostream>
#include "Transform.h"
#include <glm/glm.hpp>

// Renderer class handles the basic rendering operations using OpenGL.
class Renderer {
public:
    Renderer();
    ~Renderer();

    // Initializes the renderer with the SDL window.
    void Initialize(SDL_Window* window);

    // Renders a frame. This is called every loop iteration in the main game loop.
    void RenderFrame();
    void handleEvents(bool* running, Transform* triangleTransform, Transform* circleTransform);
    // Cleans up OpenGL context and resources.
    void Cleanup();
    void swap();
    SDL_Window* getWindow();
private:
    SDL_Window* window;
    SDL_GLContext glContext; // The OpenGL context associated with the SDL window.
};

#endif // RENDERER_H