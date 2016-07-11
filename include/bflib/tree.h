#ifndef BFLIB_TREE_H_
#define BFLIB_TREE_H_

#include <vector>
#include <memory>
#include <functional>

namespace bf {

    template <class T>
    class tree {
    public:
        typedef T value_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;

        //! Create a new tree node with a given value
        tree(const value_type& value);

        //! Create a new tree node with a given value and a parent.
        //! \param value  The value of the node (copied).
        //! \param parent A pointer to the tree node's parent.
        tree(const value_type& value, tree<T>* parent);

        virtual ~tree() = default;

        reference value();

        const_reference value() const;

        //! Adds a child and sets the parent value of the child to this.
        tree<T>* add_child(const value_type& value);

        //! Get all children.
        std::vector<std::reference_wrapper<tree<T>>> children();

    private:
        value_type value_;

        tree<T>* parent_;

        std::vector<std::unique_ptr<tree<T>>> children_;
    };
}

#endif // BFLIB_TREE_H_
