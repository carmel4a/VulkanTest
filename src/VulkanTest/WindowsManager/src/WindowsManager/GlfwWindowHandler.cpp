#include "WindowsManager/GlfwWindowHandler.hpp"

using VulkanTest::WindowsManager::GlfwWindowHandler;
using VulkanTest::WindowsManager::Id;

GlfwWindowHandler::GlfwWindowHandler()
        : window { nullptr }
        , m_id {} {
    create();
}

auto GlfwWindowHandler::create() -> GLFWwindow* const {
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, 
            nullptr);
    return window;
}

void GlfwWindowHandler::destroy() {
    glfwDestroyWindow(window);
    window = nullptr;
}

