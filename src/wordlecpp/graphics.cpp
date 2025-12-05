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
            if(!nc) {
                throw std::runtime_error("Ошибка инициализации Notcurses. Одна из возможных причин - Notcurses не установлен или консоль не поддерживает Notcurses");
                return;
            }
            ncmp = notcurses_stdplane(nc);
            if(!ncmp) {
                throw std::runtime_error("Ошибка получения stdplane");
                return;
            }

            unsigned int rows, cols;
            ncplane_dim_yx(ncmp, &rows, &cols);

            // Создание сцен
            struct ncplane_options newscene_opts = {
                .y = 0, .x = 0,
                .rows = rows, .cols = cols,
            };
            scenes[SCENE_PROFILE_ENTRY] = ncplane_create(ncmp, &newscene_opts);
        }
        void shutdown() {
            notcurses_stop(nc);
            nc = nullptr;
        }
    };
};
