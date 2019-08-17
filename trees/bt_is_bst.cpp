#include <iostream>
#include <climits>

using namespace std;

struct TreeNode_t {
    
    int val;
    TreeNode_t *left;
    TreeNode_t *right;

};

typedef struct TreeNode_t TreeNode;

/* Function to add a new node to a tree */
TreeNode* addNode(int val) {

    TreeNode *node = new TreeNode;

    node->val = val;
    node->left = NULL;
    node->right = NULL;
    
    return node;

}

// Util to determine is the left and right subtrees are BST
bool isBSTUtil(TreeNode* root, int min_val, int max_val) {

    if (root == NULL) {
        return true;
    }

    if (root->val > min_val && root->val <= max_val
            && isBSTUtil(root->left, min_val, root->val)
            && isBSTUtil(root->right, root->val, max_val)) {
            
        return true;
    } else {
        return false;
    }
}

// Function to determine if a binary tree is BST
bool isBST(TreeNode* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{

    TreeNode *root = addNode(10); 
    
    root->left        = addNode(7); 
    root->right       = addNode(20); 
    root->left->left  = addNode(4); 
    root->left->right = addNode(9); 
    root->right->left = addNode(12); 
    root->right->right = addNode(30); 
    
    cout << isBST(root) << endl;

    return 0;
}