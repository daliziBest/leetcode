//https://fizzbuzzed.com/top-interview-questions-1/
//对hashmap的改进
//将sum3转化为sum2问题后，不使用hashmap在线性时间解决sum2问题
//可以做到，因为此时sum2的数组已经排好序
//即对于一个已排序数组，找出所有的不重复组合{x,y}，使得x+y=-T
//和leetcode011思路很像
//时间复杂度O(n2)
/**
为了减少代码重复编写，编写函数moveback，moveForward。但该函数位于循环体内，可能由于频繁调用产生额外开销。
然后为了减少函数调用开销，使用inline。但是inline只是对编译器提出一个申请，并不是强制命令。编译器可以某些忽略内联请求。
最后放弃将重复代码编写成函数
**/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        //core code
        for (int i = 0; i < nums.size(); ) {
            int j = i + 1;
            int k = nums.size() - 1;
            const int T = 0 - nums.at(i);
            while (j < k) {
                if (nums.at(j) + nums.at(k) == T) {
                    result.push_back({nums.at(i), nums.at(j), nums.at(k)});
                    //moveForward(nums, j);
                    do {
                        j++;
                    } while (j < nums.size() && nums.at(j) == nums.at(j - 1));
                    //moveBack(nums, k);
                    do {
                        k--;
                    } while (k >= 0 && nums.at(k) == nums.at(k + 1));
                } else if (nums.at(j) + nums.at(k) > T) {
                    //moveBack(nums, k);
                    do {
                        k--;
                    } while (k >= 0 && nums.at(k) == nums.at(k + 1));
                } else {
                    //moveForward(nums, j);
                    do {
                        j++;
                    } while (j < nums.size() && nums.at(j) == nums.at(j - 1));
                }
            }
            
            //moveForward(nums, i);
            do {
                i++;
            } while (i < nums.size() && nums.at(i) == nums.at(i - 1));
        }

        return result;
    }
/**
private:
    inline void moveBack(vector<int>& nums, int& index) {
        do {
            index--;
        } while (index >= 0 && nums.at(index) == nums.at(index + 1));
    }
    inline void moveForward(vector<int>& nums, int& index) {
        do {
            index++;
        } while (index < nums.size() && nums.at(index) == nums.at(index - 1));
    }
**/
};