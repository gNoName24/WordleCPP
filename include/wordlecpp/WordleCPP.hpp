#ifndef WORDLECPP_HPP
#define WORDLECPP_HPP

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <filesystem>
#include <random>

#include <uuid_v4/uuid_v4.h> // https://github.com/crashoz/uuid_v4

namespace WordleCPP {
    extern UUIDv4::UUIDGenerator<std::mt19937_64> uuid_generator;

    // Хранилище слов для ОДНОЙ игровой сессии
    struct WordsStorage {
        const std::string language;

        WordsStorage(const std::string& language):
            language(language)
        {}
    };

    // Данные игрока
    struct Player {
        UUIDv4::UUID uuid4 = uuid_generator.getUUID();
        std::string nickname;

        Player() {

        }
    };

    // Игровая сессия
    class GameSession {

    };
};

#endif // WORDLECPP_HPP
