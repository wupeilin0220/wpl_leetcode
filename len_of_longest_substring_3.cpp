//
// Created by peilin.wu on 2023/5/15.
//

class Solution {
public:
    // 滑动窗口思想
    // 使用哈希表去重，两个指针分别指向左右边界，右边界向有滑动把不重复的字符插入哈希表中，判断重复后计算最大长度，
    // 从哈希表中删除左边界元素，左边界向右滑动，最后返回最大子串；
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> cc;
        int num_size = (int)s.size();
        int left_ptr = 0;
        int right_ptr = -1;
        int max_num = 0;
        for(int left_ptr = 0 ; left_ptr<num_size; left_ptr++){
            // 从哈希表中删除左边界元素，左边界向右滑动；
            if(left_ptr != 0){
                cc.erase(s[left_ptr-1]);
            }
            // 右边界持续向右滑动找到重复元素返回，计算最大长度；
            while(right_ptr+1<num_size && !cc.count(s[right_ptr+1])){
                right_ptr++;
                cc.insert(s[right_ptr]);
            }
            max_num = max(max_num, right_ptr-left_ptr+1);
        }
        return max_num;
    }
};
