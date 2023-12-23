
#include "Renderer.h"
#include <cmath>
Renderer::Renderer() {


    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        //return 1;
    }

    // Set OpenGL attributes
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // Create a window
    window = SDL_CreateWindow("OpenGL Triangle", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        //return 1;
    }

    // Create OpenGL context
    glContext = SDL_GL_CreateContext(window);
    if (glContext == nullptr) {
        std::cerr << "SDL_GL_CreateContext Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        // return 1;
    }

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "glewInit Error" << std::endl;
        SDL_GL_DeleteContext(glContext);
        SDL_DestroyWindow(window);
        SDL_Quit();
        // return 1;
    }




}
Renderer::~Renderer() {

    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();

}

SDL_Window* Renderer::getWindow() {

    return window;

}

void Renderer::handleEvents(bool* running, Transform* triangleTransform, Transform* circleTransform) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            *running = false;
        }
        if (event.type == SDL_KEYDOWN) {
            triangleTransform->HandleKeyInput(event.key.keysym.sym);
            circleTransform->HandleKeyInput(event.key.keysym.sym);
        }
    }
}

void Renderer::swap() {

    SDL_GL_SwapWindow(window);
}
