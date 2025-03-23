#include "planet.h"
#include <cmath>

Planet::Planet(float orbitRadius, float size, float speed, glm::vec3 color)
    : orbitRadius(orbitRadius), size(size), speed(speed), angle(0.0f), color(color) {}

void Planet::update(float deltaTime) {
    angle += speed * deltaTime;
    if (angle > 2.0f * M_PI) angle -= 2.0f * M_PI;
}

glm::vec2 Planet::getPosition() const {
    return glm::vec2(cos(angle), sin(angle)) * orbitRadius;
}

float Planet::getSize() const {
    return size;
}

glm::vec3 Planet::getColor() const {
    return color;
}