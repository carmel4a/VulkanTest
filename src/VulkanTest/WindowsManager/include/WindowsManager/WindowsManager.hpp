#ifndef WINDOWS_MANAGER__WINDOWS_MANAGER
#define WINDOWS_MANAGER__WINDOWS_MANAGER

#include <memory>
#include <list>

#include "WindowsManager/IWindowsManager.hpp"

namespace VulkanTest::WindowsManager {
    template <typename T>
    class WindowsManager : public IWindowsManager<T> {
      public:
        WindowsManager()
            : m_windows { }
            , m_mainWindow { nullptr } {}

        WindowsManager(const WindowsManager&) = delete;
        WindowsManager& operator=(const WindowsManager&) = delete;

        virtual auto createWindow() -> Window<T> override;
        virtual auto getWindow(const Id& id) const -> Window<T> override;
        virtual auto getWindows() -> const std::list<UniqueWindow<T>>& override;

        virtual void setMainWindow(const Window<T> window) override;
        constexpr virtual auto getMainWindow() const -> Window<T> override;

        virtual auto removeWindow(const Id& id) -> bool override;
        virtual auto removeWindows() -> void override;

      protected:
        virtual auto getNewWindow() -> IWindowHandler<T>* const =0;

      private:
        std::list<UniqueWindow<T>> m_windows;
        IWindowHandler<T>* m_mainWindow;
    };

    template <typename T>
    auto WindowsManager<T>::createWindow() -> Window<T> {
        m_windows.emplace_back(nullptr);
        m_windows.back().reset(getNewWindow());
        m_windows.back()->create();
        return m_windows.back().get();
    }

    template <typename T>
    auto WindowsManager<T>::getWindow(const Id& id) const -> Window<T> {
        for (const UniqueWindow<T>& window : m_windows)
            if (window->getId() == id)
                return window.get();
        return nullptr;
    }

    template <typename T>
    auto WindowsManager<T>::getWindows() -> const std::list<UniqueWindow<T>>& {
        return m_windows;
    }

    template <typename T>
    void WindowsManager<T>::setMainWindow(const Window<T> window) {
        m_mainWindow = window;
    }

    template <typename T>
    constexpr auto WindowsManager<T>::getMainWindow() const -> Window<T> {
        return m_mainWindow;
    }

    template <typename T>
    auto WindowsManager<T>::removeWindow(const Id& id) -> bool {
        for (auto window = m_windows.begin(); window != m_windows.end(); ++window)
            if ((*window)->getId() == id) {
                (*window)->destroy();
                m_windows.erase(window);
                return true;
            }
        return false;
    }

    template <typename T>
    void WindowsManager<T>::removeWindows() {
        for (const UniqueWindow<T>& window : m_windows)
            window->destroy();
        m_windows.clear();
    }
}

#endif // !WINDOWS_MANAGER__WINDOWS_MANAGER
