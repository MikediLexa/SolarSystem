#include "renderer.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <fstream>
#include <sstream>
#include <iostream>

Renderer::Renderer() {
    initCircleGeometry(100); // 100 Segmente = schöner Kreis

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, circleVertices.size() * sizeof(float), circleVertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    shaderProgram = loadShader("../shaders/basic.vert", "../shaders/basic.frag");
}

Renderer::~Renderer() {
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
    glDeleteProgram(shaderProgram);
}

void Renderer::drawCircle(glm::vec2 pos, float radius, glm::vec3 color) {
    glUseProgram(shaderProgram);
    glBindVertexArray(vao);

    glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(pos, 0.0f));
    model = glm::scale(model, glm::vec3(radius, radius, 1.0f));
    glm::mat4 view = glm::mat4(1.0f); // 2D = keine Kamera
    glm::mat4 proj = glm::ortho(-1.f, 1.f, -1.f, 1.f); // Normiertes Fenster [-1,1]

    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "u_model"), 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "u_view"), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "u_proj"), 1, GL_FALSE, glm::value_ptr(proj));
    glUniform3fv(glGetUniformLocation(shaderProgram, "u_color"), 1, glm::value_ptr(color));

    glDrawArrays(GL_TRIANGLE_FAN, 0, circleVertices.size() / 2);
}

void Renderer::initCircleGeometry(int segments) {
    circleVertices.clear();
    circleVertices.push_back(0.0f); // Zentrum

    for (int i = 0; i <= segments; ++i) {
        float angle = i * 2.0f * 3.1415926f / segments;
        circleVertices.push_back(cos(angle));
        circleVertices.push_back(sin(angle));
    }
}

unsigned int Renderer::loadShader(const char* vertPath, const char* fragPath) {
    std::ifstream vFile(vertPath), fFile(fragPath);
    std::stringstream vStream, fStream;
    vStream << vFile.rdbuf();
    fStream << fFile.rdbuf();
    std::string vCode = vStream.str(), fCode = fStream.str();

    const char* vSrc = vCode.c_str();
    const char* fSrc = fCode.c_str();

    unsigned int vert = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vert, 1, &vSrc, NULL);
    glCompileShader(vert);

    unsigned int frag = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(frag, 1, &fSrc, NULL);
    glCompileShader(frag);

    unsigned int program = glCreateProgram();
    glAttachShader(program, vert);
    glAttachShader(program, frag);
    glLinkProgram(program);

    glDeleteShader(vert);
    glDeleteShader(frag);

    return program;
}