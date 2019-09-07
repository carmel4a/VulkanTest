#include "WindowsManager/GlfwWindowHandler.hpp"

using VulkanTest::WindowsManager::GlfwWindowHandler;
using VulkanTest::WindowsManager::Id;

GlfwWindowHandler::GlfwWindowHandler()
        : GlfwWindowHandler(std::list<int>(),
                            "Default window name",
                            800, 600,
                            nullptr, nullptr) {}

GlfwWindowHandler::GlfwWindowHandler(const std::list<int>& hints,
                                     const std::string&    name,
                                     unsigned              w,
                                     unsigned              h,
                                     GLFWmonitor*          monitor,
                                     GLFWwindow*           share)
            : m_window { create(hints, name, w, h, monitor, share) }
            , m_id {} {}

void GlfwWindowHandler::destroy() {
    glfwDestroyWindow(m_window);
    m_window = nullptr;
}
