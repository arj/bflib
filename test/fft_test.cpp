#include <gtest/gtest.h>
#include <bflib/fft.h>

TEST(FFT, fft) {
    std::valarray<std::complex<double>> inout = {1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0};

    bf::fft(inout);

    std::cout << "Result" << std::endl;
    for (int i=0; i<inout.size(); ++i) {
        std::cout << inout[i] << std::endl;
    }

    std::valarray<std::complex<double>> expected = {
        std::complex<double>(4,0),
        std::complex<double>(1,-2.41421),
        std::complex<double>(0,0),
        std::complex<double>(1,-0.414214),
        std::complex<double>(0,0),
        std::complex<double>(1,0.414214),
        std::complex<double>(0,0),
        std::complex<double>(1,2.41421)
    };

    expected -= inout;

    for (int i=0; i<expected.size(); ++i) {
        ASSERT_LE(std::abs(expected[i]), 0.00001);
    }
}

TEST(FFT, ifft) {
    std::valarray<std::complex<double>> inout = {1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0};

    bf::fft(inout);
    bf::ifft(inout);

    const double EPS = 0.0000001;

    ASSERT_NEAR(std::abs(inout[0]), 1.0, EPS);
    ASSERT_NEAR(std::abs(inout[1]), 1.0, EPS);
    ASSERT_NEAR(std::abs(inout[2]), 1.0, EPS);
    ASSERT_NEAR(std::abs(inout[3]), 1.0, EPS);
    ASSERT_NEAR(std::abs(inout[4]), 0.0, EPS);
    ASSERT_NEAR(std::abs(inout[5]), 0.0, EPS);
    ASSERT_NEAR(std::abs(inout[6]), 0.0, EPS);
    ASSERT_NEAR(std::abs(inout[7]), 0.0, EPS);
}
