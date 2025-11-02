// src/wordlecpp/graphics.cpp
#include <wordlecpp/graphics.hpp>

namespace WordleCPP {
    namespace Graphics {
        Scene scene = SCENE_PROFILE;

        void init() {
            notcurses_options opts = {0};
            struct notcurses* nc = notcurses_init(&opts, stdout);

            struct ncplane* stdn = notcurses_stdplane(nc);
            ncplane_putstr_yx(stdn, 1, 1, "Hello world! Привет мир!");
            notcurses_render(nc);

            notcurses_get(nc, NULL, NULL);

            notcurses_stop(nc);
        }
    };
};
