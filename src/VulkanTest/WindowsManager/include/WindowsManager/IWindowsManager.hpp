#ifndef WINDOWS_MANAGER__WINDOWS_MANAGER_INTERFACE
#define WINDOWS_MANAGER__WINDOWS_MANAGER_INTERFACE

#include <memory>
#include <list>

#include "WindowsManager/IWindowHandler.hpp"
#include "WindowsManager/WindowsManagerCommon.hpp"

namespace VulkanTest::WindowsManager {
    /// Interface for windows managers.
    /** Single window manager should maintain lifetime of one type of windows.
     *  If user deired to use multiple windows API, should create multiple
     *  implementations of WindowsManagerInterface. Implementation doesn't have
     *  to guarante thread safety of any kind.
     *  @param T - underlaying inner, API dependent type representing single
     *  window. */
    template <typename T>
    struct IWindowsManager {
        /// Gets new instance of window.
        /** Window must have determined lifetime guaranted by implementation. */
        virtual auto createWindow() -> Window<T> =0;

        /// Gets window of given Id.
        /** @param Id - unique id given on window creation time. */
        virtual auto getWindow(const Id& id) const -> Window<T> =0;

        /// Gets not mutable list with existing windows.
        virtual auto getWindows() -> const std::list<UniqueWindow<T>>& =0;

        /// Sets given window as main window.
        virtual void setMainWindow(const Window<T> window) =0;

        /// Gets current main window.
        /** This method should be preffered by user, over @ref getWindow */
        virtual auto getMainWindow() const -> Window<T> =0;

        /// Removes window in forcefull mode.
        virtual bool removeWindow(const Id& id) =0;

        /// Removes all windows in forcefull mode.
        virtual void removeWindows() =0;
    };
}

#endif // !WINDOWS_MANAGER__WINDOWS_MANAGER_INTERFACE
