#ifndef BFLIB_UTILS_H
#define BFLIB_UTILS_H

#include <map>
#include <vector>
#include <algorithm>
#include <iterator>

namespace bflib {

    //! An implementation of the unit datatype.
    //!
    //! Its only value is Unit() which is equal to all other instances of it.
    //!
    //! Unit is implicitly constructable by {} because and can be used as a
    //! dummy overloading argument for empty std::initializer_list<T> without
    //! deducting T.
    class Unit {
    };

    inline bool operator==(const Unit& lhs, const Unit& rhs) {
        return true;
    }

    inline bool operator!=(const Unit& lhs, const Unit& rhs) {
        return !(lhs == rhs);
    }

    template<class C>
    class back_insert_pair_first_iterator {
    protected:
        C* container;
    public:
        typedef C                   container_type;
        typedef std::output_iterator_tag iterator_category;
        typedef void                value_type;
        typedef void                difference_type;
        typedef void                pointer;
        typedef void                reference;

        explicit back_insert_pair_first_iterator( C& __x ) :container( &__x ) {
        }

        back_insert_pair_first_iterator<C>& operator=( const typename C::value_type& val ) {
            container->push_back( val.first );
            return *this;
        }

        back_insert_pair_first_iterator<C>& operator*() {
            return *this;
        }

        back_insert_pair_first_iterator<C>& operator++() {
            return *this;
        }

        back_insert_pair_first_iterator<C>& operator++( int ) {
            return *this;
        }
    };

    template< class Container >
    back_insert_pair_first_iterator<Container> back_inserter_pair_first( Container& c )
    {
        return back_insert_pair_first_iterator<Container>(c);
    }

    template<typename T, typename S>
    std::vector<T> multimap_keys(const std::multimap<T, S> &map) {
        std::vector<std::pair<T,S>> keys_dedup;
        std::unique_copy(std::begin(map),
                         std::end(map),
                         std::back_inserter(keys_dedup),
                         [](const std::pair<T, S> &entry1,
                            const std::pair<T, S> &entry2) {
                             return (entry1.first == entry2.first);
                         });

        std::vector<T> keys;

        std::transform(keys_dedup.cbegin(),
                       keys_dedup.cend(),
                       std::back_inserter(keys),
                       [](const std::pair<T, S>& entry) {
                           return entry.first;
                       });

        return keys;
    }
}

#endif // BFLIB_UTILS_H
