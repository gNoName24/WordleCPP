// include/wordlecpp/graphics.hpp
#ifndef WORDLECPP_GRAPHICS_HPP
#define WORDLECPP_GRAPHICS_HPP

// C++


// LIBS
#include <notcurses/notcurses.h>

namespace WordleCPP {
    namespace Graphics {
        enum Scene {
            SCENE_PROFILE, SCENE_PROFILE_REGISTER, SCENE_PROFILE_LOGIN,
            SCENE_MENU
        };
        extern Scene scene;

        void init();
    };
};

#endif // WORDLECPP_GRAPHICS_HPP
