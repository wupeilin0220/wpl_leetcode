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
    // 用一个节点一直指向pre节点用于返回合并后的链表的头节点，遍历两个链表判断值大小然后接在pre节点后面；
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* pre = new ListNode(0);
        ListNode* tmp = pre;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val <= list2->val){
                pre->next = list1;

//                pre = list1;
                list1 = list1->next;
            }else{
                pre->next = list2;

//                pre = list2;
                list2 = list2->next;
            }
            // 替换上面的单独赋值；
            pre = pre->next;
        }

//        if(list1 == nullptr){
//            pre->next = list2;
//        }else{
//            pre->next = list1;
//        }

        // 可以用三元式表达
        pre->next = list1 == nullptr ? list2 : list1;

        return tmp->next;
    }
};
