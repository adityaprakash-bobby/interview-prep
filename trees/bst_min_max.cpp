#include <iostream>

using namespace std;

class BSTNode {

    public:

    int data;
    BSTNode* left;
    BSTNode* right;

};

/* Function to allocate memory to a new node and return the location */
BSTNode* getNewNode(int data) {

    BSTNode* new_node = new BSTNode();

    (*new_node).data = data;
    (*new_node).left = NULL;
    (*new_node).right = NULL;

    return new_node;
}

/* Function to insert a new node to the BST */
BSTNode* insertNode(BSTNode* root, int data) {

    if (root == NULL) {
        root = getNewNode(data);
    } else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

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

/* Driver function to test the above functions */
int main(int argc, char const *argv[])
{
    BSTNode* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 12);
    root = insertNode(root, 8);
    root = insertNode(root, 5);
    root = insertNode(root, 17);
    
    // Search for an element
    int min_element = findMinValue(root);
    int max_element = findMaxValue(root);

    cout << min_element << " " << max_element << endl;

    return 0;
}