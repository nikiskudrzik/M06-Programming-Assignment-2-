#include "BTree.h"

BTreeNode::BTreeNode(int degree, bool leaf) {
    minDegree = degree;
    isLeaf = leaf;
    keyCount = 0;

    keys = new int[2 * minDegree - 1];
    children = new BTreeNode*[2 * minDegree];

    for (int i = 0; i < 2 * minDegree; i++) {
        children[i] = nullptr;
    }
}

// Insert into a node that is not full
void BTreeNode::insertNonFull(int key) {
    int index = keyCount - 1;

    if (isLeaf) {
        while (index >= 0 && keys[index] > key) {
            keys[index + 1] = keys[index];
            index--;
        }

        keys[index + 1] = key;
        keyCount++;
    } else {
        while (index >= 0 && keys[index] > key) {
            index--;
        }

        index++;

        if (children[index]->keyCount == 2 * minDegree - 1) {
            splitChild(index, children[index]);

            if (keys[index] < key) {
                index++;
            }
        }

        children[index]->insertNonFull(key);
    }
}

// Split a full child node
void BTreeNode::splitChild(int index, BTreeNode* child) {
    BTreeNode* newChild = new BTreeNode(child->minDegree, child->isLeaf);
    newChild->keyCount = minDegree - 1;

    for (int j = 0; j < minDegree - 1; j++) {
        newChild->keys[j] = child->keys[j + minDegree];
    }

    if (!child->isLeaf) {
        for (int j = 0; j < minDegree; j++) {
            newChild->children[j] = child->children[j + minDegree];
        }
    }

    child->keyCount = minDegree - 1;

    for (int j = keyCount; j >= index + 1; j--) {
        children[j + 1] = children[j];
    }

    children[index + 1] = newChild;

    for (int j = keyCount - 1; j >= index; j--) {
        keys[j + 1] = keys[j];
    }

    keys[index] = child->keys[minDegree - 1];
    keyCount++;
}

// Print the tree structure
void BTreeNode::printTree(int spaces) {
    for (int i = keyCount - 1; i >= 0; i--) {
        if (!isLeaf) {
            children[i + 1]->printTree(spaces + 6);
        }

        for (int j = 0; j < spaces; j++) {
            cout << " ";
        }

        cout << keys[i] << endl;
    }

    if (!isLeaf) {
        children[0]->printTree(spaces + 6);
    }
}

BTree::BTree(int degree) {
    root = nullptr;
    minDegree = degree;
}

// Insert a key into the tree
void BTree::insert(int key) {
    if (root == nullptr) {
        root = new BTreeNode(minDegree, true);
        root->keys[0] = key;
        root->keyCount = 1;
    } else {
        if (root->keyCount == 2 * minDegree - 1) {
            BTreeNode* newRoot = new BTreeNode(minDegree, false);
            newRoot->children[0] = root;
            newRoot->splitChild(0, root);

            int index = 0;

            if (newRoot->keys[0] < key) {
                index++;
            }

            newRoot->children[index]->insertNonFull(key);
            root = newRoot;
        } else {
            root->insertNonFull(key);
        }
    }
}

// Display the tree
void BTree::display() {
    if (root == nullptr) {
        cout << "The B-Tree is empty." << endl;
    } else {
        root->printTree(0);
    }
}