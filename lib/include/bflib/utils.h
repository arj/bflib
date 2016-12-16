#ifndef BFLIB_UTILS_H
#define BFLIB_UTILS_H

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
}

#endif // BFLIB_UTILS_H
