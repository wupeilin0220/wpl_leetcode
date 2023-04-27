//
// Created by peilin.wu on 2023/4/27.
//

class Solution {
public:
    // 方法一：使用hash表存储元素，使用遍历的方式开始判断每个元素的连续长度，然后返回最大连续长度；
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> cache_hash;
        // 存储到hash表中；
        for(auto i : nums){
            cache_hash.insert(i);
        }

        int tmp_length = 1;
        int res = 0;
        // 遍历hash表中的每个元素；
        for(auto j : cache_hash){
            if(cache_hash.find(j-1) == cache_hash.end()){
                // 计算每个元素的连续长度；
                while(cache_hash.find(j+tmp_length) != cache_hash.end()){
                    tmp_length++;
                }
                // 保存最大连续长度；
                res = max(res, tmp_length);
                tmp_length = 1;
            }
        }
        return res;
    }
};