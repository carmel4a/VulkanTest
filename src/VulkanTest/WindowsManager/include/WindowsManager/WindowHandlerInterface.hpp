#ifndef WINDOWS_MANAGER__WINDOW_HANDLER_INTERFACE
#define WINDOWS_MANAGER__WINDOW_HANDLER_INTERFACE

#include "WindowsManager/WindowsManagerCommon.hpp"

namespace VulkanTest::WindowsManager {
    template<typename rawApiWindowType>
    struct WindowHandlerInterface {
        virtual auto create() -> rawApiWindowType* const =0;
        virtual auto getWindow() const -> rawApiWindowType* const =0;
        virtual operator rawApiWindowType*() =0;
        virtual operator const rawApiWindowType* const() const =0;
        virtual const Id& getId() const =0;
        virtual bool shouldClose() const =0;

        virtual void destroy() =0;
    };
}

#endif // !WINDOWS_MANAGER__WINDOW_HANDLER_INTERFACE
