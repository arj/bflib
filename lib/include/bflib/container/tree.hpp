#ifndef BFLIB_CONTAINER_TREE_HPP_
#define BFLIB_CONTAINER_TREE_HPP_

#include <bflib/container/tree.h>

namespace bflib {

    template <class T>
    tree<T>::tree(const T& value)
        : value_(value)
        , parent_()
        , children_()
    {
    }

    template <class T>
    tree<T>::tree(const T& value, const tree<T>& parent)
        : value_(value)
        , parent_(parent.get_shared_ptr())
        , children_()
    {
    }

    template <class T>
    tree<T>::tree(const T& value, const std::shared_ptr<tree<T>>& parent)
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
    std::shared_ptr<tree<T>> tree<T>::add_child(const value_type& value)
    {
        // TODO Use allocator!
        auto child = std::make_shared<tree<T>>(tree<T>(value, this->get_shared_ptr()));
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

    template <class T>
    std::shared_ptr<tree<T>> tree<T>::get(const tree_path& path)
    {
        if (path.empty()) {
            return this->get_shared_ptr();
        }

        auto i = path.back();

        if (i >= children_.size()) {
            throw std::invalid_argument("Path element " + std::to_string(i) + " is not available in tree");
        }

        tree_path new_path(path.begin(), path.end()-1);

        // TODO As tail call optimization is not avaliable, while loop might be better
        return children_[i]->get(new_path);
    }

    template <class T>
    bool tree<T>::is_leaf() const
    {
        return children_.empty();
    }

    template <class T>
    std::shared_ptr<tree<T>> tree<T>::make_tree(const T& value)
    {
        tree<T>* t = new tree<T>(value);
        return std::shared_ptr<tree<T>>(t);
    }

    template <class T>
    std::shared_ptr<tree<T>> tree<T>::make_tree(const T& value, const tree<T>& parent)
    {
        tree<T>* t = new tree<T>(value, parent);
        return std::shared_ptr<tree<T>>(t);
    }

    template <class T>
    std::shared_ptr<tree<T>> tree<T>::make_tree(const T& value, const std::shared_ptr<tree<T>>& parent)
    {
        tree<T>* t = new tree<T>(value, parent);
        return std::shared_ptr<tree<T>>(t);
    }

    template <class T>
    std::shared_ptr<tree<T>> tree<T>::get_shared_ptr()
    {
        return this->shared_from_this();
    }
}

#endif // BFLIB_CONTAINER_TREE_HPP_
