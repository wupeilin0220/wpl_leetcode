//
// Created by peilin.wu on 2023/5/5.
//

class Solution {
public:
    // 使用排序后的字符串作为key，源字符串作为value，保存在哈希表中；
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> cache_map;
        std::vector<std::vector<std::string>> re_vec;
        for(auto str :strs){
            string key = str;
            sort(key.begin(), key.end());
            cache_map[key].push_back(str);
        }
        for(auto i : cache_map){
            re_vec.push_back(i.second);
        }
        return re_vec;
    }
};
