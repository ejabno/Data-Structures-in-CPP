//
//  AVLTree.h
//  Data Structures
//
//  Created by Erickson Ureta on 2018-05-10.
//  Copyright © 2018 Erickson Ureta. All rights reserved.
//

#ifndef AVLTree_h
#define AVLTree_h

#include "avlnode.h"
#include "orderedTree.h"

template <typename E>
class AVLTree : public OrderedBinaryTree<E> {
    protected:
        void insertHelper(E, AVLNode<E>*);
    public:
        void insert(E);
};

template <typename E>
void AVLTree<E>::insert(E item) {
    if (this->isEmpty()) {
        AVLNode<E> *newNode = new AVLNode<E>(item);
        this->root = newNode;
    }
    else {
        insertHelper(item, (AVLNode<E>*) this->root);
    }
    ++(this->itemCount);
}

template <typename E>
void AVLTree<E>::insertHelper(E item, AVLNode<E> *root) {
    E compare = root->getData();
    if (item >= compare) {
        if (root->getRight() != NULL) {
            insertHelper(item, (AVLNode<E>*)root->getRight());
        }
        else {
            AVLNode<E> *newNode = new AVLNode<E>(item);
            root->setRight(newNode);
        }
    }
    else {
        if (root->getLeft() != NULL) {
            insertHelper(item, (AVLNode<E>*)root->getLeft());
        }
        else {
            AVLNode<E> *newNode = new AVLNode<E>(item);
            root->setLeft(newNode);
        }
    }
    root->recalibrateHeight();
}

#endif /* AVLTree_h */
