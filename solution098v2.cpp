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
//借助一个long，且不需要遍历完整个二叉树

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // stack<int> nodes;
        long last = LONG_MIN;
        bool result = true;
        dfs(root, last, result);
        return result;
    }
private:
    //中序遍历这个二叉树
    //result默认是true
    void dfs(TreeNode* root, long &last, bool &result)
    {
        
        if (root == nullptr)
        {
            return;
        }
        
        dfs(root->left, last, result);
        if (!result)
            return;
        int val = root->val;
        if (last == LONG_MIN)
        {
            // nodes.push(root->val);
            last = val;
        }
        else
        {
            if (last < val)
            {
                // nodes.pop();
                // nodes.push(val);
                last = val;
            }
            else
            {
                result = false;
                return;
            }
        }
        dfs(root->right, last, result);
        return;
    }
};