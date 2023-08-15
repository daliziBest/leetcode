//先在[1,end]寻找，如果找到ok，找不到说明没有rotate，返回nums[0]

class Solution {
public:
    int findMin(vector<int>& nums) {
        //没有发生rotate
        // if (nums.front() < nums.back()) {
        //     return nums.front();
        // }

        int start = 1;
        int end = nums.size() - 1;
        int mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (nums[mid] < nums[mid - 1]) {
                return nums[mid];
            } else if (nums[mid] > nums.back()) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return nums.front();
    }
};