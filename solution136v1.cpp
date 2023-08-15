//位运算小窍门
//a^a=0  0^a=a

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (auto a : nums) {
            result = result ^ a;
        }
        return result;
    }
};