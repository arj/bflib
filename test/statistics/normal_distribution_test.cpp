#include <gtest/gtest.h>
#include <bflib/statistics/normal_distribution.h>
#include <stdexcept>
#include <random>

TEST(Statistics, StandardNormalDistribution) {

    auto snd = bf::normal_distribution::standard();
    ASSERT_DOUBLE_EQ(0.0, snd.mean());
    ASSERT_DOUBLE_EQ(1.0, snd.standard_deviation());
    ASSERT_DOUBLE_EQ(1.0, snd.variance());

    ASSERT_DOUBLE_EQ(0.3989422804014327, snd.probability_density(0.0));
    ASSERT_DOUBLE_EQ(0.5, snd.cumulative_density(0.0));
}

TEST(Statistics, NormalDistribution) {

    auto nd = bf::normal_distribution(2.5, 9.0);

    ASSERT_DOUBLE_EQ(2.5, nd.mean());
    ASSERT_DOUBLE_EQ(3.0, nd.standard_deviation());
    ASSERT_DOUBLE_EQ(9.0, nd.variance());

    ASSERT_DOUBLE_EQ(0.093970625136767516, nd.probability_density(0.0));
    ASSERT_DOUBLE_EQ(0.5, nd.cumulative_density(0.0));
}

TEST(Statistics, NormalDistributionEstimation) {

    auto nd = bf::normal_distribution(0.0, 1.0);

    std::vector<double> data;

    for (double value = -1.0; value <= 1.0; value += 0.1) {
        data.push_back(value);
    }

    auto estimated = bf::normal_distribution::ml_estimation(data);

    ASSERT_NEAR(0.0, estimated.mean(), 0.0000000001);
    ASSERT_NEAR(0.6, estimated.standard_deviation(), 0.01);
    ASSERT_NEAR(0.6*0.6, estimated.variance(), 0.01);

    ASSERT_DOUBLE_EQ(0.5, nd.cumulative_density(0.0));
}

TEST(Statistics, NormalDistributionEstimation2) {

    std::vector<double> data;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d;

    for (int i=0; i<10000; ++i) {
        data.push_back(d(gen));
    }

    auto estimated = bf::normal_distribution::ml_estimation(data);

    ASSERT_NEAR(0.0, estimated.mean(), 0.01);
    ASSERT_NEAR(1.0, estimated.standard_deviation(), 0.01);
    ASSERT_NEAR(1.0, estimated.variance(), 0.01);

    ASSERT_DOUBLE_EQ(0.5, estimated.cumulative_density(0.0));
}

TEST(Statistics, NormalDistributionEstimation3) {

    std::vector<double> data {487, 650, 582, 714, 1041, 862, 647, 836, 575, 802 };

    auto estimated = bf::normal_distribution::ml_estimation(data);

    ASSERT_NEAR(719.6, estimated.mean(), 0.01);
    ASSERT_NEAR(24800.64, estimated.variance(), 0.01);
}
