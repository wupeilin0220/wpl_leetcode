//
// Created by peilin.wu on 2023/5/8.
//

class Solution {
public:
    // 使用排序+双指针
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 排序
        vector<vector<int>> res_vec;
        int size = nums.size();
        int target = 0;
        for(int i = 0; i < size; i++){
            if(i> 0 && nums[i] == nums[i-1]) continue;  // 跳过重复

            int start_ptr = i+1;
            int end_ptr = size -1;
            while(start_ptr < end_ptr){
                // 三数和
                int tmp_value = nums[i] + nums[start_ptr] + nums[end_ptr];
                if(tmp_value < target){ // 小于目标值，头指针++；
                    start_ptr++;
                }else if(tmp_value > target){   // 大于目标值，尾指针--；
                    end_ptr--;
                }else{
                    res_vec.push_back({nums[i], nums[start_ptr], nums[end_ptr]});
                    // 跳过重复
                    for(++start_ptr; start_ptr < end_ptr && nums[start_ptr] == nums[start_ptr-1]; start_ptr++){
                        continue;
                    }
                }
            }
        }
        return res_vec;
    }
};
