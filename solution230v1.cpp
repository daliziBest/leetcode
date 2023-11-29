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
//中序插入
//利用k进行标记
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int result;
        my_kthSmallest(root, k, result);
        return result;
    }
private:
    void my_kthSmallest(TreeNode* root, int &k, int &result)
    {
        if (root == nullptr)
        {
            return;
        }
        my_kthSmallest(root->left, k, result);
        if (k == 0)
            return;

        if (k == 1)
        {
            k--;
            result = root->val;
            return;
        }
        else
        {
            k--;
        }

        my_kthSmallest(root->right, k, result);
        return;
    }
};