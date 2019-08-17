#include <iostream>

#include "glm/glm.hpp"

int main() {
    std::cout << "Hello!" << std::endl;
    glm::vec2 v1 = glm::vec2();
    v1.x = 1;
    v1.y = 3;
    v1.y += 3;
    std::cout << v1.length() << std::endl;
    return 0;
}
