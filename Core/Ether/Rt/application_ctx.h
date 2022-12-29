#pragma once

#include <memory>

namespace Ether::Rt {

    class ProcessContext {
    public:
        ProcessContext() = default;
        ~ProcessContext() = default;

        [[noreturn]] static void enter_inner_loop() {
            while (true) {}
        }
    };

}
