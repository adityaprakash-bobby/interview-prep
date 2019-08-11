#include <iostream>

class BSTNode {

    public:

    int data;
    BSTNode* left;
    BSTNode* right;

};

int findMinValue(BSTNode* root) {

    // Return -1 if no nodes in the tree
    if (root == NULL) {
        return -1;
    }

    while (root->left != NULL) {
        root = root->left;
    }

    return root->data;

}

int findMaxValue(BSTNode* root) {

// Return -1 if no nodes in the tree
    if (root == NULL) {
        return -1;
    }

    while (root->right != NULL) {
        root = root->right;
    }

    return root->data;

}