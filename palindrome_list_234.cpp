//
// Created by peilin.wu on 2023/4/11.
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
    // 方法一：使用数据保存链表所有数据，然后使用双指针（首尾）判断是否是回文；
    // 时间复杂度O(n)，空间复杂度O(n);
    bool isPalindrome(ListNode* head) {
        std::vector<int> tmp_val;
        // 遍历链表写入数组
        while(head != nullptr){
            tmp_val.push_back(head->val);
            head = head->next;
        }

        // 首尾指针判断是否是回文
        int total_size = tmp_val.size();
        for(int i=0; i < (total_size/2); i++){
            if(tmp_val[i] != tmp_val[total_size-i-1]){
                return false;
            }
        }
        return true;
    }

public:
    ListNode* forn;
    // 方法二：递归方法，递归反向迭代链表，和正序迭代链表进行比较；
    bool isPalindrome(ListNode* head) {
        forn = head;
        return recu(head->next);
    }
private:
    bool recu(ListNode* curr){
        if(curr != nullptr){
            // 主要是压栈到最后一个节点开始出栈；
            if(!recu(curr->next)){
                return false;
            }

            if(curr->val != forn->val){
                return false;
            }
            // 正序遍历链表；
            forn = forn->next;
        }
        return true;
    }
};
