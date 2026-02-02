add_executable(tests_runner
    test_dummy.cpp
    test_pricer.cpp
)

target_include_directories(tests_runner
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)


target_link_libraries(tests_runner
    GTest::gtest
    GTest::gtest_main
)

add_test(NAME AllTests COMMAND tests_runner)
