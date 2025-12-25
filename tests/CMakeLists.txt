cmake_minimum_required(VERSION 3.10)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(tests
  test_shoppingcart.cpp
)
target_link_libraries(tests gtest_main bookstore_core)
target_include_directories(tests PRIVATE ${PROJECT_SOURCE_DIR}/src)
add_test(NAME unit_tests COMMAND tests)
