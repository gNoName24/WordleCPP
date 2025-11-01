// src/wordlecpp/debug.cpp
#include <wordlecpp/debug.hpp>
#include <wordlecpp/paths.hpp>

// C++
#include <filesystem>

namespace WordleCPP {
    namespace Debug {
        bool enable = false;
        void check_availability() {
            enable = std::filesystem::exists(WordleCPP::pth_debugchecker);
        }
    };
};
