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

//height-balanced?  对于任何一个树来说，两边子树节点相差不超过1
//递归


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* result;
        result = mySortedArrayToBST(nums, 0, nums.size() - 1);
        return result;
    }

private:
    TreeNode* mySortedArrayToBST(vector<int>& nums, int start, int end) {
        //base case
        if (start > end) {
            return nullptr;
        }
        if (start == end) {
            TreeNode* result = new TreeNode(nums[start]);
            return result;
        }

        int rootloc = (start + end) / 2;
        TreeNode* result = new TreeNode(nums[rootloc]);
        (*result).left = mySortedArrayToBST(nums, start, rootloc - 1);
        (*result).right = mySortedArrayToBST(nums, rootloc + 1, end);

        return result;
    }
};