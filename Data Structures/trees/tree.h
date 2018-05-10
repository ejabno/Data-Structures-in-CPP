//
//  tree.h
//  Data Structures
//
//  Created by Erickson Ureta on 2018-05-10.
//  Copyright © 2018 Erickson Ureta. All rights reserved.
//

#ifndef tree_h
#define tree_h

#include "node.h"

template <typename E>
class Tree {
    protected:
        int maxSize;
        int itemCount;
        bool fixedSize;
        Node<E> *root;
        Tree(int);
        Tree();
    public:
        virtual void insert(E) = 0;
        virtual void remove(E) = 0;
        virtual void displayTree() = 0;
        bool isEmpty();
        bool isFixedSize();
        int getMaxSize();
        int getItemCount();
        bool contains(E);
};

template <typename E>
Tree<E>::Tree() {
    fixedSize = false;
    maxSize = -1;
    itemCount = 0;
    root = NULL;
}

template <typename E>
Tree<E>::Tree(int maxSize) {
    if (maxSize < 0) {
        throw "Can't have negative sized trees\n";
    }
    fixedSize = true;
    this->maxSize = maxSize;
    itemCount = 0;
    root = NULL;
}

template <typename E>
bool Tree<E>::isEmpty() {
    return (root == NULL);
}

template <typename E>
bool Tree<E>::isFixedSize() {
    return fixedSize;
}

template <typename E>
int Tree<E>::getMaxSize() {
    if (fixedSize) {
        return maxSize;
    }
    else {
        throw "No max size for an unlimited tree\n";
    }
}

template <typename E>
int Tree<E>::getItemCount() {
    return itemCount;
}

template <typename E>
bool Tree<E>::contains(E item) {
    if (isEmpty()) {
        return false;
    }
    
    Node<E> *cur = root;
    while (cur != NULL) {
        E compare = cur->getData();
        if (compare < item) {
            cur = cur->getRight();
        }
        else if (compare > item) {
            cur = cur->getLeft();
        }
        else return true;
    }
    return false;
}

#endif /* tree_h */
