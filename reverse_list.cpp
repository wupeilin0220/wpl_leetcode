//
// Created by peilin.wu on 2023/4/10.
//

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

class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* start = head;
        ListNode* next = nullptr;

        while(start != nullptr){
            // 把头的下一个指向next;
            next = start->next;
            start->next = pre;

            // 分别交换以下指针，把指针向后移动；
            pre = start;
            start = next;
        }

        return pre;
    }
};