//
// Created by peilin.wu on 2023/4/18.
//
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // 使用哈希表存储，key是原节点，val是拷贝新节点，时间复杂度和空间复杂度都是O(n)；
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> cache_map;
        Node* curr = head;
        // 遍历链表存储到哈希表里；
        while(curr != nullptr){
            cache_map[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        // 再次遍历链表，新节点的next就是原节点的next，新节点的random就是原节点的random；
        while(curr != nullptr){
            cache_map[curr]->next = cache_map[curr->next];
            cache_map[curr]->random = cache_map[curr->random];
            curr = curr->next;
        }
        // 最后返回新的头节点地址；
        return cache_map[head];
    }
};
