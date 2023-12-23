#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <GL/glew.h>

// TextureManager class handles the loading and binding of textures.
class TextureManager {
public:
    // Loads a texture from a file path.
    GLuint LoadTexture(const std::string& texturePath);

    // Binds a texture for rendering.
    void UseTexture(GLuint textureId);

    // Deletes a texture to free resources.
    void DeleteTexture(GLuint textureId);
};

#endif // TEXTUREMANAGER_H

