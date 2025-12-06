#ifndef WORDLECPP_HPP
#define WORDLECPP_HPP

#include <cstdint> // uint8_t
#include <iostream> // std::cin, std::cout, std::endl
#include <string> // std::string
#include <format> // std::format
#include <unordered_map> // std::unordered_map
#include <filesystem> // std::filesystem

/*
 * Всё что входит сюда именно в пределах этого .hpp файла
 *  имеет обязательный статус присутствия в остальных .hpp, принадлежащие к этому namespace
 */
namespace WordleCPP {
    // Версия
    struct Version {
        uint8_t major{}; uint8_t minor{}; uint8_t patch{};
    };
    extern Version version; // 0.0.1

    // Пути
    struct Path {
        std::filesystem::path path;
        bool required_directory;

        Path() = default;
        Path(const std::filesystem::path& path, const bool required_directory):
        path(path), required_directory(required_directory) {}
    };
    struct PathStorage {
        std::unordered_map<std::string, Path> paths;
        Path& operator[](const std::string& key); // Поддержка [key]

        void check_required_directories(); // Проверка и создание всех директорий на основе required_directory
    };
    extern PathStorage pathstorage;
    void pathstorage_init();
}

// Дальше .hpp, принадлежащие к этому namespace


#endif // WORDLECPP_HPP
