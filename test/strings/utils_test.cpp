#include <gtest/gtest.h>

#include <bflib/strings/utils.h>

TEST(Split, EmptyInputTest) {
    EXPECT_EQ((std::vector<std::string>{""}), bflib::split("", {}));

    EXPECT_EQ((std::vector<std::string>{""}), bflib::split("", {','}));
}

TEST(Split, SinglePartTest) {
    EXPECT_EQ((std::vector<std::string>{"Test",""}), bflib::split("Test,", {','}, true));

    EXPECT_EQ((std::vector<std::string>{"Test"}),    bflib::split("Test,", {','}, false));
}

TEST(Split, MultiplePartTest) {
    EXPECT_EQ((std::vector<std::string>{"Test","A","","Hello"}),
               bflib::split("Test,A,,Hello", {','}, true));

    EXPECT_EQ((std::vector<std::string>{"Test","A","Hello"}),
              bflib::split("Test,A,,Hello", {','}, false));
}

TEST(Split, CharDelimiterTest) {
    EXPECT_EQ((std::vector<std::string>{"Test","A","","Hello"}),
              bflib::split("Test,A,,Hello", ',', true));
}

TEST(Split, MaximalSplitsTest) {
    EXPECT_EQ((std::vector<std::string>{"A,B,C"}),
              bflib::split("A,B,C", ',', true, 0));

    EXPECT_EQ((std::vector<std::string>{"A", "B,C"}),
              bflib::split("A,B,C", ',', true, 1));

    EXPECT_EQ((std::vector<std::string>{"A", "B", "C"}),
              bflib::split("A,B,C", ',', true, 2));

    EXPECT_EQ((std::vector<std::string>{"A", "B", "C"}),
              bflib::split("A,B,C", ',', true, 3));
}

TEST(Concat, EmptyInputTest) {
    EXPECT_EQ("", bflib::concat({}, ""));
    EXPECT_EQ("", bflib::concat({}, ","));
}

TEST(Concat, SinglePartTest) {
    EXPECT_EQ("Test", bflib::concat({"Test"}, ""));
    EXPECT_EQ("Test", bflib::concat({"Test"}, ","));
}

TEST(Concat, MultiplePartsTest) {
    EXPECT_EQ("A<>B<>C", bflib::concat({"A","B","C"}, "<>"));
    EXPECT_EQ("A,,C", bflib::concat({"A","","C"}, ","));
}

TEST(StartsWith, EmptyInputTest) {
    EXPECT_TRUE(bflib::starts_with("", ""));
    EXPECT_TRUE(bflib::starts_with("Test", ""));
}

TEST(StartsWith, NormalInputTest) {
    EXPECT_TRUE(bflib::starts_with("ABC", "AB"));
    EXPECT_TRUE(bflib::starts_with("ABC", "ABC"));

    EXPECT_FALSE(bflib::starts_with("ABX", "ABC"));
    EXPECT_FALSE(bflib::starts_with("ABX", "AX"));
}

TEST(StartsWith, OverlongInputTest) {
    EXPECT_FALSE(bflib::starts_with("", "ABC"));
    EXPECT_FALSE(bflib::starts_with("AB", "ABC"));
}

TEST(EndsWith, EmptyInputTest) {
    EXPECT_TRUE(bflib::ends_with("", ""));
    EXPECT_TRUE(bflib::ends_with("Test", ""));
}

TEST(EndsWith, NormalInputTest) {
    EXPECT_TRUE(bflib::ends_with("ABC", "BC"));
    EXPECT_TRUE(bflib::ends_with("ABC", "ABC"));

    EXPECT_FALSE(bflib::ends_with("XBC", "ABC"));
    EXPECT_FALSE(bflib::ends_with("BXC", "BC"));
}

TEST(EndsWith, OverlongInputTest) {
    EXPECT_FALSE(bflib::ends_with("", "ABC"));
    EXPECT_FALSE(bflib::ends_with("BC", "ABC"));
}

TEST(LeftTrim, EmptyInputTest) {
    EXPECT_EQ("", bflib::left_trim("", {'\t', ' '}));
    EXPECT_EQ("Test", bflib::left_trim("Test", {}));
    EXPECT_EQ("", bflib::left_trim("", {}));
}

TEST(LeftTrim, NormalInputTest) {
    EXPECT_EQ("Test", bflib::left_trim(" \tTest", {'\t', ' '}));
    EXPECT_EQ("Test ", bflib::left_trim(" Test ", {'\t', ' '}));
    EXPECT_EQ("Te st ", bflib::left_trim("Te st ", {'\t', ' '}));
}

TEST(RightTrim, EmptyInputTest) {
    EXPECT_EQ("", bflib::right_trim("", {'\t', ' '}));
    EXPECT_EQ("Test", bflib::right_trim("Test", {}));
    EXPECT_EQ("", bflib::right_trim("", {}));
}

TEST(RightTrim, NormalInputTest) {
    EXPECT_EQ("Test", bflib::right_trim("Test \t ", {'\t', ' '}));
    EXPECT_EQ(" Test", bflib::right_trim(" Test ", {'\t', ' '}));
    EXPECT_EQ(" Te st", bflib::right_trim(" Te st ", {'\t', ' '}));
}

TEST(Reverse, EmptyInputTest) {
    EXPECT_EQ("", bflib::reverse(""));
}

TEST(Reverse, NormalInputTest) {
    EXPECT_EQ("ABC", bflib::reverse("CBA"));
}

TEST(ReverseInPlace, EmptyInputTest) {
    std::string s;
    bflib::reverse_inplace(s);
    EXPECT_EQ("", s);
}

TEST(ReverseInPlace, NormalInputTest) {
    std::string s {"CBA"};
    bflib::reverse_inplace(s);
    EXPECT_EQ("ABC", s);
}