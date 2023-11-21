//关键在于能不能想到移位和翻转的关系
//移位=3次翻转
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (nums.size() == 1 || k == 0)
        {
            return;
        }
    
        //翻转整个数组
        myrotate(nums, 0, nums.size() - 1);
        //翻转前部
        myrotate(nums, 0, k - 1);
        //翻转后部
        myrotate(nums, k, nums.size() - 1);
    }

    void myrotate(vector<int>& nums, int i, int j) {
        while (i < j)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
        return;
    }
};

