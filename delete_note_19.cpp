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
    // 方法一：遍历两次，第一次获得链表总长度，然后根据传参获取要删除节点的正序位置，然后删除；
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

    // 方法二：使用栈存储节点，然后根据n值pop()，再改变指针指向完成删除节点操作；
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        stack<ListNode*> store_node;
        int pos = 1;
        while(cur != nullptr){
            store_node.push(cur);
            cur = cur->next;
        }

        // 找出被删除节点的前一个节点；
        for(int i =0 ; i <n; i++){
            store_node.pop();
        }
        ListNode* pre = store_node.empty() ? nullptr : store_node.top();
        if(pre == nullptr){
            return nullptr;
        }
        pre->next = pre->next->next;
        return dummy->next;
    }
};
