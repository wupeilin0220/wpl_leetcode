//
// Created by peilin.wu on 2023/4/12.
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
    // 方法一：使用快慢指针，注意空指针非法访问成员问题，快指针每次走2步，慢指针每次走1步；
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return false;

        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head->next;

        while(slow_ptr != fast_ptr){
            if(fast_ptr == nullptr || fast_ptr->next == nullptr){
                return false;
            }

            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        return true;
    }

    // 方法二：使用哈希表，遍历链表然后保存到哈希表中，如果已经存在表示有环；
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode*> seen;
        while(head != nullptr){
            if(seen.count(head)){
                return true;
            }
            seen.insert(head);
            head = head->next;
        }

        return false;
    }
};
