#include <wordlecpp/WordleCPP.hpp>

#include <fstream>

namespace WordleCPP {
    void Profile::initby_uuid() {
        path = pth_profiles / uuids::to_string(uuid);
    }

    // Session Lock
    void Profile::session_lock() {
        if(session_lock_check()) {
            std::cout << "Сессия " << uuids::to_string(uuid) << " уже существует" << std::endl;
            exit(0);
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
