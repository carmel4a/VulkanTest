#include "Application/Application.hpp"

#include <iostream>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include "glm/glm.hpp"

using VulkanTest::Application::Application;

Application::Application()
        : windowsManager {  } {
    try {
        initGlfw();
        createMainWindow();
        initVulkan();
        mainLoop();
        cleanup();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        throw e;
    }
}

void Application::initGlfw() {
    glfwInit();
}

void Application::createMainWindow() {
    windowsManager.setMainWindow(windowsManager.createWindow());
}

void Application::initVulkan() {
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::cout << extensionCount << " extensions supported" << std::endl;
}

void Application::mainLoop() {
    while (!windowsManager.getWindows().empty()) {
        windowsManager.refresh();
        for (auto& window : windowsManager.getWindows())
            if (window == nullptr || window->shouldClose())
                windowsManager.removeWindow(window);
        glfwPollEvents();
    }
}

void Application::cleanup() {
    windowsManager.removeWindows();
    glfwTerminate();
}
