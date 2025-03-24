#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "planet.h"
#include "renderer.h"


#define SCALE 1.0f / 1e6f

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

    GLFWwindow* window = glfwCreateWindow(1920, 720, "2D Solar System", nullptr, nullptr);
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

    Renderer renderer(window);
    float timeLast = glfwGetTime();
    
    std::vector<Planet> planets;

    // ☀️ Sonne (steht still)
    planets.emplace_back(0.0f * SCALE, 1.39e6f * SCALE, 0.0f, glm::vec3(1.0f, 0.9f, 0.3f)); // radius = 1.39 Mio km
    
    // 🌍 Erde (dreht sich langsam um die Sonne)
    planets.emplace_back(14.96e6f * SCALE, 1.2742e6f * SCALE, 0.5f, glm::vec3(0.0f, 1.0f, 0.0f)); // 149.6 Mio km Entfernung, 12.742 km Größe
    
    while (!glfwWindowShouldClose(window)) {
        float timeNow = glfwGetTime();
        float deltaTime = timeNow - timeLast;
        timeLast = timeNow;
        std::cout << "Erde bei: " << planets[1].getPosition().x << ", " << planets[1].getPosition().y << std::endl;
        glClear(GL_COLOR_BUFFER_BIT);

        for (Planet& planet : planets) {
            planet.update(deltaTime);
            renderer.drawCircle(planet.getPosition(), planet.getSize(), planet.getColor());
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}