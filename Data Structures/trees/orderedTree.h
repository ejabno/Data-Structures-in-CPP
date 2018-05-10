//
//  orderedTree.h
//  Data Structures
//
//  Created by Erickson Ureta on 2018-05-10.
//  Copyright © 2018 Erickson Ureta. All rights reserved.
//

#ifndef orderedTree_h
#define orderedTree_h

#include "tree.h"
template<typename E>
class OrderedBinaryTree: public Tree<E> {
    protected:
        void displayTreeHelper(Node<E>*, int);
    public:
        OrderedBinaryTree();
        OrderedBinaryTree(int);
        void insert(E);
        void remove(E);
        void displayTree();
};

template <typename E>
OrderedBinaryTree<E>::OrderedBinaryTree() : Tree<E>() {}

template <typename E>
OrderedBinaryTree<E>::OrderedBinaryTree(int maxSize) : Tree<E>(maxSize) {}

template <typename E>
void OrderedBinaryTree<E>::insert(E item) {
    if (this->isFixedSize()) {
        if (this->itemCount <= this->maxSize) {
            throw "Can't insert on a tree that's already full";
        }
    }
    
    Node<E> *newNode = new Node<E>(item);
    if (this->isEmpty()) {
        this->root = newNode;
    }
    else {
        Node<E> *cur = this->root;
        Node<E> *parent = NULL;
        bool insertRight = false;

        while (cur != NULL) {
            E compare = cur->getData();
            parent = cur;
            if (item < compare) {
                cur = cur->getLeft();
                insertRight = false;
            }
            else {
                cur = cur->getRight();
                insertRight = true;
            }
        }
        if (insertRight) {
            parent->setRight(newNode);
        }
        else {
            parent->setLeft(newNode);
        }
    }
    ++this->itemCount;
}

template <typename E>
void OrderedBinaryTree<E>::remove(E item) {

}

template <typename E>
void OrderedBinaryTree<E>::displayTree() {
    using namespace std;
    if (this->isEmpty()) {
        cout << "Tree is empty" << endl;
    }
    else {
        displayTreeHelper(this->root,0);
    }
}

template <typename E>
void OrderedBinaryTree<E>::displayTreeHelper(Node<E> *root, int level) {
    using namespace std;
    if (root->getRight() != NULL)
        displayTreeHelper(root->getRight(), level+1);
    for (int i = 0; i < level; ++i) {
        cout << "\t";
    }
    cout << root->getData() << endl;
    if (root->getLeft() != NULL)
        displayTreeHelper(root->getLeft(), level+1);
}

#endif /* orderedTree_h */
