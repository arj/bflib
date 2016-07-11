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
    tree<T>::tree(const T& value, tree<T>* parent)
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

    template <class T>
    tree<T>* tree<T>::add_child(const value_type& value)
    {
        // TODO Use allocator!
        tree<T>* child = new tree<T>(value, this);
        children_.emplace_back(child);
        return child;
    }

    template <class T>
    std::vector<std::reference_wrapper<tree<T>>> tree<T>::children()
    {
        std::vector<std::reference_wrapper<tree<T>>> result;
        for (auto& child : children_) {
            result.push_back(*child);
        }

        return result;
    }
}

#endif // BFLIB_TREE_HPP_
