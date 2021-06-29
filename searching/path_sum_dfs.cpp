/**
 * Definition for a binary tree node.
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isLeaf(TreeNode *node) {
        return node->left == nullptr && node->right == nullptr;
    }

    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr)
            return false;

        if (isLeaf(root))
            return targetSum == root->val;

        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};