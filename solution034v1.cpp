//binary search
//O(logn)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //range is [i,j]
        int i = -1;
        int j = -1;

        int begin;
        int end;
        int mid;

        //find the first index
        begin = 0;
        end = nums.size() -1;
        while (begin <= end) {
            mid = (begin + end) / 2;
            if (target < nums.at(mid)) {
                end = mid - 1; 
            } else if (target > nums.at(mid)) {
                begin = mid + 1;
            } else if (mid == 0 || nums.at(mid - 1) < nums.at(mid)) {
                //find the right first index
                i = mid;
                break;
            } else {
                end = mid - 1;
            }
        }

        if (i == -1) {
            return {i ,j};
        }

        //then find the second index
        begin = 0;
        end = nums.size() - 1;
        while (begin <= end) {
            mid = (begin + end) / 2;
            if (target < nums.at(mid)) {
                end = mid - 1; 
            } else if (target > nums.at(mid)) {
                begin = mid + 1;
            } else if (mid == nums.size() - 1 || nums.at(mid) < nums.at(mid + 1)) {
                //find the right second index
                j = mid;
                break;
            } else {
                begin = mid + 1;
            }
        }

        return {i, j};
    }
};