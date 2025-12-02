add_executable(main main/main.cpp)
add_library(main_lib STATIC
    main/CombinationLock.cpp
    main/ProductIdRanges.cpp
)
target_link_libraries(main PRIVATE main_lib)

# BUILD_TESTING variable is created by include(CTest)
# It is set to ON by default
if (BUILD_TESTING)

    add_executable(my_test
        test/CombinationLockTest.cpp
        test/ProductIdRangeTest.cpp
    )

    target_link_libraries(my_test PRIVATE GTest::gtest_main)
    target_link_libraries(my_test PRIVATE main_lib)

    include(GoogleTest)
    # Finds all the Google tests associated with the executable
    gtest_discover_tests(my_test)
endif()
