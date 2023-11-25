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
    void flatten(TreeNode* root) {
        myflatten(root);
        return;
    }

private:
    //递归函数
    pair<TreeNode*, TreeNode*> myflatten(TreeNode* root)
    {
        if (root == nullptr)
            return {nullptr, nullptr};
        TreeNode* head = root;
        auto [head1, tail1] = myflatten(root->left);
        head->left = nullptr;
        auto [head2, tail2] = myflatten(root->right);
        if (head1 == nullptr)
        {
            head->right = head2;
        }
        else
        {
            head->right = head1;
            tail1->right = head2;
        }
        //确定返回值
        if (head2 != nullptr)
        {
            return {head, tail2};
        }
        else if (head1 != nullptr)
        {
            return {head, tail1};
        }
        else
        {
            return {head, head};
        }
    }
};