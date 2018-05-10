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
    
    if (this->contains(item)) {
        throw "Can't have duplicates in the tree\n";
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
    if (this->isEmpty()) {
        throw "Can't remove from an already empty tree\n";
    }
    if (!this->contains(item)) {
        throw "The item being removed is not in the tree\n";
    }
    
    Node<E> *deleteNode = this->root;
    Node<E> *parent = NULL;
    bool deleteRight = false;
    E compare = deleteNode->getData();

    while (item != compare) {
        parent = deleteNode;
        if (item > compare) {
            deleteNode = deleteNode->getRight();
            deleteRight = true;
        }
        else if (item < compare) {
            deleteNode = deleteNode->getLeft();
            deleteRight = false;
        }
        compare = deleteNode->getData();
    }
    
    bool deleteRoot;
    if (parent == NULL) {
        deleteRoot = true;
    }
    else deleteRoot = false;

    switch (deleteNode->getNumChildren()) {
        case 0:
            if (deleteRoot) {
                this->root = NULL;
            }
            else {
                if (deleteRight)
                    parent->setRight(NULL);
                else parent->setLeft(NULL);
            }
            delete deleteNode;
            --(this->itemCount);
            break;
        case 1:
            Node<E> *newRoot;
            if (deleteNode->getLeft() != NULL)
                newRoot = deleteNode->getLeft();
            else newRoot = deleteNode->getRight();
            if (deleteRoot) {
                this->root = newRoot;
            }
            else {
                if (deleteRight)
                    parent->setRight(newRoot);
                else parent->setLeft(newRoot);
            }
            delete deleteNode;
            --(this->itemCount);
            break;
        case 2:
            Node<E> *IOSuccessor = deleteNode->getRight();
            while (IOSuccessor->getLeft() != NULL) {
                IOSuccessor = IOSuccessor->getLeft();
            }
            E backup = IOSuccessor->getData();
            remove(backup);
            deleteNode->setData(backup);
            break;
    }
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
    if (this->isFixedSize()) {
        cout << "Max size: " << this->getMaxSize() << endl;
    }
    else {
        cout << "Max size: no limit" << endl;
    }
    cout << "# of items in tree: " << this->getItemCount() << endl;
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
