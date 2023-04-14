//
// Created by peilin.wu on 2023/4/13.
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
    // 结论：这种方法是不可行的；但是保留自己的思考逻辑；
    // 想通过先拿到两个链表的逆序的整数值，然后相加后转为string类型，再逆序遍历string重写链表，会因为数值精度不够导致失败；
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> l1_val;
        stack<int> l2_val;
        long long  l1_add = 0;
        long long l2_add = 0;
        ListNode* head = nullptr;
        ListNode* curr = nullptr;

        while(l1 != nullptr){
            l1_val.push(l1->val);
            l1 = l1->next;
        }
        while(!l1_val.empty()){
            l1_add += l1_val.top() * pow(10, l1_val.size() - 1);
            l1_val.pop();
        }

        while(l2 != nullptr){
            l2_val.push(l2->val);
            l2 = l2->next;
        }
        while(!l2_val.empty()){
            l2_add += l2_val.top() * pow(10, l2_val.size() - 1);
            l2_val.pop();
        }

        long long total = l1_add + l2_add;
        string str_tmp = to_string(total);
        for(int i = str_tmp.size() -1; i >=0; i--){
            ListNode* next = new ListNode(str_tmp[i] - '0');
            if(head == nullptr){
                head = next;
                curr = next;
                continue;
            }
            curr->next = next;
            curr = curr->next;
            //delete next;
        }
        return head;
    }

    // 把两组链表存在vector中，分别对节点相加，主要注意如何进1，以及最后满10进1的操作；
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int is_ten = 0;
        vector<int> l1_val;
        vector<int> l2_val;
        vector<int> sum_val;
        int tmp_l1=0, tmp_l2 = 0, tmp_sum=0;
        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        // 遍历两组链表存入vector；
        while(l1 != nullptr){
            l1_val.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2 != nullptr){
            l2_val.push_back(l2->val);
            l2 = l2->next;
        }

        // 遍历两个vector值相加；
        int i=0, j=0;
        while(i<l1_val.size() || j<l2_val.size()){
            tmp_l1 = (i>=l1_val.size()) ? 0 : l1_val[i];
            tmp_l2 = (j>=l2_val.size()) ? 0 : l2_val[j];
            tmp_sum = tmp_l1 + tmp_l2;
            tmp_sum = tmp_sum + is_ten;
            if((tmp_sum / 10) > 0){
                tmp_sum = (tmp_sum % 10);
                is_ten = 1;
            }else{
                is_ten = 0;
            }
            sum_val.push_back(tmp_sum);
            i++;
            j++;
        }
        // 最后满10，补1；
        if(is_ten == 1){
            sum_val.push_back(is_ten);
        }

        // 遍历结果vector，生成链表返回头结点；
        for(int i = 0; i < sum_val.size(); i++){
            ListNode* next = new ListNode(sum_val[i]);
            if(head == nullptr){
                head = next;
                curr = next;
                continue;
            }
            curr->next = next;
            curr = curr->next;
        }
        return head;
    }
};
