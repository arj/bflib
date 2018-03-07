#ifndef BFLIB_ALGORITHMS_ALGORITHMS_H
#define BFLIB_ALGORITHMS_ALGORITHMS_H

#include <bflib/utils.h>

#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

namespace bflib {

    //! Split a sequence into subsequences by delimiters.
    //!
    //! \param first, last The range of elements to split
    //! \param delimiters A set of delimiters that are used for splitting
    //! \param keep_empty_parts Whether to keep empty sequences
    //! \return A list of iterator pairs describing sub-lists of the input range
    //!
    //! \pre first and last belong to the same sequence (unchecked, UB if not met)
    //! \pre ForwardIterator::value_type must be hashable (see http://en.cppreference.com/w/cpp/utility/hash)
    //!
    //! ## Complexity ##
    //! Linear in std::distance(first, last)
    //!
    //! ## Example ##
    //! The following code snippet
    //! \code{.cpp}
    //! std::vector<int> data {1, 4, 99, 2, 99, 99, 7, 10};
    //!
    //! auto parts = bflib::split(data.cbegin(), data.cend(), {99}, true);
    //!
    //! for (auto& part : parts) {
    //!    for (auto& it = part.first; it != part.second; ++it) {
    //!       std::cout << *it;
    //!    }
    //!    std::cout << std::endl;
    //! }
    //! \endcode
    //! produces the following output:
    //! \verbatim
    //! 14
    //! 2
    //!
    //! 710
    //! \endverbatim
    template<typename ForwardIterator>
    std::vector <std::pair<ForwardIterator, ForwardIterator>>
    split(ForwardIterator first, ForwardIterator last,
          const std::unordered_set<typename std::iterator_traits<ForwardIterator>::value_type> &delimiters,
          bool keep_empty_parts = true,
          size_t max_splits = std::numeric_limits<size_t>::max()) {

        std::vector <std::pair<ForwardIterator, ForwardIterator>> result;

        ForwardIterator part_begin = first;

        size_t splits = 0;

        for (auto &it = first; it != last; ++it) {
            if (splits >= max_splits) {
                break;
            }

            if (delimiters.find(*it) != delimiters.end()) {

                if (part_begin == it && !keep_empty_parts) {
                    part_begin = it;
                    ++part_begin;
                    continue;
                }

                result.emplace_back(part_begin, it);
                part_begin = it;
                ++part_begin;

                ++splits;
            }
        }

        if (keep_empty_parts || part_begin != last) {
            result.emplace_back(part_begin, last);
        }

        return result;
    }

    //! Vector-specific split version.
    //! Copies elements of the vector
    template <typename T>
    std::vector<std::vector<T>> split(const std::vector<T>& input, const std::unordered_set<typename std::vector<T>::value_type>& delimiters,
            bool keep_empty_parts = true,
            size_t max_splits = std::numeric_limits<size_t>::max()) {
        std::vector<std::vector<T>> result;

        for (auto& it : split(input.cbegin(), input.cend(), delimiters, keep_empty_parts, max_splits)) {
            result.emplace_back(it.first, it.second);
        }

        return result;
    }

    template <typename ForwardIterator>
    bool starts_with(ForwardIterator first, ForwardIterator last,
                     const std::vector<typename std::iterator_traits<ForwardIterator>::value_type>& prefix) {

        auto& it = first;

        for (auto& v : prefix) {
            if (it == last) {
                // prefix is longer than input sequence
                return false;
            }

            if (v != *it) {
                return false;
            }

            ++it;
        }

        return true;
    }

    template <typename BidirectionalIterator>
    bool ends_with(BidirectionalIterator first, BidirectionalIterator last,
                   const std::vector<typename std::iterator_traits<BidirectionalIterator>::value_type>& suffix) {

        auto& it = last;
        --it;

        auto first_end = first;
        --first_end;

        for (auto suffix_it = suffix.rbegin(); suffix_it != suffix.rend(); ++suffix_it) {
            if (it == first_end) {
                // suffix is longer than input sequence
                return false;
            }

            if (*suffix_it != *it) {
                return false;
            }

            --it;
        }

        return true;
    }


    template <typename T, typename Container>
    bool contains(const Container& container, const T& value) {
        return std::find(container.cbegin(), container.cend(), value) != container.cend();
    }

    template <typename T>
    bool contains(const std::initializer_list<T>& container, const T& value) {
        return std::find(container.begin(), container.end(), value) != container.end();
    }

    template <typename Container1, typename Container2>
    bool is_subset(const Container1& container1, const Container2& container2) {
        for (auto& v : container1) {
            if (!contains(container2, v)) {
                return false;
            }
        }

        return true;
    }

    template <typename T, typename Container2>
    bool is_subset(const std::initializer_list<T>& container1, const Container2& container2) {
        for (auto& v : container1) {
            if (!contains(container2, v)) {
                return false;
            }
        }

        return true;
    }

    // This catches {} before the initializer list above and does not need a template T
    template <typename Container2>
    bool is_subset(const Unit& unit, const Container2& container2) {
        return true;
    }

    template <typename Container1>
    bool is_subset(const Container1& container1, const Unit& unit) {
        return container1.empty();
    }

    //! \brief Extract a sublist from index from (inclusive) to index to (exclusive)
    template <typename T>
    std::vector<T> sublist(const std::vector<T>& input, size_t from, size_t to) {
        if (from > to) {
            throw std::invalid_argument("from > to");
        }

        std::vector<T> result;

        auto from_it = input.begin() + from;
        auto to_it = input.begin() + to;

        std::copy(from_it, to_it, std::back_inserter(result));

        return result;
    }

    template <typename T>
    std::vector<T> difference(const std::vector<T>& input1, const std::vector<T>& input2)
    {
        std::set<T> set1(input1.cbegin(), input1.cend());
        std::set<T> set2(input2.cbegin(), input2.cend());

        std::vector<T> result;

        std::set_difference(set1.cbegin(), set1.cend(),
                            set2.cbegin(), set2.cend(),
                            std::back_inserter(result));

        return result;
    }
}

#endif // BFLIB_ALGORITHMS_ALGORITHMS_H
