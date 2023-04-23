//
// Created by peilin.wu on 2023/4/23.
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
    // 合并两个链表，返回头结点；
    ListNode* merge_two_lists(ListNode* a_ptr, ListNode* b_ptr){
        if(!a_ptr || !b_ptr){
            return a_ptr ? a_ptr : b_ptr;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        while(a_ptr && b_ptr){
            if(a_ptr->val <= b_ptr->val){
                head->next = a_ptr;
                a_ptr = a_ptr->next;
            }else{
                head->next = b_ptr;
                b_ptr = b_ptr->next;
            }
            head = head->next;
        }
        // 最后合并剩余非空链表；
        head->next = a_ptr ? a_ptr : b_ptr;
        return dummy->next;
    }
public:
    // 方法一：把合并K个链表，切割为合并两个链表，然后继续合并两个链表，最后返回新链表头，贪心算法；
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 关键先传一个空链表和第一个链表进行合并；
        ListNode* tmp = nullptr;
        for(auto i=0; i<lists.size(); i++){
            tmp = merge_two_lists(tmp, lists[i]);
        }
        return tmp;
    }
};
