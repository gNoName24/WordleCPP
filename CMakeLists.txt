cmake_minimum_required(VERSION 3.24)
project(wordlecpp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

function(project_message msg_type msg_text)
    message(${msg_type} "[InitTools] ${msg_text}")
endfunction()

project_message(STATUS "Library: JSON (nlohmann)")
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG        55f93686c01528224f448c19128836e7df245f72 # v3.12.0
)
FetchContent_MakeAvailable(nlohmann_json)

project_message(STATUS "Collecting all .cpp files into wordlecpp_sources")
file(GLOB_RECURSE wordlecpp_sources "src/wordlecpp/*.cpp")

add_executable(wordlecpp
    main.cpp
    ${wordlecpp_sources}
)
target_include_directories(wordlecpp PRIVATE include)
target_link_libraries(wordlecpp PRIVATE nlohmann_json::nlohmann_json)

install(TARGETS wordlecpp RUNTIME DESTINATION bin)
