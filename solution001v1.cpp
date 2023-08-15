//不用#include各种头文件
//不用using namespace std

//unordered_map
//关键要搞定重复元素的问题，不使用unordered_multimap
//边查边插
//unordered_map, constructor, find, insert

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        unordered_map<int, int> checked;
        for(int i = 0; i < nums.size(); i++) {
            auto search = checked.find(target - nums[i]);
            if (search != checked.end()) {
                result.push_back(i);
                result.push_back(search->second);
                break;
            }
            checked.insert({nums[i], i});
        }
        
        return result;
    }
};