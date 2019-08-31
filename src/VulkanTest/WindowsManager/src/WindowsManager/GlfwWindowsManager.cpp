#include "WindowsManager/GlfwWindowsManager.hpp"

using ::VulkanTest::WindowsManager::GlfwWindowsManager;

auto GlfwWindowsManager::getNewWindow() -> IWindowHandler<GLFWwindow>* const {
    return new GlfwWindowHandler();
}
