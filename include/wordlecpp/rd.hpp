// include/wordlecpp/rd.hpp
#ifndef WORDLECPP_RD_HPP
#define WORDLECPP_RD_HPP

// C++
#include <random> // rd, gen

// LIBS
#include <uuid.h> // uuid_gen

namespace WordleCPP {
    extern std::random_device rd;
    extern std::mt19937 gen;
    extern uuids::uuid_random_generator uuid_gen;
};

#endif // WORDLECPP_RD_HPP
