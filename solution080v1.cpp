//和026类似

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int placeLoc = 1;
        int seeLoc = 1;
        int count = 1;
        int sumNum = 1;

        while (seeLoc < nums.size()) {
            if (nums.at(seeLoc) == nums.at(seeLoc - 1)) {
                if (++count <= 2) {
                    nums.at(placeLoc++) = nums.at(seeLoc++);
                    sumNum++;
                } else {
                    seeLoc++;
                }
            } else {
                nums.at(placeLoc++) = nums.at(seeLoc++);
                sumNum++;
                count = 1;
            }
        }

        return sumNum;
    }
};