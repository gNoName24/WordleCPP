cmake_minimum_required(VERSION 3.24)
project(wordlecpp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

function(project_message msg_type msg_text)
    message(${msg_type} "[WordleCPP] ${msg_text}")
endfunction()

project_message(STATUS "Library: JSON (nlohmann)")
# https://github.com/nlohmann/json
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG        55f93686c01528224f448c19128836e7df245f72 # v3.12.0
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(nlohmann_json)

project_message(STATUS "Library: uuid_v4 (crashoz)")
# https://github.com/crashoz/uuid_v4
find_package(uuid_v4)
if(uuid_v4_FOUND)
    project_message(STATUS "uuid_v4 library found")
else()
    project_message(FATAL_ERROR "uuid_v4 library NOT found. https://github.com/crashoz/uuid_v4?tab=readme-ov-file#cmake")
endif()

project_message(STATUS "Collecting all .cpp files into wordlecpp_sources")
file(GLOB_RECURSE wordlecpp_sources "src/wordlecpp/*.cpp")

add_executable(wordlecpp
    main.cpp
    ${wordlecpp_sources}
)
target_include_directories(wordlecpp PRIVATE include)
target_link_libraries(wordlecpp PRIVATE
    nlohmann_json::nlohmann_json
    uuid_v4::uuid_v4
)

install(TARGETS wordlecpp RUNTIME DESTINATION bin)
