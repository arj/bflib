#include <gtest/gtest.h>
#include <bflib/2d/line_2d.h>

TEST(Line2d, FromPoints) {
    auto line = bflib::Line2D::from_points(-5,7, 7,-8);

    ASSERT_EQ(-1.25, line.m());
    ASSERT_EQ(0.75, line.b());
}

TEST(Line2d, FromCartesian) {
    auto line = bflib::Line2D::from_cartesian(10, -2);

    ASSERT_EQ(10, line.m());
    ASSERT_EQ(-2, line.b());
}

TEST(Line2d, FromPolar) {
    auto line = bflib::Line2D::from_polar(1, M_PI_4);

    ASSERT_DOUBLE_EQ(-1, line.m());
    ASSERT_DOUBLE_EQ(std::sqrt(2), line.b());
}

TEST(Line2d, Eval) {
    auto line = bflib::Line2D::from_points(-5,7, 7,-8);

    ASSERT_DOUBLE_EQ(7, line.eval(-5));
    ASSERT_DOUBLE_EQ(-5, line.inverse_eval(7));

    ASSERT_DOUBLE_EQ(-8, line.eval(7));
    ASSERT_DOUBLE_EQ(7, line.inverse_eval(-8));
}
