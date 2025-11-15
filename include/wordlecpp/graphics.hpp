// include/wordlecpp/graphics.hpp
#ifndef WORDLECPP_GRAPHICS_HPP
#define WORDLECPP_GRAPHICS_HPP

// C++
#include <unordered_map>

// LIBS
#include <notcurses/notcurses.h>

namespace WordleCPP {
    namespace Graphics {
        /*
         * SCENE_PROFILE_ENTRY - Начальное меню для создания аккаунта и входа в него.
         *      SCENE_PROFILE_REGISTER - Регистрация нового аккаунта
         *      SCENE_PROFILE_LOGIN - Ручной вход в аккаунт
         * SCENE_MENU - Основное меню игры
         */
        enum Scene {
            SCENE_PROFILE_ENTRY, SCENE_PROFILE_REGISTER, SCENE_PROFILE_LOGIN,
            SCENE_MENU
        };
        extern Scene scene;
        extern std::unordered_map<Scene, struct ncplane*> scenes;

        // notcurses
        extern struct notcurses* nc;
        extern struct ncplane* ncmp; // notcurses main plane

        void init();
        void shutdown();
    };
};

#endif // WORDLECPP_GRAPHICS_HPP
