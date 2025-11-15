// src/wordlecpp/graphics.cpp
#include <wordlecpp/graphics.hpp>
#include <wordlecpp/paths.hpp>

// C++
#include <locale>
#include <math.h>
#include <iostream>

namespace WordleCPP {
    namespace Graphics {
        Scene scene = SCENE_PROFILE_ENTRY;
        std::unordered_map<Scene, struct ncplane*> scenes;

        // notcurses
        struct notcurses* nc = nullptr;
        struct ncplane* ncmp = nullptr;

        void init() {
            setlocale(LC_ALL, "");
            nc = notcurses_init(nullptr, stdout);
            ncmp = notcurses_stdplane(nc);

            unsigned int rows, cols;
            ncplane_dim_yx(ncmp, &rows, &cols);

            // Создание сцен
            struct ncplane_options opts_scenes = {
                .y = 0, .x = 0,
                .rows = rows, .cols = cols,
            };
            scenes[SCENE_PROFILE_ENTRY] = ncplane_create(ncmp, &opts_scenes);
        }
        void shutdown() {
            notcurses_stop(nc);
            nc = nullptr;
        }
    };
};
