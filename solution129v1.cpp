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
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int result = 0;
        my_sumNumbers(root, 0, result);
        return result;
    }
private:
    //root一定非空
    void my_sumNumbers(TreeNode* root, int up, int &sum)
    {
        int newup = up * 10 + root->val;
        //叶子结点
        if (root->right == nullptr && root->left == nullptr)
        {
            sum += newup;
            return;
        }
        // int newup = up * 10 + root->val;
        if (root->left != nullptr)
        {
            my_sumNumbers(root->left, newup, sum);
        }
        if (root->right != nullptr)
        {
            my_sumNumbers(root->right, newup, sum);
        }
        
        return;
    }
};