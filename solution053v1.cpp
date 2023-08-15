//从长度1出发，逐步得到maximum subarray
//每增加一个新元素，就会多出来一部分可选subArray，找到这部分subArray最大值，与未增加前最大值比较并更新

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxNow = nums.at(0);
        int maxfromRight = nums.at(0);
        
        //core code
        int addNew;
        for (int i = 1; i < nums.size(); i++) {
            addNew = nums.at(i);
            maxfromRight = (maxfromRight + addNew > addNew) ? maxfromRight + addNew : addNew;
            if (maxNow < maxfromRight) {
                maxNow = maxfromRight;
            }
        }
        
        return maxNow;
    }
};