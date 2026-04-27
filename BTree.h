#ifndef BTREE_H
#define BTREE_H

#include <iostream>
using namespace std;

class BTreeNode {
public:
    int* keys;
    int minDegree;
    BTreeNode** children;
    int keyCount;
    bool isLeaf;

    BTreeNode(int degree, bool leaf);

    // Insert a key into a node that is not full
    void insertNonFull(int key);

    // Split a full child node
    void splitChild(int index, BTreeNode* child);

    // Print the tree structure
    void printTree(int spaces);
};

class BTree {
private:
    BTreeNode* root;
    int minDegree;

public:
    BTree(int degree);

    // Insert a key into the B-Tree
    void insert(int key);

    // Display the tree
    void display();
};

#endif