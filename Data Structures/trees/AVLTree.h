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

enum ImbalanceType {LL, LR, RL, RR};
enum Rotation {LEFT, RIGHT};

template <typename E>
class AVLTree : public OrderedBinaryTree<E> {
    protected:
        AVLNode<E>* insertHelper(E, AVLNode<E>*);
        void displayTreeHelper(AVLNode<E>*, int);
        bool isNodeImbalanced(AVLNode<E>*);
        ImbalanceType getImbalance(AVLNode<E>*);
        AVLNode<E>* rotateTree(AVLNode<E>*, Rotation);
    public:
        void insert(E);
        void displayTree();
};

template <typename E>
void AVLTree<E>::insert(E item) {
    if (this->isEmpty()) {
        AVLNode<E> *newNode = new AVLNode<E>(item);
        this->root = newNode;
    }
    else if (this->contains(item)) {
        throw "Inserting duplicate items not allowed\n";
    }
    else {
        this->root = insertHelper(item, (AVLNode<E>*) this->root);
    }
    ++(this->itemCount);
}

template <typename E>
AVLNode<E>* AVLTree<E>::insertHelper(E item, AVLNode<E> *root) {
    E compare = root->getData();
    if (item >= compare) {
        if (root->getRight() != NULL) {
            root->setRight(insertHelper(item, (AVLNode<E>*)root->getRight()));
        }
        else {
            AVLNode<E> *newNode = new AVLNode<E>(item);
            root->setRight(newNode);
        }
    }
    else {
        if (root->getLeft() != NULL) {
            root->setLeft(insertHelper(item, (AVLNode<E>*)root->getLeft()));
        }
        else {
            AVLNode<E> *newNode = new AVLNode<E>(item);
            root->setLeft(newNode);
        }
    }
    root->recalibrateHeight();
    
    if (isNodeImbalanced(root)) {
        ImbalanceType imba = getImbalance(root);
        switch (imba) {
            case LL:
                root = rotateTree(root, RIGHT);
                break;
            case LR:
                root->setLeft(rotateTree((AVLNode<E>*)root->getLeft(), LEFT));
                root = rotateTree(root, RIGHT);
                break;
            case RL:
                root->setRight(rotateTree((AVLNode<E>*)root->getRight(), RIGHT));
                root = rotateTree(root, LEFT);
                break;
            case RR:
                root = rotateTree(root, LEFT);
                break;
        }
    }
    return root;
}

template <typename E>
bool AVLTree<E>::isNodeImbalanced(AVLNode<E> *root) {
    int leftH = 0;
    if (root->getLeft() != NULL) leftH = ((AVLNode<E>*)root->getLeft())->getHeight();
    int rightH = 0;
    if (root->getRight() != NULL) rightH = ((AVLNode<E>*)root->getRight())->getHeight();
    int difference = abs(leftH - rightH);
    if (difference > 1) {
        return true;
    }
    else return false;
}

template <typename E>
ImbalanceType AVLTree<E>::getImbalance(AVLNode<E> *root) {
    if (!isNodeImbalanced(root)) {
        throw "Function should only be used on imbalanced roots";
    }
    int leftHeight = 0;
    int rightHeight = 0;
    if (root->getLeft() != NULL) leftHeight = ((AVLNode<E>*)root->getLeft())->getHeight();
    if (root->getRight() != NULL) rightHeight = ((AVLNode<E>*)root->getRight())->getHeight();

    if (leftHeight > rightHeight) {
        int leftLeftHeight = 0;
        int leftRightHeight = 0;
        if (root->getLeft()->getLeft() != NULL) leftLeftHeight = ((AVLNode<E>*)root->getLeft()->getLeft())->getHeight();
        if (root->getLeft()->getRight() != NULL) leftRightHeight = ((AVLNode<E>*)root->getLeft()->getRight())->getHeight();
        if (leftLeftHeight > leftRightHeight)
            return LL;
        else return LR;
    }
    else {
        int rightLeftHeight = 0;
        int rightRightHeight = 0;
        if (root->getRight()->getLeft() != NULL) rightLeftHeight = ((AVLNode<E>*)root->getRight()->getLeft())->getHeight();
        if (root->getRight()->getRight() != NULL) rightRightHeight = ((AVLNode<E>*)root->getRight()->getRight())->getHeight();
        if (rightLeftHeight > rightRightHeight)
            return RL;
        else return RR;
    }
}

template <typename E>
AVLNode<E>* AVLTree<E>::rotateTree(AVLNode<E> *root, Rotation rotate) {
    AVLNode<E> *newRoot;
    switch (rotate) {
        case LEFT: {
//            displayTree();
            newRoot = (AVLNode<E>*) root->getRight();
            root->setRight((AVLNode<E>*)newRoot->getLeft());
            newRoot->setLeft(root);
            break;
        }
        case RIGHT: {
//            displayTree();
            newRoot = (AVLNode<E>*) root->getLeft();
            root->setLeft((AVLNode<E>*)newRoot->getRight());
            newRoot->setRight(root);
            break;
        }
    }
    newRoot->recalibrateHeight();
    return newRoot;
}

template <typename E>
void AVLTree<E>::displayTree() {
    using namespace std;
    if (this->isEmpty()) {
        OrderedBinaryTree<E>::displayTree();
        return;
    }
    else {
        displayTreeHelper((AVLNode<E>*) this->root, 0);
    }
    if (this->isFixedSize()) {
        cout << "Max size: " << this->getMaxSize() << endl;
    }
    else {
        cout << "Max size: no limit" << endl;
    }
    cout << "# of items in tree: " << this->getItemCount() << endl;
}

template <typename E>
void AVLTree<E>::displayTreeHelper(AVLNode<E> *root, int level) {
    using namespace std;
    if (root->getRight() != NULL) {
        displayTreeHelper((AVLNode<E>*)root->getRight(), level + 1);
    }
    for (int i = 0; i < level; ++i) {
        cout << "\t";
    }
    cout << root->getData() << "(" << root->getHeight() << ")" << endl;
    if (root->getLeft() != NULL) {
        displayTreeHelper((AVLNode<E>*)root->getLeft(), level + 1);
    }
}

#endif /* AVLTree_h */
