//binary search
//if a1,a2,a3....an-1,an, 其中a1<a2 && an-1>an, 那么a2...an-1中必有peak element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        while (true) {
            mid = (start + end) / 2;
            if (mid == nums.size() - 1 || (mid == 0 && nums[0] > nums[1]) || (mid != 0 && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])) {
                return mid;
            } else if (mid == 0) {
                return 1;
            } else if (nums[mid - 1] < nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
};