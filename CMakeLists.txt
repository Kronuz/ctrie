cmake_minimum_required(VERSION 3.14)
project(ctrie LANGUAGES CXX)

# Header-only compile-time compressed trie. A correct-but-slower alternative to a perfect
# hash for compile-time string membership; kept mainly as a benchmark contender.
add_library(ctrie INTERFACE)
add_library(ctrie::ctrie ALIAS ctrie)
target_include_directories(ctrie INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(ctrie INTERFACE cxx_std_17)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  enable_testing()
  add_executable(ctrie_test test/test.cc)
  target_link_libraries(ctrie_test PRIVATE ctrie)
  target_compile_options(ctrie_test PRIVATE
    $<$<CXX_COMPILER_ID:Clang,AppleClang>:-Wall -Wextra -Werror -Wgnu-string-literal-operator-template>)
  add_test(NAME ctrie COMMAND ctrie_test)
endif()
