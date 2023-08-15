//033变种
//md这题烦死了

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //先判断是否发生了rotate，并为后面相等的情况得到一些辅助判断条件
        int range;
        if (nums.at(0) < nums.back()) {
            return binaryFind(nums, 0, nums.size() - 1, target);
        } else if (nums.at(0) == nums.back()) {
            range = 1;
            while (range < nums.size()) {
                if (nums.at(range) == nums.at(0)) {
                    range++;
                } else {
                    break;
                }
            }
            if (range >= nums.size()) {
                return nums.at(0) == target;
            }
        }

        //肯定发生了rotate, 且此时nums[pivot-1]>nums[pivot]
        //find pivot
        int mid;
        int begin = 1;
        int end = nums.size() - 1;
        while (begin <= end) {
            mid = (begin + end) / 2;
            if (nums.at(mid - 1) > nums.at(mid)) {
                break;
            } else if (nums.at(mid - 1) < nums.at(mid)) {
                if (nums.at(mid) <= nums.back()) {
                    end = mid - 1;
                } else {
                    begin = mid + 1;
                }
            } else {
                if (nums.at(mid) < nums.back()) {
                    end = mid - 1;
                } else if (nums.at(mid) > nums.back()) {
                    begin = mid + 1;
                } else if (nums.at(mid) < nums.front()) {
                    end = mid - 1;
                } else if (mid <= range) {
                    //begin = mid + 1;
                    begin = range + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        //then find target
        if (nums.back() == target) {
            return true;
        } else if (target < nums.back()) {
            return binaryFind(nums, mid, nums.size() - 2, target);
        } else {
            return binaryFind(nums, 0, mid - 1, target);
        }
    }

private:
    bool binaryFind(vector<int>& nums, int begin, int end, int target) {
        int mid;
        while (begin <= end) {
            mid = (begin + end) / 2;
            if (nums.at(mid) == target) {
                return true;
            } else if (nums.at(mid) < target) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return false;
    }
};