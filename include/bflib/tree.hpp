#ifndef BFLIB_TREE_HPP_
#define BFLIB_TREE_HPP_

#include <bflib/tree.h>

namespace bf {

    template <class T>
    tree<T>::tree(const T& value)
        : value_(value)
        , parent_()
        , children_()
    {
    }

    template <class T>
    tree<T>::tree(const T& value, std::weak_ptr<tree<T>> parent)
        : value_(value)
        , parent_(parent)
        , children_()
    {
    }

    template <class T>
    tree<T>::tree(const T& value, std::shared_ptr<tree<T>> parent)
        : value_(value)
        , parent_(parent)
        , children_()
    {
    }

    template <class T>
    typename tree<T>::reference tree<T>::value()
    {
        return this->value_;
    }

    template <class T>
    typename tree<T>::const_reference tree<T>::value() const
    {
        return this->value_;
    }
}

#endif // BFLIB_TREE_HPP_
