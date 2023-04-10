//
// Created by peilin.wu on 2023/4/10.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // 方法一：使用hash集合set存储A链表每个节点的信息，遍历B链表找到相交的节点，没有返回nullptr；
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> total_set;
        ListNode* tmp = headA;
        // 遍历A链表存储到hash集合中；
        while(tmp != nullptr){
            total_set.insert(tmp);
            tmp = headA->next;
        }

        tmp = headB;
        // 遍历链表B；
        while(tmp != nullptr){
            // 如果存在返回1，不存在返回0；
            if(total_set.count(tmp)){
                return tmp;
            }
            tmp = headB->next;
        }
        return nullptr;
    }
};
