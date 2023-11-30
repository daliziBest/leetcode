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
//层次遍历
//在层次遍历的过程中，检查当前层节点有没有弹出完，并累计下一层节点的个数
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> nodes;
        int N_current = 1; //用于检查当前层结点有没有弹出完
        int N_nextline = 0; //统计下一层结点个数
        if (root == nullptr)
            return result;
        nodes.push(root);
        while (nodes.size() != 0)
        {
            TreeNode* node = nodes.front();
            nodes.pop();
            N_current--;
            if (node->left != nullptr)
            {
                nodes.push(node->left);
                N_nextline++;
            }
            if (node->right != nullptr)
            {
                nodes.push(node->right);
                N_nextline++;
            }
            if (N_current == 0)
            {
                result.push_back(node->val);
                N_current = N_nextline;
                N_nextline = 0;
            }
        }
        return result;
    }
};