// src/wordlecpp/global_session.cpp
#include <wordlecpp/global_session.hpp>
#include <wordlecpp/information.hpp>
#include <wordlecpp/paths.hpp>
#include <wordlecpp/profile.hpp>

// C++
#include <fstream>

namespace WordleCPP {
    std::unique_ptr<Profile> gs_profile = nullptr;
    json gs_config = { // Стандартный конфиг. Используется только если создается новый config.json. Если config.json есть, то gs_config перезаписывается
        {"version_created", {version_major, version_minor, version_patch}},
        {"version_updated", {version_major, version_minor, version_patch}},
        {"opened_profile", "none"}, // Указывается uuid профиля, который нужно мгновенно открыть
        {"profiles", {}} // Хранилище профилей
    };
    json& gs_config_profiles = gs_config["profiles"];
    void gs_config_init() {
        if(!std::filesystem::exists(pth_config)) {
            if(gs_config_save()) {
                throw std::runtime_error("Не удалось выполнить gs_config_save()");
            }
        }
        gs_config.clear();
        std::ifstream file(pth_config);
        file >> gs_config;
        file.close();
    }
    bool gs_config_save() {
        gs_config["version_updated"] = {version_major, version_minor, version_patch};

        std::ofstream file(pth_config);
        if(!file) {
            return false;
        }
        file << gs_config.dump();
        file.close();
        return true;
    }
};
