//使用hashmap
//如何判断一个数在consecutive sequence里
//如何去除重复的数
//如何计算每个consecutive sequence的length


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //corner case
        if (nums.size() == 0) {
            return 0;
        }

        unordered_map<int, bool> pool;
        for (auto a : nums) {
            pool.insert({a, false});
        }

        int maxLength = 0;
        for (auto a : pool) {
            if (a.second == false) {
                int temp = a.first;
                int len = 1;
                a.second = true; //能直接修改value
                while (pool.find(++temp) != pool.end()) {   //不能使用contains函数，C++20才引入
                    len++;
                    pool.at(temp) = true;
                }

                temp = a.first;
                while (pool.find(--temp) != pool.end()) {
                    len++;
                    pool.at(temp) = true;
                }

                maxLength = len > maxLength ? len : maxLength;
            }
        }

        return maxLength;
    }
};