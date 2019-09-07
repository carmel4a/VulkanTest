#include "WindowsManager/GlfwWindowsManager.hpp"

using ::VulkanTest::WindowsManager::GlfwWindowsManager;

auto GlfwWindowsManager::getNewWindow() -> IWindowHandler<GLFWwindow>* const {
    return new GlfwWindowHandler(m_newWindowSettings.m_hints,
                                 m_newWindowSettings.m_name,
                                 m_newWindowSettings.m_w,
                                 m_newWindowSettings.m_h,
                                 m_newWindowSettings.m_monitor,
                                 m_newWindowSettings.m_share);
}
