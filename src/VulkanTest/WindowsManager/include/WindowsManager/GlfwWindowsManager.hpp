#ifndef WINDOWS_MANAGER_GLFW_WINDOWS_MANAGER
#define WINDOWS_MANAGER_GLFW_WINDOWS_MANAGER

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

#include "WindowsManager/WindowsManager.hpp"
#include "WindowsManager/GlfwWindowHandler.hpp"

namespace VulkanTest::WindowsManager {
    class GlfwWindowsManager : public WindowsManager<GLFWwindow> {
      public:
      protected:
        virtual auto getNewWindow() -> WindowHandlerInterface<GLFWwindow>* const override;
    };
}

#endif // !WINDOWS_MANAGER_GLFW_WINDOWS_MANAGER
