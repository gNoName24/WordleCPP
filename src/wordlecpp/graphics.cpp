// src/wordlecpp/graphics.cpp
#include <wordlecpp/graphics.hpp>

#include <locale>
#include <math.h>
#include <iostream>

namespace WordleCPP {
    namespace Graphics {
        Scene scene = SCENE_PROFILE;

        // notcurses
        struct notcurses* nc = nullptr;

        void init() {
            setlocale(LC_ALL, "");
            nc = notcurses_init(nullptr, stdout);

            ncvisual* ncv = ncvisual_from_file("image.jpg");

            struct ncvisual_options vopts{};
            vopts.n = notcurses_stdplane(nc);
            vopts.scaling = NCSCALE_SCALE;
            vopts.blitter = NCBLIT_DEFAULT;

            ncplane* n = ncvisual_blit(nc, ncv, &vopts);
            notcurses_render(nc);

            notcurses_get_blocking(nc, nullptr);

            ncvisual_destroy(ncv);
            notcurses_stop(nc);
            nc = nullptr;
        }
    };
};
