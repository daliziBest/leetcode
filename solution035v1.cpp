//binary search
//O(logn)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int result = -1;
        
        int begin = 0;
        int end = nums.size() - 1;
        int mid;
        while (begin <= end) {
            mid = (begin + end) / 2;
            if (target < nums.at(mid)) {
                end = mid - 1;
            } else if (target > nums.at(mid)) {
                begin = mid + 1;
            } else {
                result = mid;
                break;
            }
        }

        //if not find
        if (result == -1) {
            result = begin;
        }

        return result;

    }
};