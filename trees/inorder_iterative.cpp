#include <iostream>
#include <stack>
#include <vector>

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

/* Function to return the inorder traversal of a binary tree */
vector<int> inorderTraversal(TreeNode* A) {

    vector<int> res;
    stack<TreeNode *> st;
    TreeNode* curr = A;

    while (curr != NULL || st.empty() == false) {

        while (curr != NULL) {

            st.push(curr);
            curr = curr->left;

        }

        curr = st.top();
        st.pop();

        res.push_back(curr->val);

        curr = curr->right;

    }

    return res;
}

/* Driver to test the above code */
int main(int argc, char const *argv[])
{
    
    TreeNode *root = addNode(1); 
    
    root->left         = addNode(2); 
    root->right        = addNode(3); 
    root->left->left   = addNode(4); 
    root->left->right  = addNode(5); 
    root->right->left  = addNode(6);
    root->right->right = addNode(7);
    
    
    vector<int> res = inorderTraversal(root);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << "\n";

    return 0;

}