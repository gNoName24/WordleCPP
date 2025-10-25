#include <wordlecpp/WordleCPP.hpp>

int main(int argc, char **argv) {
    WordleCPP::pth_check();
    WordleCPP::gs_config_init();
    WordleCPP::profile_init();

    WordleCPP::shutdown();
    return 0;
}
