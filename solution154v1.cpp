//类似081题

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.front() < nums.back()) {
            return nums.front();
        }

        int border = -1;
        if (nums.front() == nums.back()) {
            int i;
            for (i = 0; i < nums.size(); i++) {
                if (nums[i] != nums.front()) {
                    break;
                }
            }
            if (i == nums.size()) {
                return nums.front();
            } else {
                border = i - 1;
            }
        }

        //此时min一定在[1,end]里
        int start = 1;
        int end = nums.size() - 1;
        int mid;
        while (true) {
            mid = (start + end) / 2;
            if (nums[mid] < nums[mid - 1]) {
                return nums[mid];
            } else if (nums[mid] < nums.back()) {
                end = mid - 1;
            } else if (nums[mid] > nums.back()) {
                start = mid + 1;
            } else if (mid <= border) {
                start = border + 1;
            } else {
                end = mid - 1;
            }
        }
    }
};