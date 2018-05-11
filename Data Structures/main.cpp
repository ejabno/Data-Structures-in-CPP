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
    testAVLTree->displayTree();
    cout << "==============================" << endl;
    testAVLTree->insert(1000);
    testAVLTree->displayTree();
    cout << "==============================" << endl;
//    testAVLTree->insert(3000);
//    testAVLTree->displayTree();
//    cout << "==============================" << endl;
    testAVLTree->insert(700);
    testAVLTree->displayTree();
    cout << "==============================" << endl;
    testAVLTree->insert(200);
    testAVLTree->displayTree();
    cout << "==============================" << endl;
}
