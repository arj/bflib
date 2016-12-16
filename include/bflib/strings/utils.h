#ifndef BFLIB_STRINGS_UTILS_H
#define BFLIB_STRINGS_UTILS_H

#include <algorithm>
#include <limits>
#include <string>
#include <vector>

namespace bflib {

    // TODO Check for strong exception guarantee!

    //! Split a string by a list of delimiters into a list of strings.
    std::vector<std::string> split(const std::string &input,
                                   const std::vector<std::string::value_type> &delimiters,
                                   bool keep_empty_parts = true,
                                   size_t max_splits = std::numeric_limits<size_t>::max()
    );

    std::vector <std::string> split(const std::string &input,
                                    const std::string::value_type &delimiter,
                                    bool keep_empty_parts = true,
                                    size_t max_splits = std::numeric_limits<size_t>::max()
    );

    // TODO Create a concat function w/ variadic templates that accepts a list of parameters, e.g. concat("A", "B", "C", "D");
    std::string concat(const std::vector<std::string>& parts, const std::string& delimiter);

    bool starts_with(const std::string& input, const std::string& prefix);

    bool ends_with(const std::string& input, const std::string& suffix);

    std::string left_trim(const std::string &input, const std::vector<std::string::value_type> &chars);

    void left_trim_inplace(std::string &input, const std::vector<std::string::value_type> &chars);

    std::string right_trim(const std::string &input, const std::vector<std::string::value_type> &chars);

    void right_strip_inplace(std::string& input, const std::vector<std::string::value_type>& chars);

    template <typename ForwardIterator>
    std::string trim(ForwardIterator first, ForwardIterator last, const std::vector<std::string::value_type> &chars) {

        while (first != last) {
            if (std::find(chars.cbegin(), chars.cend(), *first) == chars.cend()) {
                break;
            }

            ++first;
        }

        return std::string(first, last);
    }

    std::string trim(const std::string &input, const std::vector<std::string::value_type> &chars);

    std::string reverse(const std::string& input);

    void reverse_inplace(std::string& input);
};

#endif //BFLIB_STRINGS_UTILS_H
