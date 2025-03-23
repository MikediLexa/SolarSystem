#ifndef PLANET_H
#define PLANET_H

#include <glm/glm.hpp>

class Planet {
public:
    Planet(float orbitRadius, float size, float speed, glm::vec3 color);

    void update(float deltaTime);
    glm::vec2 getPosition() const;
    float getSize() const;
    glm::vec3 getColor() const;

private:
    float orbitRadius;
    float size;
    float speed; // radians per second
    float angle;
    glm::vec3 color;
};

#endif