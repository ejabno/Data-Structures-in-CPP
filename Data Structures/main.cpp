//
//  main.cpp
//  Data Structures
//
//  Created by Erickson Ureta on 2018-05-10.
//  Copyright © 2018 Erickson Ureta. All rights reserved.
//

#include <iostream>
#include "trees/orderedTree.h"

int main(int argc, const char * argv[]) {
    using namespace std;
    OrderedBinaryTree<int> *testTree = new OrderedBinaryTree<int>();
    testTree->displayTree();
    
    cout << "=============================================" << endl;
    testTree->insert(50);
    testTree->displayTree();
    
    cout << "=============================================" << endl;
    testTree->insert(15);
    testTree->displayTree();
    
    cout << "=============================================" << endl;
    testTree->insert(100);
    testTree->displayTree();
}
