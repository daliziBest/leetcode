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

//最快的方法：找到旋转的位置，把两个链表拼接起来
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        int N = 1;
        ListNode* node = head;
        //统计结点个数，保留尾指针
        while (node->next != nullptr)
        {
            node = node->next;
            N++;
        }
        k = k % N;
        if (k == 0)
            return head;
        
        //找到切分点
        int i = 1;
        ListNode* node1 = head;
        while (i < N - k)
        {
            i++;
            node1 = node1->next;
        }

        ListNode* new_head = node1->next;
        node->next = head;
        node1->next = nullptr;
        return new_head;
    }
};