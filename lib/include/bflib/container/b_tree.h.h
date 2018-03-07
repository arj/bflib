#ifndef BFLIB_B_TREE_H_H
#define BFLIB_B_TREE_H_H

namespace bf {

    template <typename K, typename V>
    class b_tree
    {
    public:
        b_tree(unsigned int order = 5);

        //! Add a new key value pair to the b tree.
        //!
        //! Both the key and the value are copied, if you don't want that use
        //! a reference or pointer type for instantiation.
        //!
        //! \post There is only one key-value pair in there (the last one wins)
        //!
        //! \return true if the key already exists, false if not.
        bool add(const K& k, const V& v);

        bool is_leaf() const { return children.empty(); }

        bool has_key(const K& k) const;

        const v& get(const K& k) const {

        }

    private:
        std::vector<K> keys;
        std::vector<std::shared_ptr<b_tree<t,K,V>>> children;

        void check_invariant() {
            if (keys.empty() && children.empty()) {
                return;
            }

            if (keys.size() + 1 != children.size()) {
                throw std::logic_error("Invariant key.size() +1 == children.size() invalid");
            }

            if (keys.size() != m_order) {
                throw std::logic_error("Invariant key.size() == order invalid");
            }
        }
    };

}

#endif //BFLIB_B_TREE_H_H
