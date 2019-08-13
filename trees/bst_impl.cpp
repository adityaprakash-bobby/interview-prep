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

/* Funciton to find a element in the BST */
bool searchNode(BSTNode* root, int data) {

    if (root == NULL) {
        return false; 
    } else if (data == root->data) {
        return true;
    } else if (data < root->data) {
        return searchNode(root->left, data);
    } else if (data > root->data) {
        return searchNode(root->right, data);
    } 

}

/* Driver function to test the BST implementation */
int main(int argc, char const *argv[])
{
    BSTNode* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 12);
    root = insertNode(root, 8);
    root = insertNode(root, 5);
    root = insertNode(root, 17);
    
    // Search for an element
    bool present_num = searchNode(root, 12);
    bool not_present_num = searchNode(root, 9);

    cout << "12? = " << present_num << endl;
    cout << "9? = " << not_present_num << endl;

    return 0;
}