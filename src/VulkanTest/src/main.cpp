#include "Application/Application.hpp"

#include <iostream>
#include <exception>

int main() {
    try {
        VulkanTest::Application::Application();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
