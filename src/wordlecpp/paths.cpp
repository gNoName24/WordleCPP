// src/wordlecpp/paths.cpp
#include <wordlecpp/paths.hpp>

namespace WordleCPP {
    std::filesystem::path pth_resources = "resources";
    std::filesystem::path pth_config = pth_resources / "config.json";
    std::filesystem::path pth_sessionlock = pth_resources / "sessionlocks";
    std::filesystem::path pth_profiles = pth_resources / "profiles";

    void pth_check() {
        std::filesystem::create_directories(pth_resources);
        std::filesystem::create_directories(pth_sessionlock);
        std::filesystem::create_directories(pth_profiles);
    }
};
