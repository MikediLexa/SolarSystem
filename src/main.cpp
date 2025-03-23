#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "renderer.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {

    if (!glfwInit()) {
        std::cerr << "GLFW Init failed!" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    GLFWwindow* window = glfwCreateWindow(800, 600, "2D Solar System", nullptr, nullptr);
    if (!window) {
        std::cerr << "Window creation failed!" << std::endl;
        glfwTerminate();
        return -1;
    }
  
    glfwMakeContextCurrent(window);

    if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Basic OpenGL settings
    glClearColor(0.01f, 0.01f, 0.1f, 1.0f);

    Renderer renderer;
    float timeLast = glfwGetTime();

    while (!glfwWindowShouldClose(window)) {
        float timeNow = glfwGetTime();
        float deltaTime = timeNow - timeLast;
        timeLast = timeNow;

        glClear(GL_COLOR_BUFFER_BIT);

        renderer.drawCircle(glm::vec2(0.0f, 0.0f), 0.2f, glm::vec3(1.0f, 0.9f, 0.3f)); // Gelbe Sonne

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}