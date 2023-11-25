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
    TreeNode* myflatten(TreeNode* root)
    {
        if (root == nullptr)
            return nullptr;
        // TreeNode* head = root;
        auto tail1 = myflatten(root->left);
        auto head1 = root->left;
        root->left = nullptr;
        auto tail2 = myflatten(root->right);
        // if (tail1 == nullptr)
        // {
        //     head->right = head2;
        // }
        if (head1 != nullptr)
        {
            auto head2 = root->right;
            root->right = head1;
            tail1->right = head2;
        }
        //确定返回值
        if (tail2 != nullptr)
        {
            return tail2;
        }
        else if (tail1 != nullptr)
        {
            return tail1;
        }
        else
        {
            return root;
        }
    }
};