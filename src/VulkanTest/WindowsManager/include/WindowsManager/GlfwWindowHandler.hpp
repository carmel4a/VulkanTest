#ifndef WINDOWS_MANAGER__GLFW_WINDOW_HANDLER
#define WINDOWS_MANAGER__GLFW_WINDOW_HANDLER

#include "WindowsManager/IWindowHandler.hpp"

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

namespace VulkanTest::WindowsManager {
    class GlfwWindowHandler : public IWindowHandler<GLFWwindow> {
      public:
        GlfwWindowHandler();
        GlfwWindowHandler(const std::list<int>& hints,
                          const std::string& name,
                          unsigned w,
                          unsigned h,
                          GLFWmonitor* m_monitor,
                          GLFWwindow* m_share);

        inline ~GlfwWindowHandler();

        GlfwWindowHandler(const GlfwWindowHandler&) = delete;
        GlfwWindowHandler& operator=(const GlfwWindowHandler&) = delete;

        constexpr inline operator GLFWwindow*() override;
        constexpr inline operator const GLFWwindow* const() const override;

        constexpr inline auto getWindow() const -> GLFWwindow* const override;
        constexpr inline auto getId() const -> const Id& override;

        inline bool shouldClose() const override;
        void destroy() override;

      private:
        inline auto create(const std::list<int>& hints,
                           const std::string&    name,
                           unsigned              w,
                           unsigned              h,
                           GLFWmonitor*          monitor,
                           GLFWwindow*           share) -> GLFWwindow* const;

        GLFWwindow* m_window;
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

    auto GlfwWindowHandler::create(const std::list<int>& hints,
                                   const std::string& name,
                                   unsigned w,
                                   unsigned h,
                                   GLFWmonitor* monitor,
                                   GLFWwindow* share) -> GLFWwindow* const {
        auto it = hints.begin();
        while (it != hints.end()) {
            int hint = *(it++);
            int value = *(it++);
            glfwWindowHint(hint, value);
        }
        
        return glfwCreateWindow(w, h, name.c_str(), monitor, share);
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
