cmake_minimum_required(VERSION 3.14)
project(crow-one CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify the path to CrowConfig.cmake if necessary
set(CROW_DIR /opt/homebrew/opt/crow/share/cmake/Crow)
find_package(Crow REQUIRED)

include_directories(/opt/homebrew/opt/crow/include)
include_directories(/opt/homebrew/opt/asio/include)

# Add executable
add_executable(crow-one main.cc blockroute/about.cc blockroute/index.cc)

# Link libraries
target_link_libraries(crow-one Crow::Crow)
