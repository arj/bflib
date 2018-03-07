#include <gtest/gtest.h>
#include <bflib/math/interval.h>
#include <stdexcept>

TEST(Interval, CtorLeftRight) {
    bflib::Interval<int> i(-60, 100);

    ASSERT_EQ(-60, i.left());
    ASSERT_EQ(100, i.right());

    ASSERT_NO_THROW(bflib::Interval<int> j(0,0));
}

TEST(Interval, CtorEmptyValid) {
    ASSERT_NO_THROW(bflib::Interval<int> j(0,0));
}

TEST(Interval, CtorInvalid) {
    ASSERT_THROW(bflib::Interval<int>(100,10), std::invalid_argument);
}

TEST(Interval, ContainsValue) {
    bflib::Interval<int> i(-60, 100);

    ASSERT_TRUE(i.contains(-60));
    ASSERT_TRUE(i.contains(0));
    ASSERT_TRUE(i.contains(10));
    ASSERT_TRUE(i.contains(100));

    ASSERT_FALSE(i.contains(-61));
    ASSERT_FALSE(i.contains(101));
}

TEST(Interval, ContainsInterval) {
    bflib::Interval<int> i(-60, 100);

    ASSERT_TRUE(i.contains(bflib::Interval<int>(-59,99)));
    ASSERT_TRUE(i.contains(bflib::Interval<int>(0,0)));

    ASSERT_FALSE(i.contains(bflib::Interval<int>(-61,0)));
    ASSERT_FALSE(i.contains(bflib::Interval<int>(0,101)));

    ASSERT_FALSE(i.contains(bflib::Interval<int>(-200,600)));
}

TEST(Interval, Overlaps) {
    bflib::Interval<int> i(-60, 100);

    ASSERT_TRUE(i.overlaps(bflib::Interval<int>(-59,99)));
    ASSERT_TRUE(i.overlaps(bflib::Interval<int>(0,0)));

    ASSERT_TRUE(i.overlaps(bflib::Interval<int>(-61,0)));
    ASSERT_TRUE(i.overlaps(bflib::Interval<int>(0,101)));

    ASSERT_FALSE(i.overlaps(bflib::Interval<int>(-200,600)));
}