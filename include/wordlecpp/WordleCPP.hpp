#ifndef WORDLECPP_HPP
#define WORDLECPP_HPP

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <filesystem>

namespace WordleCPP {
    namespace WordsStorage {
        extern std::string target_language;
        extern std::filesystem::path target_path;

        extern std::unordered_map<std::string, std::vector<std::string>> list;
        extern std::vector<std::string> current_list;
        void list_load(std::filesystem::path& path, std::string& target_language);

        void target_language_change(std::string new_target_language);

        void setup();
    }
};

#endif // WORDLECPP_HPP
