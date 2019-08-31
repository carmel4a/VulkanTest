#ifndef WINDOWS_MANAGER__GLFW_WINDOW_HANDLER
#define WINDOWS_MANAGER__GLFW_WINDOW_HANDLER

#include "WindowsManager/WindowHandlerInterface.hpp"

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

namespace VulkanTest::WindowsManager {
    class GlfwWindowHandler : public WindowHandlerInterface<GLFWwindow> {
      public:
        GlfwWindowHandler()
                : window { nullptr }
                , m_id {} {
            create();
        }

        auto create() -> GLFWwindow* const override {
            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
            glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
            window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, 
                    nullptr);
            return window;
        }

        auto getWindow() const -> GLFWwindow* const override {
            return window;
        }

        operator GLFWwindow*() override {
            return window;
        }

        operator const GLFWwindow* const() const override {
            return window;
        }

        const Id& getId() const override {
            return m_id;
        }

        bool shouldClose() const override {
            return (bool) glfwWindowShouldClose(window);
        }

        void destroy() override {
            glfwDestroyWindow(window);
            window = nullptr;
        }

        ~GlfwWindowHandler() {
            destroy();
        }

      private:
        GLFWwindow* window;
        Id m_id;
    };
}

#endif // !WINDOWS_MANAGER__GLFW_WINDOW_HANDLER
