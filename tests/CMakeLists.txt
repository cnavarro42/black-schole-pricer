find_package(GTest REQUIRED)

add_executable(tests_runner
    test_dummy.cpp
)

target_link_libraries(tests_runner
    GTest::gtest
    GTest::gtest_main
)

add_test(NAME DummyTest COMMAND tests_runner)