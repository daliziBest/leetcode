/*
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
*/

//建立原结点到拷贝结点映射即可
//new的语法

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        unordered_map<Node*, Node*> origin2copy;    //原链表结点到对应拷贝结点映射
        Node *last_in_copy = nullptr;
        Node *node_in_origin = head;
        Node *node_in_copy;  
        while (node_in_origin != nullptr)
        {
            //申请拷贝结点
            /*
             * 这里不要直接声明Node对象，否则下次循环这个Node就会消失，链表也就失效了!!!!!!!!!!!!!!!!
             */
            node_in_copy = new Node(node_in_origin->val);
            //建议映射关系
            origin2copy.insert({node_in_origin, node_in_copy});
            //插入拷贝结点next
            if (last_in_copy != nullptr)
            {
                last_in_copy->next = node_in_copy;
            }

            node_in_origin = node_in_origin->next;
            last_in_copy = node_in_copy;
        }

        //处理拷贝结点random
        node_in_origin = head;
        node_in_copy = origin2copy.at(head);
        while (node_in_origin != nullptr)
        {
            //找到random结点
            Node *node1 = node_in_origin->random;
            //找到random对应的copy结点
            if (node1 != nullptr)
            {
                node1 = origin2copy.at(node1);
            }
            //插入拷贝结点的random
            node_in_copy->random = node1;

            node_in_origin = node_in_origin->next;
            node_in_copy = node_in_copy->next;
        }

        return origin2copy.at(head);
    }
};