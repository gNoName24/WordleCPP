// include/wordlecpp/paths.hpp
#ifndef WORDLECPP_PATHS_HPP
#define WORDLECPP_PATHS_HPP

// C++
#include <filesystem>

namespace WordleCPP {
    extern std::filesystem::path pth_resources;
    extern std::filesystem::path pth_config;
    extern std::filesystem::path pth_sessionlock;
    extern std::filesystem::path pth_profiles;
    void pth_check();
};

#endif // WORDLECPP_PATHS_HPP
