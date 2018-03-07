#include <gtest/gtest.h>
#include <bflib/container/tree.h>
#include <bflib/container/tree.hpp>
#include <stdexcept>

TEST(Tree, CtorAndValue) {
    auto t = bflib::tree<int>::make_tree(1);

    const auto& const_t = t;

    ASSERT_EQ(1, t->value());
    ASSERT_EQ(1, const_t->value());
}

TEST(Tree, SetAValueThroughReference) {
    auto t = bflib::tree<int>::make_tree(1);

    t->value() = 2;

    ASSERT_EQ(2, t->value());
}

TEST(Tree, ChildrenTest) {
    auto t = bflib::tree<int>::make_tree(1);

    ASSERT_EQ(0u, t->children().size());

    auto t11 = t->add_child(11);
    auto t12 = t->add_child(12);

    std::vector<std::reference_wrapper<bflib::tree<int>>> children = t->children();

    ASSERT_EQ(2u, t->children().size());
    ASSERT_EQ(11, t->children().at(0).get().value());
    ASSERT_EQ(12, t->children().at(1).get().value());
}

TEST(Tree, LeafTest) {
    auto t = bflib::tree<int>::make_tree(1);

    auto t_child = t->add_child(11);

    ASSERT_FALSE(t->is_leaf());
    ASSERT_TRUE(t_child->is_leaf());
}

TEST(Tree, PathTest) {
    auto t = bflib::tree<int>::make_tree(1);

    auto t_child = t->add_child(11);

    ASSERT_EQ(t->get({})->value(), t->value());
    ASSERT_EQ(t->get({0})->value(), t_child->value());
}

TEST(Tree, InvalidPathTest) {
    auto t = bflib::tree<int>::make_tree(1);

    auto t_child = t->add_child(11);

    ASSERT_THROW(t->get({1})->value(), std::invalid_argument);
}

TEST(Tree, PointerValueTest) {
    int i = 1;

    auto t = bflib::tree<int*>::make_tree(&i);

    ASSERT_EQ(i, *t->value());

    i = 2;

    ASSERT_EQ(i, *t->value());
}

TEST(Tree, SettingValueTest) {
    auto t = bflib::tree<int>::make_tree(1);

    ASSERT_EQ(1, t->value());

    t->value() = 2;

    ASSERT_EQ(2, t->value());
}
