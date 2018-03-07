#include <gtest/gtest.h>
#include <bflib/2d/bounding_box_2d.h>
#include <stdexcept>

TEST(BoundingBox2d, CtorValues) {
    bflib::BoundingBox2D<int> bbox(0,1,10,20);

    ASSERT_EQ(0, bbox.left());
    ASSERT_EQ(10, bbox.right());
    ASSERT_EQ(1, bbox.top());
    ASSERT_EQ(20, bbox.bottom());

    ASSERT_NO_THROW(bflib::BoundingBox2D<int> j(0,0,0,0));
}

TEST(BoundingBox2d, ContainsPoint) {
    bflib::BoundingBox2D<int> bbox(10,20,30,40);

    ASSERT_TRUE(bbox.contains(10,20));
    ASSERT_TRUE(bbox.contains(10,40));
    ASSERT_TRUE(bbox.contains(20,30));
    ASSERT_TRUE(bbox.contains(30,40));

    ASSERT_TRUE(bbox.contains(20,30));

    ASSERT_FALSE(bbox.contains(9,30));
    ASSERT_FALSE(bbox.contains(31,30));

    ASSERT_FALSE(bbox.contains(20,19));
    ASSERT_FALSE(bbox.contains(20,41));

    ASSERT_FALSE(bbox.contains(9,41));
}