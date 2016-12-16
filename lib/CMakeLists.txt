set(TARGET bflib)

set(HEADERS
    include/bflib/algorithms/algorithms.h

    include/bflib/strings/utils.h
    include/bflib/strings/string.h

    include/bflib/container/non_empty_vector.h
    include/bflib/container/graph.h
    include/bflib/container/tree.h
    include/bflib/container/tree.hpp

    include/bflib/contracts.h
    include/bflib/utils.h

    include/bflib/signal_processing/filter.h
    include/bflib/signal_processing/fft.h
)

set(CPP
    src/strings/utils.cpp
    src/strings/string.cpp

    src/signal_processing/filter.cpp
    src/signal_processing/fft.cpp
)

set(SRC ${HEADERS} ${CPP})

add_library(${TARGET} ${SRC})

target_include_directories(${TARGET} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
    $<INSTALL_INTERFACE:include/bflib>
)

install(TARGETS ${TARGET}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)

install(FILES ${HEADERS} DESTINATION include/bflib)
