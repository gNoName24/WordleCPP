#include <wordlecpp/WordleCPP.hpp>

#include <fstream>

namespace WordleCPP {
    std::unique_ptr<Profile> gs_profile = nullptr;
    json gs_config = { // Стандартный конфиг. Используется только если создается новый config.json. Если config.json есть, то gs_config перезаписывается
        {"version_created", {version_major, version_minor, version_patch}},
        {"opened_profile", "none"},
        {"profiles", {}} // Хранилище профилей
    };
    void gs_config_init() {
        if(!std::filesystem::exists(pth_config)) {
            std::filesystem::create_directories(pth_config.parent_path());
            gs_config_save();
        }
        gs_config.clear();
        std::ifstream file(pth_config);
        file >> gs_config;
        file.close();
    }
    void gs_config_save() {
        std::ofstream file(pth_config);
        if(!file) {
            throw std::runtime_error("Не удалось создать " + pth_config.string());
        }
        file << gs_config.dump();
        file.close();
    }
};
