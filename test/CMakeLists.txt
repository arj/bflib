set(TARGET bflib.test)

find_package(GTest)

if (GTEST_FOUND)


    set(SOURCES
            algorithm/algorithms_test.cpp

            container/graph_test.cpp
            container/tree_test.cpp

            strings/utils_test.cpp

            signal_processing/filter_test.cpp
            signal_processing/fft_test.cpp

            testing/ddmin_test.cpp

            ml/estimator_test.cpp

            statistics/normal_distribution_test.cpp

            main.cpp
            )

    add_executable(${TARGET} ${SOURCES})

    target_include_directories(${TARGET} PRIVATE ${GTEST_INCLUDE_DIRS})

    target_link_libraries(${TARGET}
            bflib
            ${GTEST_BOTH_LIBRARIES})

    if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
        find_package(Threads)
        target_link_libraries(${TARGET} ${CMAKE_THREAD_LIBS_INIT})
    endif ()

    add_test(NAME ${TARGET}
        COMMAND ${TARGET}
    )
ENDIF (GTEST_FOUND)
