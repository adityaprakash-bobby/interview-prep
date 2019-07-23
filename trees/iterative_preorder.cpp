#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/* Structure to hold tree node data */
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

/* Function to return the preorder tree traversal */
vector<int> preorderTraversal(TreeNode* A) {
    
    vector<int> res;
    
    if (A == NULL) {
        return res;
    }
    
    stack<TreeNode *> st;
    st.push(A);
    
    while (st.empty() == false) {
        
        TreeNode *node = st.top();
        res.push_back(node->val);
        
        st.pop();
        
        if (node->right) {
            st.push(node->right);
        }
        
        if (node->left) {
            st.push(node->left);
        }
        
    }
    
    return res;
}

/* Driver to test the above function */
int main(int argc, char const *argv[])
{

    TreeNode *root = addNode(10); 
    
    root->left        = addNode(8); 
    root->right       = addNode(2); 
    root->left->left  = addNode(3); 
    root->left->right = addNode(5); 
    root->right->left = addNode(2); 
    
    vector<int> res = preorderTraversal(root);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << "\n";

    return 0;
}