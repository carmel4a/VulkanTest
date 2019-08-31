#ifndef APPLICATION__APPLICATION
#define APPLICATION__APPLICATION

#include <string>
#include "WindowsManager/GlfwWindowsManager.hpp"

namespace VulkanTest::Application {

    class Application {
      public:
        Application();

      private:
        void initGlfw();
        void createMainWindow();
        void initVulkan();
        void mainLoop();
        void cleanup();

        ::VulkanTest::WindowsManager::GlfwWindowsManager windowsManager;
    };
}

#endif // !APPLICATION__APPLICATION
