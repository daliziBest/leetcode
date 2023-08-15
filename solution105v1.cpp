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

//用递归的方法去做

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        TreeNode* result;
        result = myBuildTree(preorder, 0, n - 1, inorder, 0, n - 1);
        return result;
    }

private:
    TreeNode* myBuildTree(vector<int>& preorder, int startp, int endp, vector<int>& inorder, int starti, int endi) {
        //base case
        if (startp > endp) {
            return nullptr;
        }
        if (startp == endp) {
            TreeNode* result = new TreeNode(preorder[startp]);
            return result;
        }
        
        TreeNode* result = new TreeNode(preorder[startp]);
        int root = preorder[startp];
        int rootloc = starti;
        while (inorder[rootloc] != root) {
            rootloc++;
        }
        int leftnum = rootloc - starti;
        int rightnum = endi - rootloc;
        (*result).left = myBuildTree(preorder, startp + 1, startp + leftnum, inorder, starti, rootloc - 1);
        (*result).right = myBuildTree(preorder, endp - rightnum + 1, endp, inorder, rootloc + 1, endi);

        return result;
    }
};