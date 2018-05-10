//
//  node.h
//  Data Structures
//
//  Created by Erickson Ureta on 2018-05-10.
//  Copyright © 2018 Erickson Ureta. All rights reserved.
//

#ifndef node_h
#define node_h

template <typename E>
class Node {
    protected:
        E data;
        Node *left;
        Node *right;
    public:
        Node(E);
        E getData();
        Node *getLeft();
        Node *getRight();
        void setData(E);
        void setLeft(Node*);
        void setRight(Node*);
        int getNumChildren();
};

template <typename E>
Node<E>::Node(E newData) {
    data = newData;
    left = NULL;
    right = NULL;
}

template <typename E>
E Node<E>::getData() {
    return data;
}

template <typename E>
Node<E>* Node<E>::getLeft() {
    return left;
}

template <typename E>
Node<E>* Node<E>::getRight() {
    return right;
}

template <typename E>
void Node<E>::setData(E change) {
    data = change;
}

template <typename E>
void Node<E>::setLeft(Node<E> *newLeft) {
    left = newLeft;
}

template <typename E>
void Node<E>::setRight(Node<E> *newRight) {
    right = newRight;
}

template <typename E>
int Node<E>::getNumChildren() {
    if (left == NULL && right == NULL) {
        return 2;
    }
    else if (left == NULL ^ right == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

#endif /* node_h */
