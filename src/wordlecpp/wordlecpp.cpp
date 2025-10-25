// src/wordlecpp/wordlecpp.cpp
#include <wordlecpp/wordlecpp.hpp>
#include <wordlecpp/global_session.hpp>
#include <wordlecpp/profile.hpp>

namespace WordleCPP {
    void shutdown() {
        if(gs_profile) {
            gs_profile->session_unlock();
        }
        gs_profile.reset();
    }
};
