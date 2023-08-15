//假设我们可以使用额外空间，想想是怎么做的
//下面有一个额外数组，同时有一个j指示现在待插的位置
//O(n)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 0;
        i++;
        j++;
        while (i < nums.size()) {
            if (nums.at(i) == nums.at(i - 1)) {
                i++;
            } else {
                nums.at(j) = nums.at(i);
                i++;
                j++;
            }
        }

        return j;
    }
};