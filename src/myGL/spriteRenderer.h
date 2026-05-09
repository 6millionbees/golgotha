#ifndef sprite_renderer
#define sprite_renderer

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.h"
#include "texture.h"

// Draws the same square FOREVER
class SpriteRenderer
{
public:
    SpriteRenderer(Shader &program);
    ~SpriteRenderer();

    void DrawSprite(
        Texture2D &texture,
        glm::vec2 position,
        glm::vec2 size = glm::vec2(10.0f, 10.0f),
        float rotate = 0.0f,
        glm::vec3 color = glm::vec3(1.0f)
    );
private:
    Shader program;
    unsigned int quadVAO;
    // Initialize data
    void initRenderData();
};

#endif
