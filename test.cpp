#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        unordered_map<Node*, Node*> origin2copy;    //原链表结点到对应拷贝结点映射
        unordered_map<Node*, Node*> origin2random;  //原链表结点到随机连接结点映射
        Node *last_in_copy = nullptr;
        Node *node_in_origin = head;
        while (node_in_origin != nullptr)
        {
            //申请拷贝结点
            Node node_in_copy(node_in_origin->val);
            //建议映射关系
            origin2copy.insert({node_in_origin, &node_in_copy});
            origin2random.insert({node_in_origin, node_in_origin->random});
            //插入拷贝结点next
            if (last_in_copy != nullptr)
            {
                last_in_copy->next = &node_in_copy;
            }
            node_in_origin = node_in_origin->next;
            last_in_copy = &node_in_copy;
        }

        //处理拷贝结点random
        node_in_origin = head;
        while (node_in_origin != nullptr)
        {
            //找到random结点
            Node *node1 = origin2random.at(node_in_origin);
            //找到random对应的copy结点
            if (node1 != nullptr)
            {
                node1 = origin2copy.at(node1);
            }
            //插入拷贝结点的random
            (origin2copy.at(node_in_origin))->random = node1;
            node_in_origin = node_in_origin->next;
        }

        return origin2copy.at(head);
    }
};

int main()
{
    Node head(7);
    int i = 0;
    Node *node = &head;
    Node *last = nullptr;
    while (i < 5)
    {
        Node newnode(7);
        if (last != nullptr)
        {
            last->next = &newnode;
        }
        last = node;
        i++;
    }
    Solution solution;
    Node *result = solution.copyRandomList(&head);
    while (result != nullptr)
    {
        cout << result->val << endl;
        result = result->next;
    }

    return 0;
}