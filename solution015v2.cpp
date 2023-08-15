//https://fizzbuzzed.com/top-interview-questions-1/
//hashmap
//将sum3转化为sum2问题：从一个数组a中找出所有不重复的组合{x,y}，使得x+y=-T
//需要对原sum2问题解法进行修改
//时间复杂度O(n2)
//实际时间耗时较高，主要是由于循环体里定义的大变量(hashmap)频繁的申请回收导致的额外时间开销

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ) {
            const int T = 0 - nums.at(i);
            unordered_map<int, bool> check;
            for (int j = i + 1; j < nums.size(); j++) {
                auto search = check.find(T - nums.at(j));
                if (search == check.end()) {
                    check.insert({nums.at(j), false});
                }else if (search->second == false) {
                    result.push_back({nums.at(i) , nums.at(j), search->first});
                    search->second = true;
                }
            }

            do {
                i++;
            } while (i < nums.size() && nums.at(i) == nums.at(i - 1));
        }


        return result;
    }
};