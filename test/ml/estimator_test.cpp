#include <gtest/gtest.h>
#include <bflib/ml/estimator.h>
#include <stdexcept>

TEST(Estimator, NormalDistribution) {
    std::vector<double> data {-5.0, -2.5, 2.5, 5.0};

    ASSERT_DOUBLE_EQ(0.0, bf::normal_distribution::mean_estimator(data));

    std::vector<double> data2 {487, 650, 582, 714, 1041, 862, 647, 836, 575, 802 };

    ASSERT_NEAR(719.6, bf::normal_distribution::mean_estimator(data2), 0.0001);

    // http://www.fernuni-hagen.de/ksw/neuestatistik/content/MOD_30448/html/comp_30453.html
}
