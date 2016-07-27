#ifndef BFLIB_TREE_H_
#define BFLIB_TREE_H_

#include <vector>
#include <memory>
#include <functional>

namespace bf {

    //! A path represents a path on the tree.
    //!
    //! A path is always specified backwards, i.e. the first path is the last item.
    using tree_path = std::vector<unsigned int>;

    //! Tree represents a non-modifiable tree.
    //!
    //! The tree is non-modifiable in the sense that its structure cannot be changed.
    //! The values in the tree can be changed, however.
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

        //! Get the tree at a specific path
        std::shared_ptr<tree<T>> get(const tree_path& path);

        //! \return true if the tree is a leaf, i.e. it doesn't have children.
        bool is_leaf() const;

        //! Create a new tree node with a given value and a parent.
        //! \param value  The value of the node (copied).
        //! \param parent A pointer to the tree node's parent.
        //! \return a shared_ptr to the new tree.
        static std::shared_ptr<tree<T>> make_tree(const value_type& value);

        //! Create a new tree node with a given value and a parent.
        //! \param value  The value of the node (copied).
        //! \param parent A pointer to the tree node's parent.
        //! \return a shared_ptr to the new tree.
        static std::shared_ptr<tree<T>> make_tree(const value_type& value, const tree<T>& parent);

        //! Create a new tree node with a given value and a parent.
        //! \param value  The value of the node (copied).
        //! \param parent A pointer to the tree node's parent.
        //! \return a shared_ptr to the new tree.
        static std::shared_ptr<tree<T>> make_tree(const value_type& value, const std::shared_ptr<tree<T>>& parent);

    private:
        //! Create a new tree node with a given value.
        //! \param value The value at the tree node (copied)
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
