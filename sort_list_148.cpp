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

    // 方法二：归并排序；
    // B站：https://www.bilibili.com/video/BV1Pt4y197VZ/?spm_id_from=333.788.recommend_more_video.1&vd_source=0b7c4bac5ac59d7c4a141b23acdcada4
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        // 1.先通过快慢指针找到链表中间节点，然后断开链表分成两个前后链表，继续递归找中间节点断开，直到终止条件节点==nullptr，跳出递归；
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow;
        ListNode* mid_next = mid->next;
        mid->next = nullptr;
        return merge_sort(sortList(head), sortList(mid_next));
    }

    // 2.合并链表排序，比较两个节点的头结点大小，完成排序；
    ListNode* merge_sort(ListNode* head1, ListNode* head2){
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(head1 && head2){
            if(head1->val <= head2->val){
                curr->next = head1;
                head1 = head1->next;
            }else{
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }

        curr->next = head1 ? head1 : head2;
        return dummy->next;
    }
};