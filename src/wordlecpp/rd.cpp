// src/wordlecpp/rd.cpp
#include <wordlecpp/rd.hpp>

namespace WordleCPP {
    std::random_device rd;
    std::mt19937 gen(rd());
    uuids::uuid_random_generator uuid_gen{&gen};
};
