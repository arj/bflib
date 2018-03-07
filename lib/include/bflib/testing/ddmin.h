#ifndef BFLIB_TESTING_DDMIN_H
#define BFLIB_TESTING_DDMIN_H

#include <bflib/utils.h>
#include <bflib/algorithms/algorithms.h>
#include <bflib/strings/utils.h>

#include <vector>
#include <unordered_set>
#include <algorithm>

namespace bflib {

    template <typename T>
    void print_vector(const std::vector<T>& input) {
        std::vector<std::string> str;
        std::transform(input.cbegin(), input.cend(),
                       std::back_inserter(str),
                       [](const T& v) { return std::to_string(v); });

        std::cout << concat(str, " ");
    }

    template <>
    void print_vector(const std::vector<std::string>& input) {
        std::cout << concat(input, " ");
    }

    //! Split the input list into n equally-sized lists (last list may be longer).
    template <typename T>
    std::vector<std::vector<T>> sublists(const std::vector<T>& input, unsigned int n)
    {
        std::vector<std::vector<T>> subsets;
        unsigned int pos = 0;

        for (size_t i = 0; i < n; ++i) {
            auto lst = sublist(input, pos, pos + (input.size() - pos) / (n - i));
            subsets.push_back(lst);

            pos += lst.size();
        }

        return subsets;
    }

    enum class DDMinResult
    {
        PASS,
        UNRESOLVED,
        FAIL
    };

    template <typename T, typename F>
    std::vector<T> ddmin(const std::vector<T>& input, F harness)
    {
        std::vector<T> data = input;

        // We expect that the input fails in the harness.
        if (harness(input) != DDMinResult::FAIL) {
            throw std::invalid_argument("Input does not fail in test harness");
        }

        unsigned int n = 2;

        while (data.size() >= 2) {
            std::cout << "ddmin(";
            print_vector(input);
            std::cout << "," << n << ")" << std::endl;

            auto subsets = sublists(data, n);
            bool complement_failed = false;

            std::cout << "  Subsets {";
            for (auto& subset : subsets) {
                std::cout << "(";
                print_vector(subset);
                std::cout << ") ";
            }
            std::cout << "}" << std::endl;

            std::cout << "  Complements {";
            for (auto& subset : subsets) {
                std::cout << "(";
                print_vector(bflib::difference(data, subset));
                std::cout << ") ";
            }
            std::cout << "}" << std::endl;

            int i = 1;

            for (auto& subset : subsets) {
                auto complement = bflib::difference(data, subset);

                auto result = harness(complement);
                if (result == DDMinResult::FAIL) {
                    std::cout << "- (";
                    print_vector(complement);
                    std::cout << ") failed" << std::endl;
                    data = complement;
                    n = std::max(n-1, 2u);
                    complement_failed = true;
                    break;
                } else {
                    std::cout << "- (";
                    print_vector(complement);
                    std::cout << ") succeeded" << std::endl;
                }

                ++i;
            }

            if (!complement_failed) {
                if (n == data.size()) {
                    break;
                }

                n = std::min(size_t(n * 2), data.size());
                std::cout << "  No subset failed" << std::endl;
            }
        }

        return data;
    }

}

#endif // BFLIB_TESTING_DDMIN_H
