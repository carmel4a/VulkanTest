#ifndef WINDOWS_MANAGER__GLFW_WINDOW_HANDLER
#define WINDOWS_MANAGER__GLFW_WINDOW_HANDLER

#include "WindowsManager/IWindowHandler.hpp"

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

namespace VulkanTest::WindowsManager {
    class GlfwWindowHandler : public IWindowHandler<GLFWwindow> {
      public:
        GlfwWindowHandler();
        inline ~GlfwWindowHandler();

        GlfwWindowHandler(const GlfwWindowHandler&) = delete;
        GlfwWindowHandler& operator=(const GlfwWindowHandler&) = delete;

        constexpr inline operator GLFWwindow*() override;
        constexpr inline operator const GLFWwindow* const() const override;

        auto create() -> GLFWwindow* const override;

        constexpr inline auto getWindow() const -> GLFWwindow* const override;
        constexpr inline auto getId() const -> const Id& override;

        inline bool shouldClose() const override;
        void destroy() override;

      private:
        GLFWwindow* window;
        Id m_id;
    };

    GlfwWindowHandler::~GlfwWindowHandler() {
        destroy();
    }

    constexpr GlfwWindowHandler::operator GLFWwindow*() {
        return m_window;
    }

    constexpr GlfwWindowHandler::operator const GLFWwindow* const() const {
        return m_window;
    }

    }

    constexpr auto GlfwWindowHandler::getWindow() const -> GLFWwindow* const {
        return m_window;
    }

    constexpr auto GlfwWindowHandler::getId() const -> const Id& {
        return m_id;
    }

    bool GlfwWindowHandler::shouldClose() const {
        return (bool) glfwWindowShouldClose(m_window);
    }
}

#endif // !WINDOWS_MANAGER__GLFW_WINDOW_HANDLER
