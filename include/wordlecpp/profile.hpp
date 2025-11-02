// include/wordlecpp/profile.hpp
#ifndef WORDLECPP_PROFILE_HPP
#define WORDLECPP_PROFILE_HPP

#include <wordlecpp/paths.hpp>

// C++
#include <string>
#include <filesystem>

// LIBS
#include <uuid.h> // uuids
#include <nlohmann/json.hpp> // nlohmann::json
using json = nlohmann::json;

namespace WordleCPP {
    struct ProfileStorage {
        std::string nickname;

        void parsing(json& json_storage);
        json packing();
    };
    class Profile {
    public:
        Profile(const uuids::uuid& uuid):
        uuid(uuid),
        uuidstr(uuids::to_string(uuid)),
        path(pth_profiles / uuidstr)
        {}
        const uuids::uuid uuid;
        const std::string uuidstr; // Вспомогательно
        const std::filesystem::path path; // Вспомогательно

        // gets
        const ProfileStorage& get_storage() const;

    private:
        ProfileStorage storage;

    };

    void profile_new(const uuids::uuid& uuid, const std::string& nickname);
    void profile_login(const uuids::uuid& uuid);
    /*struct Profile {
        uuids::uuid uuid;
        std::string uuidstr;
        std::string nickname;
        std::filesystem::path path; // pth_profiles + uuidstr

        void save();

        void parse(const json& data);
        json dump();

        // session
        bool session_lock();
        void session_unlock();
        bool session_lock_check();

        Profile(const std::string& uuid) {
            this->uuid = uuids::uuid::from_string(uuid).value();
            uuidstr = uuids::to_string(this->uuid);
            path = pth_profiles / uuidstr;

            session_lock();
        }
        ~Profile() = default;
    };*/
};

#endif // WORDLECPP_PROFILE_HPP
