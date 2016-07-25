#ifndef BFLIB_TREE_H_
#define BFLIB_TREE_H_

#include <vector>
#include <memory>
#include <functional>

namespace bf {

    template <class T>
    class tree : public std::enable_shared_from_this<tree<T>> {
    public:
        typedef T value_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;

        virtual ~tree() = default;

        reference value();

        const_reference value() const;

        //! Adds a child and sets the parent value of the child to this.
        std::shared_ptr<tree<T>> add_child(const value_type& value);

        //! Get all children.
        std::vector<std::reference_wrapper<tree<T>>> children();

        static std::shared_ptr<tree<T>> make_tree(const value_type& value);
        static std::shared_ptr<tree<T>> make_tree(const value_type& value, const tree<T>& parent);
        static std::shared_ptr<tree<T>> make_tree(const value_type& value, const std::shared_ptr<tree<T>>& parent);

    private:
        //! Create a new tree node with a given value
        tree(const value_type& value);

        //! Create a new tree node with a given value and a parent.
        //! \param value  The value of the node (copied).
        //! \param parent A pointer to the tree node's parent.
        tree(const value_type& value, const tree<T>& parent);

        //! Create a new tree node with a given value and a parent.
        //! \param value  The value of the node (copied).
        //! \param parent A pointer to the tree node's parent.
        tree(const value_type& value, const std::shared_ptr<tree<T>>& parent);

        std::shared_ptr<tree<T>> get_shared_ptr();

    private:
        value_type value_;

        std::weak_ptr<tree<T>> parent_;

        std::vector<std::shared_ptr<tree<T>>> children_;
    };
}

#endif // BFLIB_TREE_H_
