/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//递归设计

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return my_isValidBST(root, LONG_MIN, LONG_MAX);
    }
private:
    bool my_isValidBST(TreeNode* root, long min, long max)
    {
        if (root == nullptr)
            return true;
        if (root->val <= min || root->val >= max)
            return false;
        if (!my_isValidBST(root->left, min, root->val))
            return false;
        if (!my_isValidBST(root->right, root->val, max))
            return false;
        return true;
    }
};