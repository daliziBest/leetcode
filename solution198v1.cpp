//动态规划
//i->i+1，多了必须包括i+1的组合

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> max_in_i;
        max_in_i.push_back(nums[0]);
        if (nums.size() == 1)
        {
            return max_in_i.back();
        }
        int temp = nums[1] > max_in_i[0] ? nums[1] : max_in_i[0];
        max_in_i.push_back(temp);
        int i = 2;
        while (i < nums.size())
        {
            //计算最多考虑偷到第i个房屋，一夜之内能够偷窃到的最高金额
            temp = nums[i] + max_in_i[i - 2];
            if (temp < max_in_i[i - 1])
            {
                temp = max_in_i[i - 1];
            }
            max_in_i.push_back(temp);
            i++;
        }
        return max_in_i.back();
    }
};