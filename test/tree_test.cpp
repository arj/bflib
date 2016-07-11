#include <gtest/gtest.h>
#include <bflib/tree.h>
#include <bflib/tree.hpp>
#include <stdexcept>

TEST(Tree, CtorAndValue) {
    bf::tree<int> t(1);

    const bf::tree<int>& const_t = t;

    ASSERT_EQ(1, t.value());
    ASSERT_EQ(1, const_t.value());
}

TEST(Tree, SetAValueThroughReference) {
    bf::tree<int> t(1);

    t.value() = 2;

    ASSERT_EQ(2, t.value());
}
