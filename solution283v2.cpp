//从后往前，依次把遇到的0移至末尾
//比较耗时O(N2)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = nums.size() - 1;
        int j = nums.size() - 1;
        while (i >= 0)
        {
            if (nums[i] != 0)
            {
                i--;
            }
            else
            {
                int k = i--;
                while (k < j)
                {
                    swap(nums, k, k + 1);
                    k++;
                }
                j--;
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