#pragma once

#include <thread>

namespace Ether::Rt {

    class ProcessContext {
    public:
        ProcessContext() = default;
        ~ProcessContext() = default;

        [[noreturn]] static void enterInnerLoop() {
            while (1) { 
                std::this_thread::sleep_for(std::chrono::milliseconds(10000));
            }
        }
    };

}
