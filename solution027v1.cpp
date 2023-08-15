//和026很像

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = 0;
        while (i < nums.size()) {
            if (nums.at(i) == val) {
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