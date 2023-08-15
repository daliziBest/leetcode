//想办法在查找上下功夫
//用排序后的string做key建立hashmap
//sort和unordered_map的使用

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> warehouse;
        for(string s : strs) {
            string scopy = s;
            sort(scopy.begin(), scopy.end());
            
            auto location = warehouse.find(scopy);
            if (location == warehouse.end()) {
                warehouse.insert({scopy, {s}});
            } else {
                location->second.push_back(s);
            }
        }

        //遍历每对key-value
        vector<vector<string>> result;
        for (auto i = warehouse.begin(); i != warehouse.end(); i++) {
            result.push_back(i->second);
        }
        return result;
    }
};