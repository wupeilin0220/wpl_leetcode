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

    // 方法二：使用两个指针
    // 分别遍历A和B连表，如果相同则返回节点；如果不同把pa赋值headB， pb赋值headA，
    // 后再次遍历是否pa==pb，如果相等返回pa，第二次遍历链表后还没有相等的节点，则没有相交的节点返回nullptr;
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr){
            return nullptr;
        }

        int pa_size = 0, pb_size = 0;
        ListNode* pa = headA;
        ListNode* pb = headB;
        while(pa != pb){
            if (pa_size == 2 and pb_size == 2){
                pa = nullptr;
                break;
            }

            if (pa->next == nullptr){
                pa = headB;
                ++pa_size;
            }else{
                pa = pa->next;
            }

            if (pb->next == nullptr){
                pb = headA;
                ++pb_size;
            }else{
                pb = pb->next;
            }
        }
        return pa;
    }
};
