#include <iostream>
#include <queue>

using namespace std;

class TreeNode {

    public:
    int data;
    TreeNode* left;
    TreeNode* right;

};

/* Function to add nodes to the binary tree */
TreeNode* addNode(int data) {

    TreeNode *node = new TreeNode;

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return node;

}

/* Funciton to print the level order traversal of a binary tree */
vector<int> levelOrderTraversal(TreeNode* root) {

    vector<int> level_order;
    queue<TreeNode*> q;

    // Logic is to visit the parent and push it into the queue. After visiting
    // the parent, pop the parent from the queue and and push it's children in
    // to the queue. Repeat this until the queue is empty.
    if (root == NULL) {
        return level_order;
    }

    q.push(root);

    while (q.empty() != true) {

        TreeNode* temp = q.front();
        q.pop();
        level_order.push_back(temp->data);
        
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
            
    }

    return level_order;
}

/* Driver to test the level order traversal */
int main(int argc, char const *argv[])
{
    
    TreeNode *root = addNode(1); 
    
    root->left         = addNode(2); 
    root->right        = addNode(3); 
    root->left->left   = addNode(4); 
    root->left->right  = addNode(5); 
    root->right->left  = addNode(6);
    root->right->right = addNode(7);
    
    
    vector<int> res = levelOrderTraversal(root);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << "\n";

    return 0;

}