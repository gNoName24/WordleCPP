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

# INFO
project_message(STATUS "CMAKE_PROJECT_VERSION: ${CMAKE_PROJECT_VERSION}")
project_message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
project_message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
project_message(STATUS "CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID}")

# ===== nlohmann_json ======
project_message(STATUS "Library: JSON (nlohmann)")
# https://github.com/nlohmann/json
# Оригинальный репозиторий весит под 200мб, который каждый раз скачивается довольно долго
# Так что я создал форк репозитория и очистил его. Если он вдруг недоступен, смените на оригинальный репозиторий
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/gNoName24/json-clean.git
    GIT_TAG        v3.12.0c
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(nlohmann_json)

# ===== stduuid ======
project_message(STATUS "Library: stduuid (mariusbancila)")
# https://github.com/mariusbancila/stduuid
FetchContent_Declare(
    stduuid
    GIT_REPOSITORY https://github.com/mariusbancila/stduuid.git
    GIT_TAG        3afe7193facd5d674de709fccc44d5055e144d7a # v1.2.3
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(stduuid)

# ===== notcurses_src ======
project_message(STATUS "Library: notcurses (dankamongmen)")
# https://github.com/dankamongmen/notcurses
find_path(NOTCURSES_INCLUDE_DIR notcurses/notcurses.h
    HINTS /usr/include /usr/local/include
)
find_library(NOTCURSES_LIB notcurses
    HINTS /usr/lib /usr/local/lib
)
find_library(NOTCURSES_CORE_LIB notcurses-core
    HINTS /usr/lib /usr/local/lib
)
find_library(NOTCURSES_PLUSPLUS_LIB notcurses++
    HINTS /usr/lib /usr/local/lib
)
if(NOT NOTCURSES_INCLUDE_DIR OR NOT NOTCURSES_LIB)
    project_message(FATAL_ERROR "Notcurses headers or libraries not found. You can find out how to install it here: https://github.com/dankamongmen/notcurses/blob/master/INSTALL.md")
endif()
project_message(STATUS "Found Notcurses in: ${NOTCURSES_INCLUDE_DIR}")
project_message(STATUS "Libraries: ${NOTCURSES_LIB}, ${NOTCURSES_CORE_LIB}, ${NOTCURSES_PLUSPLUS_LIB}")

project_message(STATUS "Collecting all .cpp files into wordlecpp_sources")
file(GLOB_RECURSE wordlecpp_sources "src/wordlecpp/*.cpp")

add_executable(wordlecpp
    main.cpp
    ${wordlecpp_sources}
)
target_include_directories(wordlecpp PRIVATE
    include
    ${NOTCURSES_INCLUDE_DIR}
)
target_link_libraries(wordlecpp PRIVATE
    nlohmann_json::nlohmann_json
    stduuid
    ${NOTCURSES_LIB}
    ${NOTCURSES_CORE_LIB}
    ${NOTCURSES_PLUSPLUS_LIB}
)

# Для компилятора
# target_compile_options(wordlecpp PRIVATE "-Oz")
target_compile_options(wordlecpp PRIVATE "-fno-rtti")
# target_compile_options(wordlecpp PRIVATE "-flto" "-ffunction-sections" "-fdata-sections" "-fno-exceptions" "-Wl,--gc-sections")
# NOTE: от "-fno-exceptions" у JSON начинается сонный паралич

# install(TARGETS wordlecpp RUNTIME DESTINATION bin)
