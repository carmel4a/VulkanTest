#ifndef WINDOWS_MANAGER__WINDOWS_MANAGER_INTERFACE
#define WINDOWS_MANAGER__WINDOWS_MANAGER_INTERFACE

#include <memory>
#include <list>

#include "WindowsManager/WindowsManagerCommon.hpp"
#include "WindowsManager/WindowHandlerInterface.hpp"

namespace VulkanTest::WindowsManager {
    template <typename T>
    struct WindowsManagerInterface {
        virtual auto createWindow() -> Window<T> =0;
        virtual auto getWindow(const Id& id) const -> Window<T> =0;
        virtual auto getWindows() -> const std::list<UniqueWindow<T>>& =0;
        virtual void setMainWindow(const Window<T> window) =0;
        virtual auto getMainWindow() const -> Window<T> =0;
        virtual bool removeWindow(const Id& id) =0;
        virtual void removeWindows() =0;
    };
}

#endif // !WINDOWS_MANAGER__WINDOWS_MANAGER_INTERFACE
