//
// Created by peilin.wu on 2023/4/14.
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
    // 遍历两次，第一次获得链表总长度，然后根据传参获取要删除节点的正序位置，然后删除；
    // 感觉遍历两次挺费劲的；
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int list_size = 0;

        while(head != nullptr){
            head = head->next;
            list_size++;
        }

        head = curr;
        // 删除的就是头结点；
        if((list_size - n) == 0){
            head = head->next;
            curr = head;
        }else{ // 删除除头结点外的节点；
            for(int i=1; i<list_size; i++){
                // 获取删除节点的正序位置；
                if(i == (list_size - n)){
                    head->next = head->next != nullptr ? head->next->next : nullptr;
                    break;
                }
                head = head->next;
            }
        }
        return curr;
    }
};
