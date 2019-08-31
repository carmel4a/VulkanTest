#include "WindowsManager/GlfwWindowsManager.hpp"

using ::VulkanTest::WindowsManager::GlfwWindowsManager;

auto GlfwWindowsManager::getNewWindow() -> WindowHandlerInterface<GLFWwindow>* const {
    return new GlfwWindowHandler();
}
