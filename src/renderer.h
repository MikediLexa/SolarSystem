#ifndef RENDERER_H
#define RENDERER_H

#include <glad/gl.h>
#include <glm/glm.hpp>
#include <vector>

class Renderer {
public:
    Renderer();
    ~Renderer();
    void drawCircle(glm::vec2 pos, float radius, glm::vec3 color);

private:
    unsigned int vao, vbo;
    unsigned int shaderProgram;
    std::vector<float> circleVertices;

    void initCircleGeometry(int segments);
    unsigned int loadShader(const char* vertPath, const char* fragPath);
};

#endif