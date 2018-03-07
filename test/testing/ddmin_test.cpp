#include <gtest/gtest.h>

#include <bflib/testing/ddmin.h>

#include <list>
#include <set>
#include <unordered_set>
#include <iostream>
#include <vector>

TEST(DdminSplit, Sublists) {
    std::vector<int> input {1,2,3,4,5,6,7,8,9,10};

    auto result = bflib::sublists(input, 15);

    for (const auto& set : result) {
        bflib::print_vector(set);
        std::cout << std::endl;
    }
}

TEST(DdminSplit, Ddmin) {
    std::vector<int> input {1,2,3,4,5,6,7,8,9,10};

    auto harness = [](const std::vector<int> input){
        if (bflib::contains(input, 9) && bflib::contains(input, 1)) {
            return bflib::DDMinResult::FAIL;
        }

        return bflib::DDMinResult::PASS;
    };

    auto result = bflib::ddmin(input, harness);

    std::cout << "Miminum input: ";
    bflib::print_vector(result);
    std::cout << std::endl;
}

TEST(DdminSplit, DdminCharList) {
    std::vector<std::string> input {"d","e","b","u","g","g","i","n","g"};

/*    auto harness = [](const std::vector<std::string>& input){

        if (std::adjacent_find(input.cbegin(), input.cend()) != input.cend()) {
            return bflib::DDMinResult::FAIL;
        } else if (bflib::contains(input, "i") && bflib::contains(input, "g")) {
            return bflib::DDMinResult::FAIL;
        }

        return bflib::DDMinResult::PASS;
    };*/

    auto harness_exam = [](const std::vector<std::string>& input) {
        if (std::count(input.cbegin(), input.cend(), "g") >= 2) {
            return bflib::DDMinResult::FAIL;
        } else {
            return bflib::DDMinResult::PASS;
        }
    };

    auto result = bflib::ddmin(input, harness_exam);

    std::cout << "Miminum input: ";
    bflib::print_vector(result);
    std::cout << std::endl;
}

TEST(DdminSplit, DdminCharList2) {
    std::vector<std::string> input {"T","a","a","g","e"};

/*    auto harness = [](const std::vector<std::string>& input){

        if (std::adjacent_find(input.cbegin(), input.cend()) != input.cend()) {
            return bflib::DDMinResult::FAIL;
        } else if (bflib::contains(input, "i") && bflib::contains(input, "g")) {
            return bflib::DDMinResult::FAIL;
        }

        return bflib::DDMinResult::PASS;
    };*/

    auto harness_exam = [](const std::vector<std::string>& input) {
        if (std::count(input.cbegin(), input.cend(), "a") >= 2) {
            return bflib::DDMinResult::FAIL;
        } else {
            return bflib::DDMinResult::PASS;
        }
    };

    auto result = bflib::ddmin(input, harness_exam);

    std::cout << "Miminum input: ";
    bflib::print_vector(result);
    std::cout << std::endl;
}

TEST(DdminSplit, DdminFail) {
    std::vector<int> input {1,2,3};

    auto harness = [](const std::vector<int>& input){
        return bflib::DDMinResult::PASS;
    };

    auto result = bflib::ddmin(input, harness);
}
