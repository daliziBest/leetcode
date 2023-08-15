//1,2,3,4......

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //core code
        //place in-range elements on its right location
        //1 must is in nums[0], 2 must is in nums[1], 3 must is in nums[2].......
        for (int i = 0; i < nums.size(); ) {
            if (nums.at(i) >= 1 && nums.at(i) <= nums.size()) {
                int num = nums.at(i);
                //num should be in nums[num - 1]
                if (nums.at(num - 1) == num) {
                    i++;
                    continue;
                } else {
                    //swap
                    int temp = nums.at(num - 1);
                    nums.at(num - 1) = num;
                    nums.at(i) = temp;
                    continue;
                }
            }
            i++;
        }


        //check
        for (int j = 0; j < nums.size(); j++) {
            if (nums.at(j) != j + 1) {
                return j + 1;
            }
        }
        return nums.size() + 1;
    }
};