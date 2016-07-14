project(bflib.test)

find_package(GTest)

if (GTEST_FOUND)

    include_directories(${GTEST_INCLUDE_DIRS})

    set (TEST_SOURCE
        test.cpp
        tree_test.cpp
        fft_test.cpp
        )

    add_executable(${PROJECT_NAME} ${TEST_SOURCE})
    target_link_libraries(${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES} bf)

    if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
        find_package (Threads)
        target_link_libraries (${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
    endif()

    add_test(NAME ${PROJECT_NAME}
             COMMAND ${PROJECT_NAME}
    )
endif()
