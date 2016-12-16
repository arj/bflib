#ifndef BFLIB_CONTAINER_NON_EMPTY_VECTOR_H
#define BFLIB_CONTAINER_NON_EMPTY_VECTOR_H

#include <vector>

#include <bflib/contracts.h>

namespace bflib {

    template<
            typename T,
            class Allocator = std::allocator<T>
    > class NonEmptyVector {
    private:
        using InternalDataType = std::vector<T, Allocator>;
    public:
        // Member types
        using value_type = InternalDataType::T;
        using allocator_type = InternalDataType::Allocator;
        using size_type = InternalDataType::size_type;
        using difference_type = InternalDataType::difference_type;
        using value_type = InternalDataType::value_type;
        using const_reference = InternalDataType::const_reference;
        using pointer = InternalDataType::pointer;
        using const_pointer = InternalDataType::const_pointer;
        using iterator = InternalDataType::iterator;
        using const_iterator = InternalDataType::const_iterator;
        using reverse_iterator = InternalDataType::reverse_iterator;
        using const_reverse_iterator = InternalDataType::const_reverse_iterator;

        // Ctors

        explicit NonEmptyVector(const T& value, const Allocator& alloc = Allocator()) : data_(1, value, alloc) {

        }

        NonEmptyVector(size_type count, const T& value, const Allocator& alloc = Allocator())
                : data_(count, value, alloc) {
            Precondition(count > size_t{0}, "NonEmptyVector - At least one element required");
        }

        explicit NonEmptyVector(size_type count, const Allocator& alloc = Allocator())
                : data_(count, alloc) {
            Precondition(count > size_t{0}, "NonEmptyVector - At least one element required");
        }

        template <class InputIt>
        NonEmptyVector(InputIt first, InputIt last, const Allocator& alloc = Allocator())
                : data_(first, last, alloc) {
            Precondition(std::distance(first, last) >= 1, "NonEmptyVector - At least one element required");
        }

        NonEmptyVector(std::initializer_list<T> init, const Allocator& alloc = Allocator())
                : NonEmptyVector(init, alloc) {
            Precondition(init.size() >= 1, "NonEmptyVector - At least one element required");
        }

    private:
        InternalDataType data_;
    };
}

#endif // BFLIB_CONTAINER_NON_EMPTY_VECTOR_H