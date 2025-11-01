// src/wordlecpp/profile.cpp
#include <wordlecpp/profile.hpp>
#include <wordlecpp/paths.hpp>

// C++
#include <fstream>

namespace WordleCPP {
    void Profile::save() {
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
    bool Profile::session_lock() {
        if(session_lock_check()) {
            return false;
        }
        std::ofstream sessionlock(pth_sessionlock / uuidstr);
        sessionlock.close();
        return true;
    }
    void Profile::session_unlock() {
        if(!session_lock_check()) return;
        std::filesystem::remove(pth_sessionlock / uuidstr);
    }
    bool Profile::session_lock_check() {
        return std::filesystem::exists(pth_sessionlock / uuidstr);
    }
};
