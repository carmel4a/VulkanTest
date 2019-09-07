#ifndef WINDOWS_MANAGER_GLFW_WINDOWS_MANAGER
#define WINDOWS_MANAGER_GLFW_WINDOWS_MANAGER

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

#include "WindowsManager/WindowsManager.hpp"
#include "WindowsManager/GlfwWindowHandler.hpp"

#include<list>

namespace VulkanTest::WindowsManager {
    class GlfwWindowsManager : public WindowsManager<GLFWwindow> {
      public:
        class NewWindowSettings {
            friend GlfwWindowsManager;
          public:
            NewWindowSettings()
                    : m_hints {  }
                    , m_name { "default window" }
                    , m_w { 100 }
                    , m_h { 100 }
                    , m_monitor { nullptr }
                    , m_share { nullptr } {}

            void setGlfwWindowHint(int hint, int value) {
                m_hints.push_back(hint);
                m_hints.push_back(value);
            };

            void setSize(unsigned w, unsigned h) {
                m_w = w;
                m_h = h;
            };

            void setName(std::string name) {
                m_name = name;
            }

            void setMonitor(GLFWmonitor* monitor) {
                m_monitor = monitor;
            }
            void setShare(GLFWwindow* share) {
                m_share = share;
            }

          private:
            std::list<int> m_hints;
            std::string m_name;
            unsigned m_w;
            unsigned m_h;
            GLFWmonitor* m_monitor;
            GLFWwindow* m_share;
        };

        constexpr inline auto getNewWindowSettings() -> NewWindowSettings& {
            return m_newWindowSettings;
        }

      protected:
        virtual auto getNewWindow()
                -> IWindowHandler<GLFWwindow>* const override;

      private:
        NewWindowSettings m_newWindowSettings;
    };
}

#endif // !WINDOWS_MANAGER_GLFW_WINDOWS_MANAGER
