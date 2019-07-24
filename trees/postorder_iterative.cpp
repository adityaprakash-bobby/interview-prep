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

/* Function to return the postorder traversal of a tree */
vector<int> postorderTraversal(TreeNode* root) {

    vector<int> res;

    if (root == NULL) {
        return res;
    }

    stack<TreeNode*> st1;

    st1.push(root);

    while (st1.empty() == false) {

        TreeNode* top = st1.top();
        st1.pop();
        res.insert(res.begin(), top->val);

        if (top->left) {
            st1.push(top->left);
        }

        if (top->right) {
            st1.push(top->right);
        }

    }
    
    return res;
}

int main(int argc, char const *argv[])
{
    
    TreeNode *root = addNode(1); 
    
    root->left         = addNode(2); 
    root->right        = addNode(3); 
    root->left->left   = addNode(4); 
    root->left->right  = addNode(5); 
    root->right->left  = addNode(6);
    root->right->right = addNode(7);
    
    vector<int> res = postorderTraversal(root);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << "\n";

    return 0;

}