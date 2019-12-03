//
//  main.cpp
//  cTest
//
//  Created by Ankur Lahiry on 3/12/19.
//  Copyright © 2019 Prefeex. All rights reserved.
//

#include<iostream>

using namespace std;

struct Node {
    int value;
    Node * left;
    Node * right;
    
    public:
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createBST(Node * node, int value) {
    if (node == NULL) {
        Node * node = new Node(value);
        return node;
    }
    if(value >= node->value) {
        node->right = createBST(node->right, value);
    } else {
        node->left = createBST(node->left, value);
    }

    return node;
}

Node * createFirstBinaryTree(Node * tree) {
    tree = createBST(tree, 25);
    createBST(tree, 15);
    createBST(tree, 10);
    createBST(tree, 4);
    createBST(tree, 12);
    createBST(tree, 22);
    createBST(tree, 18);
    createBST(tree, 24);
    createBST(tree, 50);
    createBST(tree, 35);
    createBST(tree, 31);
    createBST(tree, 44);
    createBST(tree, 70);
    createBST(tree, 66);
    createBST(tree, 90);
    return tree;
}

bool checkIfTreeAreIdenticalRecursive(Node * fTree, Node * sTree) {
    if (fTree == NULL && sTree == NULL)  {
        return true;
    }
  
    /* 2. both non-empty -> compare them */
    if (fTree != NULL && sTree != NULL)
    {
        return
        (
            fTree->value == sTree->value &&
            checkIfTreeAreIdenticalRecursive(fTree->left, sTree->left) &&
            checkIfTreeAreIdenticalRecursive(fTree->right, sTree->right)
        );
    }
      
    return false;
}

int main(int argc, char **argv) {
    Node * fTree = NULL;
    Node * sTree = NULL;
    fTree = createFirstBinaryTree(fTree);
    sTree = createFirstBinaryTree(sTree);
    if (checkIfTreeAreIdenticalRecursive(fTree, sTree)) {
        cout<< "Both tree identical\n";
    } else {
        cout<< "Both tree aren't identical\n";
    }
}
