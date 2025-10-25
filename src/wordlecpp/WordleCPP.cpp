#include <wordlecpp/WordleCPP.hpp>

namespace WordleCPP {
    std::random_device rd;
    std::mt19937 gen(rd());
    uuids::uuid_random_generator uuid_gen{&gen};

    uint8_t version_major = 0;
    uint8_t version_minor = 1;
    uint8_t version_patch = 0;

    void profile_init() {
        if(gs_config["opened_profile"] == "none") {
            profile_open();
            return;
        }
        profile_open(gs_config["opened_profile"]);
    }
    void profile_open(const std::string& uuid) {
        Profile profile(uuid);
        gs_profile = std::make_unique<Profile>(std::move(profile));
        gs_profile->initby_uuid();
    }

    void profile_open() { // NOTE: Переделать под ncurses
        bool mode;
        std::cout << "0/1 ; 0 - login, 1 - register\n> ";
        std::cin >> mode;

        if(mode == false) { // login
            profile_login();
        } else { // register
            profile_register();
        }
    }
    void profile_login() {
        std::string regbuf_nickname;
        std::cout << "nickname: ";
        std::cin >> regbuf_nickname;

        gs_config_init();

        if(!gs_config_profiles.contains(regbuf_nickname)) {
            throw std::runtime_error("Профиль " + regbuf_nickname + " не существует");
        }

        gs_config["opened_profile"] = gs_config_profiles[regbuf_nickname];
        gs_config_save();

        profile_open(gs_config_profiles[regbuf_nickname]);
    }
    void profile_register() {
        std::string regbuf_nickname;
        std::cout << "nickname: ";
        std::cin >> regbuf_nickname;

        gs_config_init();

        if(gs_config_profiles.contains(regbuf_nickname)) {
            throw std::runtime_error("Профиль " + regbuf_nickname + " уже есть");
        }

        uuids::uuid newuuid = uuid_gen();
        Profile newprofile(uuids::to_string(newuuid));
        newprofile.nickname = regbuf_nickname;
        newprofile.save();
        newprofile.session_unlock();

        gs_config_profiles[regbuf_nickname] = newprofile.uuidstr;
        gs_config["opened_profile"] = newprofile.uuidstr;

        gs_config_save();

        profile_open(gs_config["opened_profile"]);
    }

    void shutdown() {
        if(gs_profile) {
            gs_profile->session_unlock();
        }
        gs_profile.reset();
    }
};
