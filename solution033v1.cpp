//关键在于找到pivot
//O(logn)


class Solution {
public:
    int search(vector<int>& nums, int target) {
        //用于后面所有的binary search
        int begin;
        int end;
        int mid;

        //检查是否发生rotation
        //如果没有发生rotation
        if (nums.at(0) <= nums.at(nums.size() - 1)) {
            //binary search
            begin = 0;
            end = nums.size() - 1;
            while (begin <= end) {
                mid = (begin + end) / 2;
                if (nums.at(mid) < target) {
                    begin = mid + 1;
                } else if (nums.at(mid) > target) {
                    end = mid - 1;
                } else {
                    return mid;
                }
            }
            return -1;
        }

        //find pivot(或者切分线)
        begin = 0;
        end = nums.size() - 2;
        int pivot;
        while (true) {
            pivot = (begin + end) / 2;
            if (nums.at(pivot) > nums.at(pivot + 1)) {
                break;
            } else if (nums.at(pivot) < nums.at(nums.size() - 1)) {
                end = pivot - 1;
            } else {
                begin = pivot + 1;
            }
        }

        //find target
        //determine search range, then binary search
        if (target < nums.at(0)) {
            begin = pivot + 1;
            end = nums.size() - 1;
        } else {
            begin = 0;
            end = pivot;
        }
        while (begin <= end) {
            mid = (begin + end) / 2;
            if (nums.at(mid) < target) {
                begin = mid + 1;
            } else if (nums.at(mid) > target) {
                end = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;

    }

};