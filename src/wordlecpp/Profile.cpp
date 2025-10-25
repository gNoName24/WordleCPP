#include <wordlecpp/WordleCPP.hpp>

#include <fstream>

namespace WordleCPP {
    void Profile::initby_uuid() {
        if(!std::filesystem::exists(path)) {
            throw std::runtime_error("Профиль по указанному uuid не существует");
        }
    }

    void Profile::save() {
        std::cout << path << std::endl;
        std::ofstream file(path);
        file << dump().dump();
        file.close();
    }

    void Profile::parse(const json& data) {
        nickname = data["nickname"];
    }
    json Profile::dump() {
        json buffer;

        buffer["nickname"] = nickname;

        return buffer;
    }

    // Session Lock
    void Profile::session_lock() {
        if(session_lock_check()) {
            throw std::runtime_error("Сессия " + uuids::to_string(uuid) + " уже существует");
        }
        std::filesystem::create_directories(pth_sessionlock);
        std::ofstream sessionlock(pth_sessionlock / uuids::to_string(uuid));
        sessionlock.close();
    }
    void Profile::session_unlock() {
        if(!session_lock_check()) return;
        std::filesystem::remove(pth_sessionlock / uuids::to_string(uuid));
    }
    bool Profile::session_lock_check() {
        return std::filesystem::exists(pth_sessionlock / uuids::to_string(uuid));
    }
};
