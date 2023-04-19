//
// Created by peilin.wu on 2023/4/19.
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
    // 方法一：使用有序哈希表存储，然后遍历哈希表创建新的链表，返回链表头节点；
    ListNode* sortList(ListNode* head) {
        std::map<int, int> cache_map;
        // 遍历原链表存储哈希表；
        while(head!=nullptr){
            if(!cache_map.count(head->val)){
                cache_map[head->val] = 1;
            }else{
                cache_map[head->val]++;
            }
            head = head->next;
        }
        ListNode* new_head = new ListNode(0);
        ListNode* cur = new_head;
        // 遍历哈希表，返回新的链表头结点；
        for(auto iter = cache_map.begin(); iter!=cache_map.end(); iter++){
            int count = iter->second;
            while(count){
                cur->next = new ListNode(iter->first);
                cur = cur->next;
                count--;
            }
        }
        return new_head->next;
    }
};