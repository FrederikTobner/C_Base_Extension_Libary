#C++ 14 needed for Google Test Framework
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(TEST_PROJ_NAME ${PROJECT_NAME}Tests)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)


set(TEST_SOURCES
sha256.cc
fnv1a.cc
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(${TEST_PROJ_NAME} ${TEST_SOURCES})

# Links text executable, googletest and the blockchain-libary
target_link_libraries(${TEST_PROJ_NAME} GTest::gtest_main ${PROJECT_NAME})

# For shorter includes
target_include_directories(${TEST_PROJ_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/src")

include(googletest)
# discovers test cases automatically
gtest_discover_tests(${TEST_PROJ_NAME})