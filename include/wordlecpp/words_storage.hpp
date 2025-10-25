// include/wordlecpp/words_storage.hpp
#ifndef WORDLECPP_WORDS_STORAGE_HPP
#define WORDLECPP_WORDS_STORAGE_HPP

// C++
#include <string>

namespace WordleCPP {
    struct WordsStorage {
        const std::string language;

        WordsStorage(const std::string& language):
        language(language)
        {}
    };
};

#endif // WORDLECPP_WORDS_STORAGE_HPP
