
#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform {
public:
    Transform(const glm::vec3& position = glm::vec3(0.0f),
        const glm::vec3& rotation = glm::vec3(0.0f),
        const glm::vec3& scale = glm::vec3(1.0f));

    void HandleKeyInput(SDL_Keycode key);
    const glm::mat4 GetModelMatrix();

private:
    void Translate(const glm::vec3& delta);
    void Rotate(float angle, const glm::vec3& axis);
    void Scale(const glm::vec3& delta);

    glm::vec3 position;
    glm::vec3 rotation; // Stored as Euler angles
    glm::vec3 scale;
    glm::mat4 model;
    bool needsUpdate;
    void UpdateModelMatrix();
};

#endif // TRANSFORM_H



