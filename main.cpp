#include <wordlecpp/wordlecpp.hpp>

#include <iostream>
#include <format>

int main(int argc, char **argv) {
    std::cout << "- WordleCPP";
    std::cout <<
        std::format(" v{}.{}.{}",
            WordleCPP::version.major,
            WordleCPP::version.minor,
            WordleCPP::version.patch
        )
    << std::endl;

    WordleCPP::pathstorage_init();
    WordleCPP::pathstorage.check_required_directories();

    return 0;
}
