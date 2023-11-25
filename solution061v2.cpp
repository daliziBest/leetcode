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

//1可以先构造数组，旋转数组，在重新根据数组构造旋转后链表
//2或者直接旋转链表(*)
//结构化绑定语法：auto [head1, tail1] = rotatelocal(head, k);
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //默认大部分情况下都需要翻转
        //N:链表结点个数
        int N;
        head = rotate(head, N);
        if (N == 0 || N == 1)
            return head;

        k = k % N;
        if (k == 0)
        {
            //复原
            head = rotate(head, N);
            return head;
        }
        // Pair<ListNode*, ListNode*> pairs = rotatelocal(head, k);
        // ListNode* newhead = pairs.first;
        // ListNode* tail = pairs.second;
        auto [head1, tail1] = rotatelocal(head, k);
        auto [head2, tail2] = rotatelocal(tail1->next, N - k);
        tail1->next = head2;

        return head1;
    }
private:
    //把完整的一条链表进行翻转
    //并统计结点个数
    ListNode* rotate(ListNode* head, int &N)
    {   
        N = 0;
        if (head == nullptr)
            return head;
        if (head->next == nullptr)
        {
            N++;
            return head;
        }

        //三只手!!!
        //lastnode代表一个阵营
        //每次循环添加一个新结点到lastnode阵营中
        ListNode* lastnode = nullptr;
        ListNode* node = head;
        ListNode* temp;
        while (node != nullptr)
        {
            N++;
            temp = node->next;
            node->next = lastnode;
            lastnode = node;
            node = temp;
            // nextnode = nextnode->next;
        }
        
        return lastnode;
    }

    //把链表局部进行翻转，返回头尾指针
    //只能传入N, N>=1
    pair<ListNode*, ListNode*> rotatelocal(ListNode* head, int N)
    {
        if (N == 1)
            return {head, head};

        //三只手!!!
        //lastnode代表一个阵营
        //每次循环添加一个新结点到lastnode阵营中
        int i = 1;
        ListNode* lastnode = head;
        ListNode* node = head->next;
        ListNode* temp;
        while (i < N)
        {
            i++;
            temp = node->next;
            node->next = lastnode;
            lastnode = node;
            node = temp;
            // nextnode = nextnode->next;
        }
        head->next = node;
    
        return {lastnode, head};
    }
    
};