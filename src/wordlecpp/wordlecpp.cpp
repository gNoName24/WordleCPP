#include <wordlecpp/wordlecpp.hpp>

namespace WordleCPP {
    // Версия
    Version version{0, 0, 1};

    // Пути
    Path& PathStorage::operator[](const std::string& key) {
        return paths[key];
    }
    void PathStorage::check_required_directories() {
        for(const std::pair<const std::string, Path>& p : paths) {
            const Path& path = p.second;
            if(path.required_directory) {
                if(!std::filesystem::exists(path.path)) {
                    std::filesystem::create_directories(path.path);
                }
            }
        }
    }
    PathStorage pathstorage;
    void pathstorage_init() {
        pathstorage = PathStorage();
        pathstorage["resources"] = Path(std::filesystem::path("resources"), true);
    }
};
