//
//  main.cpp
//  Data Structures
//
//  Created by Erickson Ureta on 2018-05-10.
//  Copyright © 2018 Erickson Ureta. All rights reserved.
//

#include <iostream>
#include <time.h>

#include "trees/AVLTree.h"

int main(int argc, const char * argv[]) {
    using namespace std;
    AVLTree<int> *testAVLTree = new AVLTree<int>();
    
    testAVLTree->insert(600);
    testAVLTree->displayTree();
    testAVLTree->insert(800);
    testAVLTree->displayTree();
}
