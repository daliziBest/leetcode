//a O(n) algorithm using linear extra space is easy
//a one-pass algorithm using only constant extra space

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int begin = 0;
        int end = nums.size();
        while (begin < end) {
            if (nums.at(begin) == 0) {
                begin++;
            } else if (nums.at(begin) == 2) {
                swap(nums, begin, --end);
            } else {
                int i = begin + 1;
                while (i < end) {
                    if (nums.at(i) == 1) {
                        i++;
                    } else {
                        swap(nums, begin, i);
                        break;
                    }
                }
                if (i == end) {
                    return;
                }
            }
        }
    }

private:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums.at(i);
        nums.at(i) = nums.at(j);
        nums.at(j) = temp;
    }
};