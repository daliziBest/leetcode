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
//中序遍历是关键，中序遍历完检查遍历结果是不是严格大于
//借助一个vector
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> nodes;
        dfs(root, nodes);
        for (int i = 1; i < nodes.size(); i++)
        {
            if (nodes[i] <= nodes[i - 1])
                return false;
        }
        return true;
    }
private:
    //中序遍历这个二叉树
    void dfs(TreeNode* root, vector<int> &nodes)
    {
        if (root == nullptr)
        {
            return;
        }
        dfs(root->left, nodes);
        nodes.push_back(root->val);
        dfs(root->right, nodes);
        return;
    }
};