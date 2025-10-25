cmake_minimum_required(VERSION 3.24)
project(wordlecpp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
include(CheckCXXCompilerFlag)
set(FETCHCONTENT_QUIET FALSE)

function(project_message msg_type msg_text)
    message(${msg_type} "[WordleCPP] ${msg_text}")
endfunction()

project_message(STATUS "Library: JSON (nlohmann)")
# https://github.com/nlohmann/json
# Оригинальный репозиторий весит под 200мб, который каждый раз скачивается довольно долго
# Так что я создал форк репозитория и очистил его. Если он вдруг недоступен, смените на оригинальный репозиторий
#
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/gNoName24/json-clean.git
    GIT_TAG        v3.12.0c
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(nlohmann_json)

project_message(STATUS "Library: stduuid (mariusbancila)")
# https://github.com/mariusbancila/stduuid
FetchContent_Declare(
    stduuid
    GIT_REPOSITORY https://github.com/mariusbancila/stduuid.git
    GIT_TAG        3afe7193facd5d674de709fccc44d5055e144d7a # v1.2.3
)
FetchContent_MakeAvailable(stduuid)

project_message(STATUS "Collecting all .cpp files into wordlecpp_sources")
file(GLOB_RECURSE wordlecpp_sources "src/wordlecpp/*.cpp")

add_executable(wordlecpp
    main.cpp
    ${wordlecpp_sources}
)
target_include_directories(wordlecpp PRIVATE include)
target_link_libraries(wordlecpp PRIVATE
    nlohmann_json::nlohmann_json
    stduuid
)

install(TARGETS wordlecpp RUNTIME DESTINATION bin)
