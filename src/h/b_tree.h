#ifndef B_TREE_H
#define B_TREE_H

#include <iostream>


template <typename T, const unsigned int MIN_DEGREE>
class BTreeNode {
    public:
        bool isLeaf;
        unsigned int numKeys;
        T keys[2 * MIN_DEGREE - 1];
        BTreeNode* children[2 * MIN_DEGREE];

        BTreeNode(bool isLeaf): isLeaf(isLeaf), numKeys(0) {}
        void print();
        bool search(T key);
};

template <typename T, const unsigned int MIN_DEGREE>
class BTree {
    public:
        BTree(): root(nullptr) {} // inicia arvore vazia
        
        void insert(T key);
        bool search(T key);
        void remove(T key); // nao sei se vou implementar
        void print();
    
    private:
        BTreeNode<T, MIN_DEGREE>* root;

        void splitChild(BTreeNode<T, MIN_DEGREE>* parent, int index);
        void insertNonFull(BTreeNode<T, MIN_DEGREE>* node, T key);
};

extern template class BTree<int, 3>;

#endif // B_TREE_H