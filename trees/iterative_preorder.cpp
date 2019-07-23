vector<int> Solution::preorderTraversal(TreeNode* A) {
    
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