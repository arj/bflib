#ifndef BFLIB_TREE_H_
#define BFLIB_TREE_H_

#include <vector>
#include <memory>

namespace bf {

    template <class T>
    class tree {
    public:
        typedef tree<T> tree_type;
        typedef T value_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;

        //! Create a new tree node with a given value
        tree(const value_type& value);

        //! Create a new tree node with a given value and a parent.
        //! \param value  The value of the node (copied).
        //! \param parent A pointer to the tree node's parent.
        tree(const value_type& value, std::weak_ptr<tree_type> parent);

        //! Create a new tree node with a given value and a parent.
        //! \param value  The value of the node (copied).
        //! \param parent A pointer to the tree node's parent.
        tree(const value_type& value, std::shared_ptr<tree_type> parent);

        virtual ~tree() = default;

        reference value();

        const_reference value() const;

    private:
        value_type value_;

        std::weak_ptr<tree_type> parent_;

        std::vector<std::unique_ptr<tree_type>> children_;
    };
}

#endif // BFLIB_TREE_H_
