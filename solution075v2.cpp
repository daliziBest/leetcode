//对v1解法进行了改进，加快了速度
//将swap()声明为inline可进一步加快速度

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int begin = 0;
        int end = nums.size();
        int i;
        bool isfirst = true;
        while (begin < end) {
            if (nums.at(begin) == 0) {
                begin++;
            } else if (nums.at(begin) == 2) {
                swap(nums, begin, --end);
            } else {
                if (isfirst) {
                    i = begin + 1;
                    isfirst = false;
                } else {
                    i++;
                }
                while (i < end) {
                    if (nums.at(i) == 1) {
                        i++;
                    } else {
                        swap(nums, begin, i);
                        break;
                    }
                }
                if (i >= end) {
                    return;
                }
            }
        }
    }

private:
    inline void swap(vector<int>& nums, int i, int j) {
        int temp = nums.at(i);
        nums.at(i) = nums.at(j);
        nums.at(j) = temp;
    }
};