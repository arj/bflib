#include <gtest/gtest.h>
#include <bflib/signal_processing/filter.h>
#include <stdexcept>

TEST(Filter, Coefficients) {
    bf::finite_impulse_response_filter f(11u);
}
