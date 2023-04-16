//
// Created by peilin.wu on 2023/4/16.
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
    // 方法一：遍历一次，交换相邻节点，注意跳出循环的判定和节点交换的顺序；
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;

        while(pre->next != nullptr && pre->next->next != nullptr){
            ListNode* n1 = pre->next;
            ListNode* n2 = pre->next->next;
            // 完成相邻节点交换，交换顺序很重要；
            pre->next = n2;
            n1->next = n2->next;
            n2->next = n1;
            pre = n1;
        }
        return dummy->next;
    }
    // 方法二：递归法，返回交换后的新的节点；
    ListNode* swapPairs(ListNode* head) {
        // 终止条件
        if(head == nullptr || head->next==nullptr) return head;

        ListNode* next = head->next;
        // 交换节点
        head->next = swapPairs(next->next);
        next->next = head;
        // 返回新节点
        return next;
    }
};
