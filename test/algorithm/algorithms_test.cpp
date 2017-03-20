#include <gtest/gtest.h>

#include <bflib/algorithms/algorithms.h>

#include <list>
#include <set>
#include <unordered_set>
#include <vector>

TEST(SplitVector, DefaultTest) {
    auto v = bflib::split(std::vector<int>{0,0,1,0,0,1,1,0}, std::unordered_set<int>{1});

    std::vector<int> v0 {0,0};
    std::vector<int> v1 {0,0};
    std::vector<int> v2 {};
    std::vector<int> v3 {0};

    ASSERT_EQ(4, v.size());
    ASSERT_TRUE(std::equal(v[0].cbegin(), v[0].cend(), v0.cbegin(), v0.cend()));
    ASSERT_TRUE(std::equal(v[1].cbegin(), v[1].cend(), v1.cbegin(), v1.cend()));
    ASSERT_TRUE(std::equal(v[2].cbegin(), v[2].cend(), v2.cbegin(), v2.cend()));
    ASSERT_TRUE(std::equal(v[3].cbegin(), v[3].cend(), v3.cbegin(), v3.cend()));
}

TEST(Contains, InitializerListTest) {
    ASSERT_TRUE(bflib::contains({0,1,2}, 1));
    ASSERT_FALSE(bflib::contains({0,1,2}, 3));
}

TEST(Contains, VectorTest) {
    std::vector<int> c {0, 1, 2};

    ASSERT_TRUE(bflib::contains(c, 1));
    ASSERT_FALSE(bflib::contains(c, 3));
}

TEST(Contains, SetTest) {
    std::set<int> c {0, 1, 2};

    ASSERT_TRUE(bflib::contains(c, 1));
    ASSERT_FALSE(bflib::contains(c, 3));
}

TEST(Contains, ListTest) {
    std::list<int> c {0, 1, 2};

    ASSERT_TRUE(bflib::contains(c, 1));
    ASSERT_FALSE(bflib::contains(c, 3));
}

TEST(Contains, UnorderedSetTest) {
    std::unordered_set<int> c {0, 1, 2};

    ASSERT_TRUE(bflib::contains(c, 1));
    ASSERT_FALSE(bflib::contains(c, 3));
}

TEST(IsSubset, UnorderedSetTest) {
    std::vector<int> c1 {2, 0};
    std::unordered_set<int> c2 {0, 1, 2};

    ASSERT_TRUE(bflib::is_subset(c1, c2));
    ASSERT_FALSE(bflib::is_subset(c2, c1));
}

TEST(IsSubset, EmptySetTest) {
    std::unordered_set<int> c {0, 1, 2};

    ASSERT_TRUE(bflib::is_subset({}, c));
    ASSERT_FALSE(bflib::is_subset(c, {}));
    ASSERT_TRUE(bflib::is_subset(std::set<int>{}, {}));
}

TEST(Sublist, FullList) {
    std::vector<int> v {0,1,2,3,4,5,6};

    ASSERT_EQ(v, bflib::sublist(v, 0, v.size()));

    for (size_t i=0; i<v.size(); ++i) {
        ASSERT_EQ(std::vector<int> {v[i]}, bflib::sublist(v, i, i+1));
    }

    ASSERT_EQ(std::vector<int>{}, bflib::sublist(v, 5, 5));

    ASSERT_EQ((std::vector<int>{2,3,4}), bflib::sublist(v, 2, 5));
}
