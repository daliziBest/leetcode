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

//类似105,逆向操作即可
//递归

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        TreeNode* result;
        result = mybuildTree(inorder, 0, n - 1, postorder, 0, n - 1);
        return result;
    }

private:
    TreeNode* mybuildTree(vector<int>& inorder, int starti, int endi, vector<int>& postorder, int startp, int endp) {
        //base case
        if (startp > endp) {
            return nullptr;
        }
        if (startp == endp) {
            TreeNode* result = new TreeNode(postorder[endp]);
            return result;
        }

        TreeNode* result = new TreeNode(postorder[endp]);
        int root = postorder[endp];
        int rootloc = starti;
        while (inorder[rootloc] != root) {
            rootloc++;
        }
        int leftnum = rootloc - starti;
        int rightnum = endi - rootloc;
        (*result).left = mybuildTree(inorder, starti, rootloc - 1, postorder, startp, startp + leftnum - 1);
        (*result).right = mybuildTree(inorder, rootloc + 1, endi, postorder, endp - rightnum, endp - 1);

        return result;
    }
};