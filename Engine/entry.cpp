#include <Ether/Rt/application_ctx.h>

namespace Ether::Engine {
    class MainApplication : public Rt::ProcessContext {
    public:
        MainApplication() = default;
        ~MainApplication() = default;
    };
}

#define APPLICATION_EXPORT extern "C"
#define MAYBE_UNUSED [[maybe_unused]]

namespace Ether::Engine {

    APPLICATION_EXPORT MAYBE_UNUSED int main() {
        auto engine_entry = std::make_unique<MainApplication>();
        engine_entry->enterInnerLoop();
    }

}
