//
//  avlnode.h
//  Data Structures
//
//  Created by Erickson Ureta on 2018-05-10.
//  Copyright © 2018 Erickson Ureta. All rights reserved.
//

#ifndef avlnode_h
#define avlnode_h

#include "node.h"
template <typename E>
class AVLNode: public Node<E> {
    protected:
        int height;
    public:
        AVLNode(E);
        int getHeight();
        void setLeft(AVLNode<E>*);
        void setRight(AVLNode<E>*);
        void recalibrateHeight();
};

template <typename E>
AVLNode<E>::AVLNode(E item): Node<E>(item) {
    height = 1;
}

template <typename E>
int AVLNode<E>::getHeight() {
    return height;
}

template <typename E>
void AVLNode<E>::recalibrateHeight() {
    int leftHeight = 0, rightHeight = 0;
    if (((AVLNode<E>*)this->left) != NULL) {
        ((AVLNode<E>*)this->left)->recalibrateHeight();
        leftHeight = ((AVLNode<E>*)this->left)->getHeight();
    }
    if (((AVLNode<E>*)this->right) != NULL) {
        ((AVLNode<E>*)this->right)->recalibrateHeight();
        rightHeight = ((AVLNode<E>*)this->right)->getHeight();
    }
    if (leftHeight > rightHeight) {
        height = leftHeight + 1;
    }
    else {
        height = rightHeight + 1;
    }
}

template <typename E>
void AVLNode<E>::setLeft(AVLNode<E>* newLeft) {
    this->left = newLeft;
    recalibrateHeight();
}

template <typename E>
void AVLNode<E>::setRight(AVLNode<E>* newRight) {
    this->right = newRight;
    recalibrateHeight();
}

#endif /* avlnode_h */
