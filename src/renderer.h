#ifndef RENDERER_H
#define RENDERER_H

#include <glad/gl.h>
#include <glm/glm.hpp>
#include <vector>
#include <glfw/glfw3.h>

class Renderer {
public:
    Renderer(GLFWwindow* window);
    ~Renderer();
    void drawCircle(glm::vec2 pos, float radius, glm::vec3 color);
    void setViewSize(float size);

private:
    GLFWwindow* window;
    unsigned int vao, vbo;
    unsigned int shaderProgram;
    std::vector<float> circleVertices;

    void initCircleGeometry(int segments);
    unsigned int loadShader(const char* vertPath, const char* fragPath);
};

#endif