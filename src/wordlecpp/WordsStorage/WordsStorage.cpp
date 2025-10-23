#include <wordlecpp/WordleCPP.hpp>

#include <fstream>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace WordleCPP {
    namespace WordsStorage {
        std::string target_language = "en";
        std::filesystem::path target_path = "resources";

        std::unordered_map<std::string, std::vector<std::string>> list;
        std::vector<std::string> current_list = list[target_language];
        void list_load(std::filesystem::path& path, std::string& target_language) {
            std::filesystem::path path_file = path / ("wrd_" + target_language + ".json");
            std::ifstream file(path_file);

            json buffer_json;
            buffer_json = json::parse(file);
            file.close();

            for(size_t i = 0; i < buffer_json.size(); ++i) {
                current_list.push_back(buffer_json[i]);
            }
        }

        void target_language_change(std::string new_target_language) {
            target_language = new_target_language;
            current_list = list[target_language];
        }

        void setup() {
            list.clear();
            list_load(target_path, target_language);
        }
    }
};
