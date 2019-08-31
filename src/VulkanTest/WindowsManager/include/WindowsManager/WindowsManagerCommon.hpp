#ifndef WINDOWS_MANAGER__WINDOWS_MANAGER_COMMON
#define WINDOWS_MANAGER__WINDOWS_MANAGER_COMMON

#include <memory>
#include <list>
#include <vector>

namespace VulkanTest::WindowsManager {
    template <typename T>
    class IWindowHandler;
    template <typename T>
    using UniqueWindow = std::unique_ptr<IWindowHandler<T>>;
    template <typename T>
    using Window = IWindowHandler<T>* const;

    class Id {
      public:
        Id()
                : id { getNextId() } {}

        explicit Id(unsigned id)
                : id { id } {}

        constexpr inline auto operator==(const Id& rhs) const -> bool {
            return this->id == rhs.id;
        }

        constexpr inline auto getId() const -> unsigned { return id; }

      private:
        auto getNextId() -> unsigned long long {
            static unsigned long long i = 0;
            return ++i;
        }

        const unsigned long long id;
        std::vector<unsigned long long> reservedIds;
    };
}

#endif // !WINDOWS_MANAGER__WINDOWS_MANAGER_COMMON
