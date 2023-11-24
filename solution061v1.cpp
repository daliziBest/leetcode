/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//1可以先构造数组，旋转数组，再重新根据数组修改旋转后链表
//2或者直接旋转链表
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)
            return head;
        //构造数组
        vector<int> nums;
        ListNode* node = head;
        int count = 0;
        while (node != nullptr)
        {
            nums.push_back(node->val);
            count++;
            node = node->next;
        }
        //旋转数组
        k = k % count;
        if (k == 0)
            return head;
        rotate_array(nums, 0, count - 1);
        rotate_array(nums, 0, k - 1);
        rotate_array(nums, k, count - 1);
        //重新根据数组修改旋转后链表
        int i = 0;
        node = head;
        while (node != nullptr)
        {
            node->val = nums[i++];
            node = node->next;
        }

        return head;
    }
private:
    void rotate_array(vector<int> &nums, int i, int j)
    {
        while (i < j)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--; 
        }
    }
    
    
};