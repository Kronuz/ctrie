cmake_minimum_required(VERSION 3.14)
project(ctrie LANGUAGES CXX)

# Header-only compile-time compressed trie. A correct-but-slower alternative to a perfect
# hash for compile-time string membership; kept mainly as a benchmark contender.
add_library(ctrie INTERFACE)
add_library(ctrie::ctrie ALIAS ctrie)
target_include_directories(ctrie INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(ctrie INTERFACE cxx_std_17)
