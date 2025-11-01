// include/wordlecpp/global_session.hpp
#ifndef WORDLECPP_GLOBAL_SESSION_HPP
#define WORDLECPP_GLOBAL_SESSION_HPP

// C++
#include <memory> // std::unique_ptr

// LIBS
#include <nlohmann/json.hpp> // nlohmann::json
using json = nlohmann::json;

namespace WordleCPP {
    struct Profile;
    extern std::unique_ptr<Profile> gs_profile;
    extern json gs_config;
    extern json& gs_config_profiles;
    void gs_config_init();
    bool gs_config_save();
};

#endif // WORDLECPP_GLOBAL_SESSION_HPP
