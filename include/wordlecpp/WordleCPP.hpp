#ifndef WORDLECPP_HPP
#define WORDLECPP_HPP

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <filesystem>
#include <random>
#include <memory> // std::unique_ptr
#include <cstdint> // u/intx_t

#include <uuid.h> // https://github.com/mariusbancila/stduuid
#include <nlohmann/json.hpp> // https://github.com/nlohmann/json

using json = nlohmann::json;

namespace WordleCPP {
    //extern UUIDv4::UUIDGenerator<std::mt19937_64> uuid_generator;

    // 0.1.0
    extern uint8_t version_major;
    extern uint8_t version_minor;
    extern uint8_t version_patch;

    // Paths - pth_
    extern std::filesystem::path pth_resources;
    extern std::filesystem::path pth_config;
    extern std::filesystem::path pth_sessionlock;
    extern std::filesystem::path pth_profiles;

    // Global Session - gs_
    struct Profile;
    extern std::unique_ptr<Profile> gs_profile;
    extern json gs_config;
    void gs_config_init();
    void gs_config_save();

    // Хранилище слов для ОДНОЙ игровой сессии
    struct WordsStorage {
        const std::string language;

        WordsStorage(const std::string& language):
            language(language)
        {}
    };

    // Список всех существующих аккаунтов
    extern std::unordered_map<std::string, std::string> profiles;

    // Данные игрока
    struct Profile {
        uuids::uuid uuid;
        std::string nickname;
        std::filesystem::path path;

        void initby_uuid();

        // Session Lock
        void session_lock();
        void session_unlock();
        bool session_lock_check();

        Profile(const std::string& uuid) {
            this->uuid = uuids::uuid::from_string(uuid).value();
            initby_uuid();

            session_lock();
        }
        ~Profile() {
            session_unlock();
        }
    };
    void profile_init();

    // Игровая сессия
    class GameSession {

    };
};

#endif // WORDLECPP_HPP
