//Moore’s Voting Algorithm : https://www.geeksforgeeks.org/boyer-moore-majority-voting-algorithm/
//对上述方法进行了一点修改，更易理解
//每个元素都在给自己投票，想办法把自己投成candidate

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == candidate) {
                count++;
            } else if (--count >= 0) {
                
            } else {
                candidate = nums[i];
                count = 1;
            }
        }

        return candidate;
    }
};