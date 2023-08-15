//从右向左依次检查跳跃范围
//假设i能到达last,那么继续在后面的元素中检查是否能到达i
//此时，能到达i和能到达last等价

class Solution {
public:
    bool canJump(vector<int>& nums) {
        //corner case
        if (nums.size() == 1) {
            return true;
        }

        //core code
        int togo = nums.size() - 1;
        int i = nums.size() - 2;
        while (i >= 0) {
            if (nums.at(i) + i >= togo) {
                if (i == 0) {
                    return true;
                } else {
                    togo = i;
                    i--;
                    continue;
                }
            } else {
                i--;
            }
        }
        return false;
    }
};