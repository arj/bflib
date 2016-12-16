#include <bflib/strings/utils.h>
#include <bflib/algorithms/algorithms.h>
#include <assert.h>

namespace bflib {

    std::vector<std::string> split(const std::string &input,
                                   const std::vector<std::string::value_type> &delimiters,
                                   bool keep_empty_parts,
                                   size_t max_splits) {

        std::vector<std::string> result;

        auto parts = bflib::split(input.cbegin(), input.cend(),
                                  {delimiters.cbegin(), delimiters.cend()},
                                  keep_empty_parts,
                                  max_splits);

        for (auto &part : parts) {
            result.emplace_back(part.first, part.second);
        }

        return result;
    }

    std::vector<std::string> split(const std::string &input,
                                   const std::string::value_type &delimiter,
                                   bool keep_empty_parts,
                                   size_t max_splits) {
        return split(input, std::vector<std::string::value_type>{delimiter}, keep_empty_parts, max_splits);
    }

    std::string concat(const std::vector<std::string> &parts, const std::string &delimiter) {

        size_t expected_size = 0;

        for (auto &part : parts) {
            expected_size += part.size();
        }

        if (parts.size() > 0) {
            expected_size += (parts.size() - 1) * delimiter.size();
        }

        std::string result;
        result.reserve(expected_size);

        for (int i = 0; i < parts.size(); ++i) {
            result += parts[i];

            if (i + 1 < parts.size()) {
                result += delimiter;
            }
        }

        assert(expected_size == result.size());

        return result;
    }

    bool starts_with(const std::string& input, const std::string& prefix) {
        return starts_with(input.cbegin(), input.cend(), {prefix.cbegin(), prefix.cend()});
    }

    bool ends_with(const std::string& input, const std::string& suffix) {
        return ends_with(input.cbegin(), input.cend(), {suffix.cbegin(), suffix.cend()});
    }

    std::string left_trim(const std::string &input, const std::vector<std::string::value_type> &chars) {
        return trim(input.cbegin(), input.cend(), chars);
    }

    std::string right_trim(const std::string &input, const std::vector<std::string::value_type> &chars) {
        auto result = trim(input.crbegin(), input.crend(), chars);
        return std::string(result.crbegin(), result.crend());
    }

    void left_trim_inplace(std::string &input, const std::vector<std::string::value_type> &chars) {
        auto end = input.begin();

        while (end != input.end()) {

            if (std::find(chars.cbegin(), chars.cend(), *end) == chars.cend()) {
                break;
            }

            ++end;
        }

        input.erase(input.begin(), end);
    }

    std::string trim(const std::string &input, const std::vector<std::string::value_type> &chars) {
        return left_trim(right_trim(input, chars), chars);
    }

    std::string reverse(const std::string& input) {
        std::string result;
        std::reverse_copy(input.cbegin(), input.cend(),
                          std::back_inserter(result));

        return result;
    }

    void reverse_inplace(std::string& input) {
        std::reverse(input.begin(), input.end());
    }
}