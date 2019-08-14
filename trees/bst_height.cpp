#include <iostream>

using namespace std;

class BSTNode {
    
    public:
    int data;
    BSTNode* left;
    BSTNode* right;

};

BSTNode* getNewNode(int data) {

    BSTNode* new_node = new BSTNode();

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

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

int maxHeightBST(BSTNode* root) {

    if (root == NULL) {
        return -1;
    }

    return max(maxHeightBST(root->left), maxHeightBST(root->right)) + 1;
}

int main(int argc, char const *argv[])
{
    BSTNode* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 12);
    root = insertNode(root, 8);
    root = insertNode(root, 5);
    root = insertNode(root, 17);

    int height = maxHeightBST(root);

    cout << height << endl;

    return 0;
}