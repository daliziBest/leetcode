//想象一滩水，由全0构成，向右移动，交换扩大
//有难度

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        while (i < nums.size() && nums[i] != 0){
            i++;
        }
        //数组中无0
        if (i == nums.size())
            return;

        j = i + 1;
        while (j < nums.size() && nums[j] == 0)
        {
            j++;
        }
        
        while (j < nums.size()){
            if (nums[j] != 0)
            {
                swap(nums, i++, j++);
            }
            else
            {
                j++;
            }
        }

        return;
    }
private:
    inline void swap(vector<int>& nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return;
    }
};